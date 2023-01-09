#ifndef CURRENCYCONVERTOR_H
#define CURRENCYCONVERTOR_H 1 

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class CurrencyConverter
{
public:
    virtual bool   getExchangeRate()       = 0;
    virtual double toGBPCurrency(double)   = 0;
    virtual double fromGBPCurrency(double) = 0;
};

class USD : public CurrencyConverter {
public:
    double currencyExchangeRate;
    bool   getExchangeRate();
    double toGBPCurrency(double);
    double fromGBPCurrency(double);
};

class GBP : public CurrencyConverter {
public:
    double currencyExchangeRate;
    bool   getExchangeRate();
    double toGBPCurrency(double);
    double fromGBPCurrency(double);
};

class INR : public CurrencyConverter {
public:
    double currencyExchangeRate;
    bool   getExchangeRate();
    double toGBPCurrency(double);
    double fromGBPCurrency(double);
};

class EUR : public CurrencyConverter {
public:
    double currencyExchangeRate;
    bool   getExchangeRate();
    double toGBPCurrency(double);
    double fromGBPCurrency(double);
};

#endif