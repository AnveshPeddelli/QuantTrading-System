#pragma once
#include "pch.h"

#ifdef TRADER_EXPORT
#define TRADER_API __declspec(dllexport)
#else
#define TRADER_API __declspec(dllimport)
#endif // TRADER_EXPORT
