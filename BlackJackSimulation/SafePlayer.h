#pragma once
#include "Player.h"
class SafePlayer : public Player
{
public:
	SafePlayer();
	virtual ~SafePlayer();
	bool shouldStand() override;
};
