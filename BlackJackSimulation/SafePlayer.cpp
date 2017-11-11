#include "SafePlayer.h"



SafePlayer::SafePlayer(std::string playerName) :Player(playerName)
{
}


SafePlayer::~SafePlayer()
{
}

void SafePlayer::shouldStand()
{
	if (getCardValue() >= 12)
		stands = true;
	else
		stands = false;
}
