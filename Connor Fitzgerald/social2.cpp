#include "social.hpp"
#include <iostream>

int main() {
	network nw;
	std::cout << nw.add_user(profile{"mario"s, "Mario"s}) << '\n'; // true (1)
	std::cout << nw.add_user(profile{"luigi"s, "Luigi"s}) << '\n'; // true (1)

	std::cout << nw.add_user(profile{"mario"s, "Mario2"s}) << '\n';   // false (0)
	std::cout << nw.add_user(profile{"mario 2"s, "Mario2"s}) << '\n'; // false (0)
	std::cout << nw.add_user(profile{"mario-2"s, "Mario2"s}) << '\n'; // false (0)

	for (std::size_t i = 2; i < 50; i++) {
		std::cout << nw.add_user(profile{"mario"s + std::to_string(i), "Mario"s + std::to_string(i)}) << '\n'; // true (1)
	}

	std::cout << nw.add_user(profile{"yoshi"s, "Yoshi"s}) << '\n'; // false (0)
}
