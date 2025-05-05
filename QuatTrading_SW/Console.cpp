#include "Trader.h"

int main()
{
	long long capital = 900000;
	int strat = 3;
	auto trader1 = GetTraderInstance(capital, strat);
	
	std::cout << "Capital: " << trader1->getCapital()<< std::endl;
	std::cout << "Strategy: " << trader1->getStrategy() << std::endl;
}