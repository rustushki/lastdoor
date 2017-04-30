#ifndef ROOM_HPP
#define ROOM_HPP

#include <string>
#include <vector>

#include "Inventory.hpp"

class Room {
private:
	std::string description;
	Inventory inventory;

public:
	Room(std::string description, Inventory inventory);
	std::string getDescription();
	Inventory& getInventory();
};

#endif//ROOM_HPP
