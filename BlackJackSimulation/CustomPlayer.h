#pragma once
#include "Player.h"
class CustomPlayer :
	public Player
{
private:
	size_t dealersCardValue;
public:
	CustomPlayer(std::string playerName);
	virtual ~CustomPlayer();
	void shouldStand() override;
	void rememberDealersCardValue(std::string card);
	void nextRound() override;
};

