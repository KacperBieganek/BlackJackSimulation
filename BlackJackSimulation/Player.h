#pragma once
#include <string>
#include <vector>
#include <stack>
#include <iostream>


class Player
{
private:
	void calculateCardsValue();
protected: // umieszczanie zmiennych w protected to zła praktyka, powinne byc one prywatne a modyfikowane funkcjami z protected lub public
	bool hasAce;
	int cardsValue;
	bool stands;
	std::vector<std::string> cardVector;
public: // sekcje public zazwyczaj daje się pierwszą, by jak ktoś wchodził najpierw czytał intefejs a nie zmienne prywatne
	const std::string playerName;
    // nie formatuj tak kodu, każda instrukcja w osobnej linijce w 99.9% przypadków
	Player(std::string playerName) :playerName(playerName) { cardsValue = 0;  stands = false; hasAce = false; }
	virtual ~Player();
	std::string drawCard(std::stack<std::string>& deckOfCards);
    // wykorzystanie polimorfizmu dynamicznego, o to chodziło tutaj plus
	virtual void shouldStand() = 0;
	bool getStands();
	virtual void nextRound();

    // gracz ma tylko grać, nie powinien być odpowiedzialny za tworzenie logiki gry
    // to gra ma obliczać jaka jest wartość kart
    // gracz oczywiście może sobie też liczyć, ale na swoje potrzeby, czyli sekcja protected lub private
	int getCardsValue();
	void printRoundInfo();
};
