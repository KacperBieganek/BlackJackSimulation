#pragma once
#include <string>
#include <vector>
#include <stack>
#include <iostream>


class Player
{
private:
	int cardsValue;
	void calculateCardsValue();
protected:
	bool stands;
	std::vector<std::string> cardVector;
public: 
	const std::string playerName;
	Player(std::string playerName):playerName(playerName) { cardsValue = 0;  stands = false;}
	virtual ~Player();
	std::string drawCard(std::stack<std::string>& deckOfCards);
	virtual void shouldStand() = 0;
	bool getStands();
	void nextRound();
	int getCardValue();
	void printRoundInfo();
};
