#include <iostream>

#include "Room.hpp"

void out(std::string output) {
	std::cout << output << std::endl;
}

std::string prompt() {
	std::string input;
	std::cout << "> ";
	std::getline(std::cin, input);
	return input;
}

void look(Room room) {
	out(room.getDescription());
}

int main() {
	std::cout << "Key" << std::endl;
	std::cout << "===============" << std::endl;

	Room room("Brown and gray stone brick walls surround you. You hear the trickle of water in the distance. In front of you is a rusted iron door.");

	look(room);

	bool keyTaken   = false;
	bool doorLocked = true;
	bool win        = false;

	while (!win && exit) {
		std::string input = prompt();

		if (input.compare("take key") == 0) {
			if (keyTaken) {
				out("You already have the key.");
			} else {
				keyTaken = true;
				out("Taken.");
			}

		} else if (input.compare("unlock door") == 0) {
			if (!doorLocked) {
				out("The door is already unlocked.");
			} else if (!keyTaken) {
				out("You don't have the key.");
			} else {
				doorLocked = false;
				out("Unlocked.");
			}

		} else if (input.compare("open door") == 0) {
			if (!doorLocked) {
				win = true;
				out("Door opened, you win!");
			} else {
				out("The door is locked.");
			}

		} else if (input.compare("look") == 0) {
			look(room);

		} else if (input.compare("exit") == 0) {
			break;

		} else {
			std:out("Command not recognized.");
		}
	}

	return 0;
}