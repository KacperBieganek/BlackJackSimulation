#include "SafePlayer.h"



SafePlayer::SafePlayer()
{
}


SafePlayer::~SafePlayer()
{
}

bool SafePlayer::shouldStand()
{
	if (getCardValue() > 12)
		return true;
	else
	return false;
}
