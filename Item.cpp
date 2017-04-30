#include "Item.hpp"
Item::Item(std::string shortDescription, std::string longDescription, std::vector<std::string> shortNames) {
	this->shortDescription = shortDescription;
	this->longDescription = longDescription;
	this->shortNames = shortNames;
}

std::string Item::getShortDescription() {
	return shortDescription;
}

std::string Item::getLongDescription() {
	return longDescription;
}

std::vector<std::string> Item::getShortNames() {
	return shortNames;
}

bool Item::isShortNamed(std::string possibleShortName) {
	for (auto shortName : getShortNames()) {
		if (shortName.compare(possibleShortName) == 0) {
			return true;
		}
	}

	return false;
}
