#include "social.hpp"
#include <iostream>

int main() {
	network nw;
	std::cout << nw.add_user(profile{"mario", "Mario"}) << '\n'; // true (1)
	std::cout << nw.add_user(profile{"luigi", "Luigi"}) << '\n'; // true (1)

	std::cout << nw.add_user(profile{"mario", "Mario2"}) << '\n';   // false (0)
	std::cout << nw.add_user(profile{"mario 2", "Mario2"}) << '\n'; // false (0)
	std::cout << nw.add_user(profile{"mario-2", "Mario2"}) << '\n'; // false (0)

	for (std::size_t i = 2; i < 50; i++) {
		std::cout << nw.add_user(profile{"mario" + std::to_string(i), "Mario" + std::to_string(i)}) << '\n'; // true (1)
	}

	std::cout << nw.add_user(profile{"yoshi", "Yoshi"}) << '\n'; // false (0)
}
