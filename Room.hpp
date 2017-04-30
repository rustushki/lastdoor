#ifndef ROOM_HPP
#define ROOM_HPP

#include <string>
#include <vector>

#include "Item.hpp"

class Room {
private:
	std::string description;
	std::vector<Item> items;

public:
	Room(std::string description);
	std::string getDescription();
	std::vector<Item> getItems();
	void addItem(Item item);
};

#endif//ROOM_HPP
