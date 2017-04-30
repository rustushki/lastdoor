#include "Room.hpp"

Room::Room(std::string description) {
	this->description = description;
}

std::string Room::getDescription() {
	return description;
}

std::vector<Item> Room::getItems() {
	return items;
}

void Room::addItem(Item item) {
	items.push_back(item);
}
