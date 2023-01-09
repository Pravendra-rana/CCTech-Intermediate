#include "currencyConvertor.h"

bool USD::getExchangeRate() {
    currencyExchangeRate = 1;
    return true;
}

double USD::toUSDCurrency(double currencyInUSD) {
    return currencyInUSD / currencyExchangeRate;
}

double USD::fromUSDCurrency(double currencyInUSD) {
    return currencyInUSD * currencyExchangeRate;
}

bool GBP::getExchangeRate() {
    string filename = "input.txt";
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << filename << " does not exists." << endl;
        return false;
    }
    string word, line, previousWord;
    while (file >> word) {
        if (word.compare("GBP") == 0) {
            currencyExchangeRate = stof(previousWord);
            break;
        }
        previousWord = word;
    }
    return true;
}

double GBP::toUSDCurrency(double currencyInGBP) {
    return currencyInGBP / currencyExchangeRate;
}

double GBP::fromUSDCurrency(double currencyInUSD) {
    return currencyInUSD * currencyExchangeRate;    
}

bool INR::getExchangeRate() {
    string filename = "exchangeRates.txt";
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << filename << " does not exists." << endl;
        return false;
    }
    string word, line, previousWord;
    while (file >> word) {
        if (word.compare("INR") == 0) {
            currencyExchangeRate = stof(previousWord);
            break;
        }
        previousWord = word;
    }
    return true;
}

double INR::toUSDCurrency(double currencyInINR) {
    return currencyInINR / currencyExchangeRate;
}

double INR::fromUSDCurrency(double currencyInUSD) {
    return currencyInUSD * currencyExchangeRate;
}

bool EUR::getExchangeRate() {
    string filename = "exchangeRates.txt";
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << filename << " does not exists." << endl;
        return false;
    }
    string word, line, previousWord;
    while (file >> word) {
        if (word.compare("EUR") == 0) {
            currencyExchangeRate = stof(previousWord);
            break;
        }
        previousWord = word;
    }
    return true;
}

double EUR::toUSDCurrency(double currencyInEUR) {
    return currencyInEUR / currencyExchangeRate;
}

double EUR::fromUSDCurrency(double currencyInUSD) {
    return currencyInUSD * currencyExchangeRate;   
}