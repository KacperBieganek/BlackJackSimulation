#include "CustomPlayer.h"



CustomPlayer::CustomPlayer(std::string playerName) : Player(playerName)
{
}


CustomPlayer::~CustomPlayer()
{
}

void CustomPlayer::shouldStand()
{
	stands = false;
}
