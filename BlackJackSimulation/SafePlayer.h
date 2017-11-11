#pragma once
#include "Player.h"
class SafePlayer : public Player
{
public:
	SafePlayer(std::string playerName);
	virtual ~SafePlayer();
	void shouldStand() override;
};
