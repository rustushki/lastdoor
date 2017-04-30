#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <vector>

#include "Item.hpp"

class Inventory {
private:
	std::vector<Item> items;

public:
	Inventory();
	std::vector<Item>& getItems();
	void addItem(Item item);
	void transferTo(Inventory& inventory, std::string shortName);
};

#endif//INVENTORY_HPP
