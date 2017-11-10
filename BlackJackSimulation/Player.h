#include <string>
#include <vector>
class Player
{
private:
	std::vector<std::string> cards;
public:
	Player();
	virtual ~Player();
	 
	virtual std::string drawCard() = 0;
};
