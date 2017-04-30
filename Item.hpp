#ifndef ITEM_HPP
#define ITEM_HPP

#include <vector>

class Item {
private:
	std::string shortDescription;
	std::string longDescription;
	std::vector<std::string> shortNames();

public:
	std::string getShortDescription();
	std::string getLongDescription();
	std::vector<std::string> getShortNames();
};

#endif//ITEM_HPP
