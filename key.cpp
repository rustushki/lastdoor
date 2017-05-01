#include <iostream>

#include "Item.hpp"
#include "Room.hpp"

void out(std::string output) {
	std::cout << output << std::endl;
}

void prompt() {
	std::cout << "> ";
}

void look(Room room) {
	out(room.getDescription());

	if (room.getInventory().getItems().size() > 0) {
		out("");

		for (Item item: room.getInventory().getItems()) {
			out("There is " + item.getLongDescription() + ".");
		}
	}
}

std::string token() {
	std::string token;
	std::cin >> token;
	return token;
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

	bool doorLocked = true;
	bool win        = false;

	while (!win) {
		prompt();

		std::string verb = token();

		if (verb.compare("take") == 0) {
			std::string directObject = token();
			if (room.getInventory().contains(directObject)) {
				room.getInventory().transferTo(playerInventory, directObject);
				out("Taken.");
			} else if (playerInventory.contains(directObject)) {
				out("You already have the " + directObject + ".");
			} else {
				out("You don't see the " + directObject + ".");
			}

		} else if (verb.compare("look") == 0) {
			look(room);

		} else if (verb.compare("exit") == 0) {
			break;

		} else if (verb.compare("unlock") == 0) {
			std::string directObject = token();

			if (directObject.compare("door") == 0) {
				if (!doorLocked) {
					out("The door is already unlocked.");
				} else if (!playerInventory.contains("key")) {
					out("You don't have the key.");
				} else {
					doorLocked = false;
					out("Unlocked.");
				}
			} else {
				out("You can't unlock the " + directObject + ".");
			}


		} else if (verb.compare("open") == 0) {
			std::string directObject = token();

			if (directObject.compare("door") == 0) {
				if (!doorLocked) {
					win = true;
					out("Door opened, you win!");
				} else {
					out("The door is locked.");
				}

			} else {
				out("You can't open the " + directObject + ".");
			}

		
		} else {
			out("Command not recognized.");
		}

		out("");
	}

	return 0;
}
