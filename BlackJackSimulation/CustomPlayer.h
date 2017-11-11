#pragma once
#include "Player.h"
class CustomPlayer :
	public Player
{
public:
	CustomPlayer();
	virtual ~CustomPlayer();
	bool shouldStand() override;
};

