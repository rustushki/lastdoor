#include "Room.hpp"

Room::Room(std::string description, Inventory inventory) {
	this->description = description;
	this->inventory = inventory;
}

std::string Room::getDescription() {
	return description;
}

Inventory& Room::getInventory() {
	return inventory;
}
