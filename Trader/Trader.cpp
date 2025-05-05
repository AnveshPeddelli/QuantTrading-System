#include "pch.h"
#include "Trader.h"

TRADER_API std::unique_ptr<iTrader> GetTraderInstance()
{
	//Trader trader();
	return std::make_unique<Trader>();
}

TRADER_API std::unique_ptr<iTrader> GetTraderInstance(long long capital, int strategy)
{
	//Trader trader();
	return std::make_unique<Trader>(capital, strategy);
}

Trader::Trader()
{
	capital = 10000;
	strategy = Strategy::moving_averages_crossover;
}

Trader::Trader(long long _capital, int _strategy)
{
	capital = _capital;
	strategy = _strategy;
}

void Trader::setThresholds(int buyThreshold, int sellThreshold)
{
	buyThreshold = buyThreshold;
	sellThreshold = sellThreshold;
}

long long Trader::getCapital()
{
	return capital;
}

int Trader::getStrategy()
{
	return strategy;
}

void Trader::updateMarketData(double price)
{
	if (strategy == moving_averages_crossover)//
	{
		executeTrade(price);
	}
}

void Trader::executeTrade(double price)
{
	if (capital <= 0) return;

	if (price < buyThreshold)
	{
		std::cout << "Buying at price: " << price << std::endl;
		capital -= static_cast<long long>(price);
	}
	else if (price > sellThreshold)
	{
		std::cout << "Selling at price: " << price << std::endl;
		capital += static_cast<long long>(price);
	}
}