#pragma once
#include <memory>
#include "CustomPlayer.h"
#include <stack>
class GameUtility
{
private:
	GameUtility();
	~GameUtility();
	bool static playRound(std::shared_ptr<Player> player, std::shared_ptr<Player> croupier, std::stack<std::string>& deck);
	bool static playRound(std::shared_ptr<CustomPlayer> player, std::shared_ptr<Player> croupier, std::stack<std::string>& deck);
public:
	void static playGame(std::shared_ptr<Player> player, std::shared_ptr<Player> croupier, std::stack<std::string> deck);
	void static playGame(std::shared_ptr<CustomPlayer> player, std::shared_ptr<Player> croupier, std::stack<std::string> deck);
};

