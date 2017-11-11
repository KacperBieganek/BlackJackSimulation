#pragma once
#include <memory>
#include "CustomPlayer.h"
#include <fstream>
#include <stack>
class GameUtility
{
private:
	bool static playRound(std::shared_ptr<Player> player, std::shared_ptr<Player> croupier, std::stack<std::string>& deck);
	bool static playRound(std::shared_ptr<CustomPlayer> player, std::shared_ptr<Player> croupier, std::stack<std::string>& deck);
public:
	bool static fillDeck(std::string filePath, std::stack<std::string>& vec);
	void static playGame(std::shared_ptr<Player> player, std::shared_ptr<Player> croupier, std::stack<std::string> deck);
	void static playGame(std::shared_ptr<CustomPlayer> player, std::shared_ptr<Player> croupier, std::stack<std::string> deck);
};

