#include "Player.h"

Player::~Player()
{
	cardVector.clear();
}

std::string Player::drawCard(std::stack<std::string>& deckOfCards)
{
	std::string tmp = deckOfCards.top();
	deckOfCards.pop();
	cardVector.push_back(tmp);
	return tmp;
}

bool Player::getStands()
{
	return stands;
}

void Player::calculateCardsValue()
{
	cardsValue = 0;
	for (size_t i = 0; i < cardVector.size(); i++)
	{
		std::string tmp = cardVector.at(i);
		if (tmp == "2")
			cardsValue += 2;
		else if (tmp == "3")
			cardsValue += 3;
		else if (tmp == "4")
			cardsValue += 4;
		else if (tmp == "5")
			cardsValue += 5;
		else if (tmp == "6")
			cardsValue += 6;
		else if (tmp == "7")
			cardsValue += 7;
		else if (tmp == "8")
			cardsValue += 8;
		else if (tmp == "9")
			cardsValue += 9;
		else if (tmp == "10")
			cardsValue += 10;
		else if (tmp == "J")
			cardsValue += 10;
		else if (tmp == "Q")
			cardsValue += 10;
		else if (tmp == "K")
			cardsValue += 10;
		else
		{
			if (cardsValue > 11)
				cardsValue += 1;
			else
				cardsValue += 11;
		}
	}
}

void Player::nextRound()
{
	stands= false;
	cardsValue = 0;
	cardVector.clear();
}

int Player::getCardValue()
{
	return cardsValue;
}
