#pragma once
#include "pch.h"
#include "Export.h"
#include <memory>

class TRADER_API iTrader
{
public:
	virtual void setThresholds(int buyThreshold, int sellThreshold) = 0;
	
	virtual long long getCapital() = 0;
	
	virtual void updateMarketData(double price) = 0;
	virtual void executeTrade(double price) = 0;
	virtual ~iTrader() = 0;

private:

};

TRADER_API std::unique_ptr<iTrader> GetTraderInstance();