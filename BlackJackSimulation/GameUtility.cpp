#include "GameUtility.h"



void GameUtility::playGame(std::shared_ptr<CustomPlayer> player, std::shared_ptr<Player> croupier, std::stack<std::string> deck)
{
	std::cout << "[Game started with player: " << player->playerName << "]" << std::endl;
	size_t playerScore = 0, croupierScore = 0;
	while (deck.size() >= 4) {
		player->nextRound();
		croupier->nextRound();
		if (playRound(player, croupier, deck))
		{
			std::cout << "[End round: Player win (" << ++playerScore << " : " << croupierScore << ")]" << std::endl;
		}
		else
		{
			std::cout << "[End round: Croupier win (" << playerScore << " : " << ++croupierScore << ")]" << std::endl;
		}

	}
	std::cout << "[Game over]" << std::endl;
}
void GameUtility::playGame(std::shared_ptr<Player> player, std::shared_ptr<Player> croupier, std::stack<std::string> deck)
{
	std::cout << "[Game started with player: " << player->playerName << "]" << std::endl;
	size_t playerScore=0, croupierScore=0;
	while (deck.size() >= 4) {
		player->nextRound();
		croupier->nextRound();
		if (playRound(player, croupier, deck))
		{
			std::cout << "[End round: Player win (" << ++playerScore << " : " << croupierScore << ")]" << std::endl;
		}
		else
		{
			std::cout << "[End round: Croupier win (" << playerScore << " : " << ++croupierScore << ")]" << std::endl;
		}

	}
	std::cout << "[Game over]" << std::endl;
}
bool GameUtility::playRound(std::shared_ptr<CustomPlayer> player, std::shared_ptr<Player> croupier, std::stack<std::string>& deck)
{
	player->drawCard(deck);
	player->rememberDealersCardValue(croupier->drawCard(deck));
	player->drawCard(deck);
	croupier->drawCard(deck);
	if (player->getCardsValue() == 21)
	{
		player->printRoundInfo();
		croupier->printRoundInfo();
		return true;
	}
	player->shouldStand();
	croupier->shouldStand();

	while (deck.size() > 0 && !(player->getStands() && croupier->getStands()))
	{
		if (player->getStands())
		{
			if (croupier->getCardsValue() > 21)
			{
				player->printRoundInfo();
				croupier->printRoundInfo();
				return false;
			}
			croupier->shouldStand();
			if (!croupier->getStands())
				croupier->drawCard(deck);
		}
		else
		{
			if (player->getCardsValue() > 21)
			{
				player->printRoundInfo();
				croupier->printRoundInfo();
				return false;
			}
			player->shouldStand();
			if (!player->getStands())
				player->drawCard(deck);
		}
	}
	player->printRoundInfo();
	croupier->printRoundInfo();
	return (player->getCardsValue() > croupier->getCardsValue()) ? true : false;

}
//Returns true when players win and false when croupier wins

bool GameUtility::playRound(std::shared_ptr<Player> player, std::shared_ptr<Player> croupier, std::stack<std::string>& deck)
{
	player->drawCard(deck);
	croupier->drawCard(deck);
	player->drawCard(deck);
	croupier->drawCard(deck);
	if (player->getCardsValue() == 21)
	{
		player->printRoundInfo();
		croupier->printRoundInfo();
		return true;
	}
	player->shouldStand();
	croupier->shouldStand();

	while (deck.size() > 0 && !(player->getStands() && croupier->getStands()))
	{
		if (player->getStands())
		{
			if (croupier->getCardsValue() > 21)
			{
				player->printRoundInfo();
				croupier->printRoundInfo();
				return false;
			}
			croupier->shouldStand();
			if (!croupier->getStands())
				croupier->drawCard(deck);
		}
		else
		{
			if (player->getCardsValue() > 21)
			{
				player->printRoundInfo();
				croupier->printRoundInfo();
				return false;
			}
			player->shouldStand();
			if (!player->getStands())
				player->drawCard(deck);
		}
	}
	player->printRoundInfo();
	croupier->printRoundInfo();
	return (player->getCardsValue() > croupier->getCardsValue()) ? true : false;

}



bool GameUtility::fillDeck(std::string filePath, std::stack<std::string>& deck) {
	std::ifstream file(filePath, std::ios::in);
	if (file.is_open()) {
		std::string allCards = "";
		std::getline(file, allCards);
		std::string delimiter = ";";
		size_t pos = 0;
		while ((pos = allCards.find(delimiter)) != std::string::npos) {
			deck.push(allCards.substr(0, allCards.find(delimiter)));
			allCards.erase(0, allCards.find(delimiter) + delimiter.length());
		}
	}
	else
		throw - 2;

	return true;
}