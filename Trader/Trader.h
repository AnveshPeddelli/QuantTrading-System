#pragma once
#include "iTrader.h"
#include "../utilities.h"


class Trader : public iTrader
{
public:
	Trader();
	Trader(long long capital, int strategy);

	void setThresholds(int buyThreshold, int sellThreshold);
	long long getCapital();
	void updateMarketData(double price);
	void executeTrade(double price);

private:
	long long capital;
	int strategy;
	int buyThreshold, sellThreshold;

};

