#include "social.hpp"
#include <iostream>

using namespace std::string_literals;

int main() {
	profile p1("marco"s, "Marco"s);
	std::cout << p1.username() << '\n';  // marco
	std::cout << p1.full_name() << '\n'; // Marco (@marco)

	p1.display_name("Marco Rossi"s);
	std::cout << p1.username() << '\n';  // marco
	std::cout << p1.full_name() << '\n'; // Marco Rossi (@marco)

	profile p2("tarma1"s, "Tarma Roving"s);
	std::cout << p2.username() << '\n';  // tarma1
	std::cout << p2.full_name() << '\n'; // Tarma Roving (@tarma1)
}
