#include "social.hpp"
// ReSharper disable once CppUnusedIncludeDirective
#include <iostream>

std::size_t network::id(std::string const& username) {
	auto const iterator = std::find_if(std::begin(profiles_), std::end(profiles_),
	                                   [&username](profile const& p) { return username == p.username(); });

	if (iterator == std::end(profiles_)) {
		return trap_value;
	}

	return std::distance(std::begin(profiles_), iterator);
}

bool network::add_user(profile new_user) {
	auto const alpha_numeric = new_user.username_is_alphanumeric();

	if (!alpha_numeric) {
		return false;
	}

	auto username = new_user.username();

	auto const found_duplicate = std::find_if(std::begin(profiles_), std::end(profiles_),
	                                          [&username](profile const& p) { return username == p.username(); })
	                             != profiles_.end();

	if (found_duplicate) {
		return false;
	}

	profiles_.emplace_back(std::move(new_user));
	following_.emplace_back();

	return true;
}

bool network::follow(std::string const& usrn1, std::string const& usrn2) {
	auto const id_a = id(usrn1);
	auto const id_b = id(usrn2);

	if (id_a == trap_value || id_b == trap_value) {
		return false;
	}

	auto& id_a_following = following_[id_a];
	if (std::find(std::begin(id_a_following), std::end(id_a_following), id_b) != std::end(id_a_following)) {
		return true;
	}
	id_a_following.emplace_back(id_b);

	return true;
}

void network::print_dot(std::ostream& os) {
	os << "digraph {\n";
	for (auto&& profile : profiles_) {
		os << "\t\"@"s << profile.username() << "\"\n";
	}
	os << '\n';

	for (std::size_t i = 0; i < profiles_.size(); ++i) {
		auto&& profile = profiles_[i];
		auto&& followees = following_[i];
		for (auto&& edge : followees) {
			os << "\t\"@"s << profile.username() << "\"s -> \"@"s << profiles_[edge].username() << "\"\n";
		}
	}
	os << "s}\n";
}

bool network::write_post(std::string const& usrn, std::string msg) {
	auto const ident = id(usrn);

	if (ident == trap_value) {
		return false;
	}

	posts_.emplace_back(std::make_pair(ident, std::move(msg)));

	return true;
}

bool network::print_timeline(std::ostream& os, std::string const& usrn) {
	auto const ident = id(usrn);

	if (ident == trap_value) {
		return false;
	}

	for (auto&& post_pair : posts_) {
		auto&& post_id = post_pair.first;
		auto&& post_text = post_pair.second;

		if (post_id != ident
		    && std::find(std::begin(following_[ident]), std::end(following_[ident]), post_id)
		           == std::end(following_[ident])) {
			continue;
		}

		os << profiles_[post_id].full_name() << ". "s << post_text << '\n';
	}

	return true;
}
