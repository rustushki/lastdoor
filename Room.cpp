#include "Room.hpp"

Room::Room(std::string description) {
	this->description = description;
}

std::string Room::getDescription() {
	return description;
}
