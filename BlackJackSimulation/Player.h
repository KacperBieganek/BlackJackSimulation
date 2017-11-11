#pragma once
#include <string>
#include <vector>
#include <stack>


class Player
{
private:
	int cardsValue;
	bool stands;
protected:
	std::vector<std::string> cardVector;
public: 
	virtual ~Player();
	std::string drawCard(std::stack<std::string>& deckOfCards);
	virtual bool shouldStand() = 0;
	bool getStands();
	void calculateCardsValue();
	void nextRound();
	int getCardValue();
};
