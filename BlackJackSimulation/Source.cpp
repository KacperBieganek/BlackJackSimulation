#include "SafePlayer.h"
#include <iostream>
#include <fstream>


bool fillDeck(std::string filePath, std::vector<std::string>& vec);

int main(int argc, char** argv)
{
	std::vector<std::string> vectorOfCards;
	std::vector<Player> players;
	try {
		if (argc < 2)
			throw - 1;
		else {
			if (!(fillDeck(argv[1], vectorOfCards)))
				throw - 2;
		}
	}
	catch (const int err) {
		switch (err)
		{
		case -1: std::cout << "Too little arguments, please include path to deck into starting arguments" << std::endl; break;
		case -2: std::cout << "Failed to load the deck" << std::endl; break;
		}
		return -1;
	}

	for (size_t i = 0; i < vectorOfCards.size(); i++)
		std::cout << vectorOfCards.at(i) << std::endl;
	return 0;
}


bool fillDeck(std::string filePath, std::vector<std::string>& vec) {
	std::ifstream file(filePath, std::ios::in);
	if (file.is_open()) {
		std::string allCards = "";
		std::getline(file, allCards);
		std::string delimiter = ";";
		size_t pos = 0;
		while ((pos = allCards.find(delimiter)) != std::string::npos) {
			vec.push_back(allCards.substr(0, allCards.find(delimiter)));
			allCards.erase(0, allCards.find(delimiter) + delimiter.length());
		}
	}
	else
		return false;

	return true;
}