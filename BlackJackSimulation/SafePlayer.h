#pragma once
#include "Player.h"
class SafePlayer : public Player
{
public:
	// konstruktor powinien wyglądać tak: explicit SafePlayer(const std::sting playerName) // nie kopiujemy stringa dwa razy
	SafePlayer(std::string playerName); // dodawaj w konstruktorach jedno argumentowych słowo kluczowe 'explcit', poczytaj dlaczego
	virtual ~SafePlayer();
	void shouldStand() override;
};
