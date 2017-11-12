#include "CustomPlayer.h"



CustomPlayer::CustomPlayer(std::string playerName) : Player(playerName)
{
}


CustomPlayer::~CustomPlayer()
{
}

void CustomPlayer::shouldStand()
{
	if (hasAce) {
		if (cardsValue <= 17)
			stands = false;
		else if (cardsValue == 18 && (dealersCardValue == 9 || dealersCardValue == 10))
			stands = false;
		else
			stands = true;
  }
	else
	{
		if (cardsValue <= 11)
			stands = false;
		else if (cardsValue == 12 && (dealersCardValue == 2 || dealersCardValue == 3))
			stands = false;
		else if ((cardsValue > 11 && cardsValue < 17) && (dealersCardValue > 6 && dealersCardValue < 12))
			stands = false;
		else
			stands = true;

	}
}

void CustomPlayer::rememberDealersCardValue(std::string card)
{
	if (card == "2")
		dealersCardValue = 2;
	else if (card == "3")
		dealersCardValue = 3;
	else if (card == "4")
		dealersCardValue = 4;
	else if (card == "5")
		dealersCardValue = 5;
	else if (card == "6")
		dealersCardValue = 6;
	else if (card == "7")
		dealersCardValue = 7;
	else if (card == "8")
		dealersCardValue = 8;
	else if (card == "9")
		dealersCardValue = 9;
	else if (card == "10")
		dealersCardValue = 10;
	else if (card == "J")
		dealersCardValue = 10;
	else if (card == "Q")
		dealersCardValue = 10;
	else if (card == "K")
		dealersCardValue = 10;
	else
		dealersCardValue = 11;
}

void CustomPlayer::nextRound()
{
	stands = false;
	cardsValue = 0;
	cardVector.clear();
	dealersCardValue = 0;
	hasAce = false;
}
