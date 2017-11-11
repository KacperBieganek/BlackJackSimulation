#pragma once
#include "Player.h"
class Croupier :
	public Player
{
public:
	Croupier(std::string playerName);
	virtual ~Croupier();
	void shouldStand() override;
	
};

