#include <iostream>

#include "Item.hpp"
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

	out("");

	for (Item item: room.getInventory().getItems()) {
		out("There is " + item.getShortDescription() + ".");
	}
}

int main() {
	std::cout << "Key" << std::endl;
	std::cout << "===============" << std::endl;

	Inventory playerInventory;

	Room room("Brown and gray stone brick walls surround you. You hear the trickle of water in the distance. In front of you is a rusted iron door.", Inventory());
	std::vector<std::string> shortNames;
	shortNames.push_back("key");
	shortNames.push_back("golden key");
	shortNames.push_back("small key");
	shortNames.push_back("little key");
	shortNames.push_back("bright key");
	Item key("key", "a bright, golden key", shortNames);
	room.getInventory().addItem(key);

	look(room);

	bool keyTaken   = false;
	bool doorLocked = true;
	bool win        = false;

	while (!win) {
		std::string input = prompt();

		if (input.compare("take key") == 0) {
			if (keyTaken) {
				out("You already have the key.");
			} else {
				keyTaken = true;
				room.getInventory().transferTo(playerInventory, "key");
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
