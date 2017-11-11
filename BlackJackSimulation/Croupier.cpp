#include "Croupier.h"



Croupier::Croupier(std::string playerName) : Player(playerName)
{
}


Croupier::~Croupier()
{
}

void Croupier::shouldStand()
{
	if (cardsValue >= 17)
		stands= true;
	else
		stands = false;
}
