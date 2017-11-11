#pragma once
#include <memory>
#include "Player.h"
#include <stack>
class GameUtility
{
private:
	GameUtility();
	~GameUtility();
	bool static playRound(std::shared_ptr<Player> player, std::shared_ptr<Player> croupier, std::stack<std::string>& deck);
public:
	void static playGame(std::shared_ptr<Player> player, std::shared_ptr<Player> croupier, std::stack<std::string> deck);
};

