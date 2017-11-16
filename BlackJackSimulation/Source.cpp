#include "SafePlayer.h"
#include "Croupier.h"
#include "CustomPlayer.h"
#include "GameUtility.h"
#include <stack>


int main(int argc, char** argv)
{
    std::stack<std::string> stackOfCards;
    std::shared_ptr<Player> cautionPlayer(
            new SafePlayer("Caution player"));  // dlaczego używamy shared_ptr?
    std::shared_ptr<Player> croupier(new Croupier("Croupier"));               // lepiej unique_ptr
    std::shared_ptr<CustomPlayer> customPlayer(new CustomPlayer("Custom player"));
    try {
        if (argc < 2) {
            throw -1;   // lepiej od razu dać return z main i wydrukować jeśli błąd o danym kodzie wyskakuje w jednym miejscu
        }
        else {
            if (GameUtility::fillDeck(argv[1], stackOfCards) && stackOfCards.size() == 52) {
                std::cout << "Deck loaded correctly" << std::endl;
            }
            else {
                throw -3;
            }
        }
    }
    catch (const int err) {
        switch (err)  // wszystkie case do rozbicia na osobne linie (juz tutaj to zrobiłem)
        {
            // skoro robimy obsługę błędów gdzie indziej niż przy jego wyrzuceniem warto zrobić nową funkcję
            // np.     void logError(int errorCode)
            case -1:
                std::cerr
                        << "Too few arguments, please include path to deck into starting arguments"
                        << std::endl;
                break;
            case -2:
                std::cerr << "Failed to load the deck (File open error)" << std::endl;
                break;
            case -3:
                std::cerr << "Deck loaded incorrectly, deck size is diffrent than 52" << std::endl;
                break;
        }
        return err;
    }
    // Singleton, monostate i zmienne globalne są wzorcami antyprojektowymi i nie powinno się ich używać
    GameUtility::playGame(cautionPlayer, croupier, stackOfCards);
    std::cout << "=============================================================================="
              << std::endl;
    GameUtility::playGame(customPlayer, croupier, stackOfCards);
    return 0;
}


