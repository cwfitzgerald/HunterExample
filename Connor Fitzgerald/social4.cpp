#include "social.hpp"
#include <iostream>

int main() {
	network nw;
	// add three users
	nw.add_user(profile{"mario"s, "Mario"s});
	nw.add_user(profile{"luigi"s, "Luigi"s});
	nw.add_user(profile{"yoshi"s, "Yoshi"s});

	nw.follow("mario"s, "luigi"s);
	nw.follow("luigi"s, "mario"s);
	nw.follow("luigi"s, "yoshi"s);
	nw.follow("yoshi"s, "mario"s);

	// write some posts
	nw.write_post("mario"s, "It's a-me, Mario!"s);
	nw.write_post("luigi"s, "Hey hey!"s);
	nw.write_post("mario"s, "Hi Luigi!"s);
	nw.write_post("yoshi"s, "Test 1"s);
	nw.write_post("yoshi"s, "Test 2"s);
	nw.write_post("luigi"s, "I just hope this crazy plan of yours works!"s);
	nw.write_post("mario"s, "My crazy plans always work!"s);
	nw.write_post("yoshi"s, "Test 3"s);
	nw.write_post("yoshi"s, "Test 4"s);
	nw.write_post("yoshi"s, "Test 5"s);

	std::cout << '\n';
	std::cout << "======= Mario's timeline ======="s << '\n';
	nw.print_timeline(std::cout, "mario"s);
	std::cout << '\n';

	std::cout << "======= Yoshi's timeline ======="s << '\n';
	nw.print_timeline(std::cout, "yoshi"s);
	std::cout << '\n';
}
