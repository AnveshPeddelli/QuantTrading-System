#include "Trader.h"

TRADER_API std::unique_ptr<iTrader> getTraderInstance()
{
	
}

Trader::Trader()
{
	this->capital = 10000;
	this->strategy = Strategy::moving_averages_crossover;
}

Trader::Trader(long long capital, int strategy)
{
	this->capital = capital;
	this->strategy = strategy;
}

void Trader::setThresholds(int buyThreshold, int sellThreshold)
{
	this->buyThreshold = buyThreshold;
	this->sellThreshold = sellThreshold;
}

long long Trader::getCapital()
{
	return this->capital;
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