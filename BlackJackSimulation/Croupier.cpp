#include "Croupier.h"



Croupier::Croupier()
{
}


Croupier::~Croupier()
{
}

bool Croupier::shouldStand()
{
	if (getCardValue() >= 17)
		return true;
	else
	return false;
}
