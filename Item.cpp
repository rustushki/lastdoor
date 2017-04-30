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
