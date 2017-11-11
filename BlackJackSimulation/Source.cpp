#include "SafePlayer.h"
#include <iostream>
#include <fstream>
#include <Memory>
#include <stack>


bool fillDeck(std::string filePath, std::stack<std::string>& vec);

int main(int argc, char** argv)
{
	std::stack<std::string> stackOfCards;
	//std::vector<std::shared_ptr<Player>> players;
	std::shared_ptr<Player> cautionPlayer(new SafePlayer());
	try {
		if (argc < 2)
			throw - 1;
		else {
			if (fillDeck(argv[1], stackOfCards) && stackOfCards.size() == 52)
				std::cout << "Deck loaded correctly" << std::endl;
		}
	}
	catch (const int err) {
		switch (err)
		{
		case -1: std::cout << "Too few arguments, please include path to deck into starting arguments" << std::endl; break;
		case -2: std::cout << "Failed to load the deck (File open error)" << std::endl; break;
		}
		return err;
	}
	return 0;
}


bool fillDeck(std::string filePath, std::stack<std::string>& vec) {
		std::ifstream file(filePath, std::ios::in);
		if (file.is_open()) {
			std::string allCards = "";
			std::getline(file, allCards);
			std::string delimiter = ";";
			size_t pos = 0;
			while ((pos = allCards.find(delimiter)) != std::string::npos) {
				vec.push(allCards.substr(0, allCards.find(delimiter)));
				allCards.erase(0, allCards.find(delimiter) + delimiter.length());
			}
		}
		else
			throw -2;

	return true;
}