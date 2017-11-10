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
			throw "Too little arguments, please include path to deck into starting arguments";
		else {
			if (!(fillDeck(argv[1], vectorOfCards)))
				throw "Failed to load the deck";
		}
	}
	catch (std::string err) {
		std::cout << err << std::endl;
	}
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