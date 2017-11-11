#pragma once
#include <string>
#include <vector>
#include <stack>
#include <iostream>


class Player
{
private:
	void calculateCardsValue();
protected:
	bool hasAce;
	int cardsValue;
	bool stands;
	std::vector<std::string> cardVector;
public: 
	const std::string playerName;
	Player(std::string playerName) :playerName(playerName) { cardsValue = 0;  stands = false; hasAce = false; }
	virtual ~Player();
	std::string drawCard(std::stack<std::string>& deckOfCards);
	virtual void shouldStand() = 0;
	bool getStands();
	virtual void nextRound();
	int getCardsValue();
	void printRoundInfo();
};
