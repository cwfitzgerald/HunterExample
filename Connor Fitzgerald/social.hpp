#pragma once

#include <algorithm>
#include <cctype>
#include <string>
#include <vector>

class profile {
  private:
	std::string username_;
	std::string display_name_;

  public:
	profile() = default;
	profile(std::string usrn, std::string dspn) : username_{std::move(usrn)}, display_name_{std::move(dspn)} {}

	std::string username() const {
		return username_;
	}

	std::string display_name() const {
		return display_name_;
	}

	void username(std::string usrn) {
		username_ = std::move(usrn);
	}

	void display_name(std::string dspn) {
		display_name_ = std::move(dspn);
	}

	// Return name in the format: "displayname (@username)"
	std::string full_name() const {
		std::string res;
		res.reserve(display_name_.size() + username_.size() + 4);

		std::copy(std::begin(display_name_), std::end(display_name_), std::back_inserter(res));
		char const intermediate[] = " (@";
		std::copy(std::begin(intermediate), std::end(intermediate) - 1, std::back_inserter(res));
		std::copy(std::begin(username_), std::end(username_), std::back_inserter(res));
		res.push_back(')');

		return res;
	}

	bool username_is_alphanumeric() const {
		return std::all_of(std::begin(username_), std::end(username_),
		                   [](char const c) { return std::isalnum(c) != 0; })
		       && !username_.empty();
	}
};

class network {
  private:
	static constexpr auto trap_value = std::numeric_limits<std::size_t>::max();

	std::vector<profile> profiles_;
	std::vector<std::vector<std::size_t>> following_;
	std::vector<std::pair<std::size_t, std::string>> posts_;

	std::size_t id(std::string const& username);

  public:
	bool add_user(profile new_user);
	bool follow(std::string const& usrn1, std::string const& usrn2);
	void print_dot(std::ostream& os);
	bool write_post(std::string const& usrn, std::string msg);
	bool print_timeline(std::ostream& os, std::string const& usrn);
};
