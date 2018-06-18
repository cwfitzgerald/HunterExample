#include "social.hpp"
#include <iostream>

int main() {
	network nw;
	// add three users
	nw.add_user(profile{"mario"s, "Mario"s});
	nw.add_user(profile{"luigi"s, "Luigi"s});
	nw.add_user(profile{"yoshi"s, "Yoshi"s});

	// make them follow each other
	nw.follow("mario"s, "luigi"s);
	nw.follow("mario"s, "yoshi"s);
	nw.follow("luigi"s, "mario"s);
	nw.follow("luigi"s, "yoshi"s);
	nw.follow("yoshi"s, "mario"s);
	nw.follow("yoshi"s, "luigi"s);

	// add a user who does not follow others
	nw.add_user(profile{"wario"s, "Wario"s});

	// add clone users who follow @mario
	for (std::size_t i = 2; i < 6; i++) {
		auto const usrn = "mario"s + std::to_string(i);
		auto const dspn = "Mario "s + std::to_string(i);
		nw.add_user(profile{usrn, dspn});
		nw.follow(usrn, "mario"s);
	}
	// additionally, make @mario2 follow @luigi
	nw.follow("mario2"s, "luigi"s);

	nw.print_dot(std::cout);
}
