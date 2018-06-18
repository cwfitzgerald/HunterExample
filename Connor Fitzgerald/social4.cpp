#include "social.hpp"
#include <iostream>

int main() {
	network nw;
	// add three users
	nw.add_user(profile{"mario", "Mario"});
	nw.add_user(profile{"luigi", "Luigi"});
	nw.add_user(profile{"yoshi", "Yoshi"});

	nw.follow("mario", "luigi");
	nw.follow("luigi", "mario");
	nw.follow("luigi", "yoshi");
	nw.follow("yoshi", "mario");

	// write some posts
	nw.write_post("mario", "It's a-me, Mario!");
	nw.write_post("luigi", "Hey hey!");
	nw.write_post("mario", "Hi Luigi!");
	nw.write_post("yoshi", "Test 1");
	nw.write_post("yoshi", "Test 2");
	nw.write_post("luigi", "I just hope this crazy plan of yours works!");
	nw.write_post("mario", "My crazy plans always work!");
	nw.write_post("yoshi", "Test 3");
	nw.write_post("yoshi", "Test 4");
	nw.write_post("yoshi", "Test 5");

	std::cout << '\n';
	std::cout << "======= Mario's timeline =======" << '\n';
	nw.print_timeline(std::cout, "mario");
	std::cout << '\n';

	std::cout << "======= Yoshi's timeline =======" << '\n';
	nw.print_timeline(std::cout, "yoshi");
	std::cout << '\n';
}
