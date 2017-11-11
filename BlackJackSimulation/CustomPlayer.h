#pragma once
#include "Player.h"
class CustomPlayer :
	public Player
{
public:
	CustomPlayer(std::string playerName);
	virtual ~CustomPlayer();
	void shouldStand() override;
};

