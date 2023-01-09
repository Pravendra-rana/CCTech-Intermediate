#include "currencyConvertor.h"

bool GBP::getExchangeRate() {
    currencyExchangeRate = 1;
    return true;
}

double GBP::toGBPCurrency(double currencyInGBP) {
    return currencyInGBP / currencyExchangeRate;
}

double GBP::fromGBPCurrency(double currencyInGBP) {
    return currencyInGBP * currencyExchangeRate;
}

bool USD::getExchangeRate() {
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

double USD::toGBPCurrency(double currencyInUSD) {
    return currencyInUSD / currencyExchangeRate;
}

double USD::fromGBPCurrency(double currencyInGBP) {
    return currencyInGBP * currencyExchangeRate;    
}

bool INR::getExchangeRate() {
    string filename = "input.txt";
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

double INR::toGBPCurrency(double currencyInINR) {
    return currencyInINR / currencyExchangeRate;
}

double INR::fromGBPCurrency(double currencyInGBP) {
    return currencyInGBP * currencyExchangeRate;
}

bool EUR::getExchangeRate() {
    string filename = "input.txt";
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

double EUR::toGBPCurrency(double currencyInEUR) {
    return currencyInEUR / currencyExchangeRate;
}

double EUR::fromGBPCurrency(double currencyInGBP) {
    return currencyInGBP * currencyExchangeRate;   
}