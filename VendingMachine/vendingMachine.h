#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H 1

#include <iostream>
#include <cassert>
#include <unordered_map>

using namespace std;

class VenderMachine 
{
private:
    float totalAmount;
    unordered_map<string, float> coins = {{"nickels", 0.05},
                               {"dimes", 0.10},
                               {"quarter", 0.25}};
    float productPrice;
    unordered_map<string, float> product = {{"cola", 1.00},
                                           {"chips", 0.50},
                                           {"candy", 0.65}};
    bool isValidCoin(string);
public:
    VenderMachine();
    void acceptCoin(int, char*[]);
    void selectProduct();
    void addCoin();
    void makeChange(string);
    void returnCoin();
    void soldOut();
    void exactChange();
};

#endif