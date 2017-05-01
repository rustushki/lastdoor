#include "Inventory.hpp"
#include "Item.hpp"

#include <iostream>

Inventory::Inventory() {
}

std::vector<Item>& Inventory::getItems() {
	return items;
}

void Inventory::addItem(Item item) {
	items.push_back(item);
}

void Inventory::transferTo(Inventory& inventory, std::string shortName) {
	for (auto item = getItems().begin(); item < getItems().end(); item++) {
		if (item->isShortNamed(shortName)) {
			inventory.addItem(*item);
			getItems().erase(item);
			break;
		}
	}
}

bool Inventory::contains(std::string possibleItem) {
	for (Item item : getItems()) {
		if (item.isShortNamed(possibleItem)) {
			return true;
		}
	}

	return false;
}
