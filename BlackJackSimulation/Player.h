#pragma once
#include <string>
#include <vector>


class Player
{
private:
	std::vector<std::string> cardVector;
	int cardsValue;
	bool stands;

public: 
	virtual ~Player();
	virtual std::string drawCard() = 0;
	virtual bool shouldStand() = 0;
	void calculateCardsValue();
	void nextRound();
	int getCardValue();
};
