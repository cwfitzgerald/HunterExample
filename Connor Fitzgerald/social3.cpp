#include "social.hpp"
#include <iostream>

int main() {
	network nw;
	// add three users
	nw.add_user(profile{"mario", "Mario"});
	nw.add_user(profile{"luigi", "Luigi"});
	nw.add_user(profile{"yoshi", "Yoshi"});

	// make them follow each other
	nw.follow("mario", "luigi");
	nw.follow("mario", "yoshi");
	nw.follow("luigi", "mario");
	nw.follow("luigi", "yoshi");
	nw.follow("yoshi", "mario");
	nw.follow("yoshi", "luigi");

	// add a user who does not follow others
	nw.add_user(profile{"wario", "Wario"});

	// add clone users who follow @mario
	for (std::size_t i = 2; i < 6; i++) {
		auto const usrn = "mario" + std::to_string(i);
		auto const dspn = "Mario " + std::to_string(i);
		nw.add_user(profile{usrn, dspn});
		nw.follow(usrn, "mario");
	}
	// additionally, make @mario2 follow @luigi
	nw.follow("mario2", "luigi");

	nw.print_dot(std::cout);
}
