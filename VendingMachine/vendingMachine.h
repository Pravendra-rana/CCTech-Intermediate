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
    int noOfCola;
    int noOfChips;
    int noOfCandy;
    float productPrice;
    unordered_map<string, float> product = {{"cola", 1.00},
                                           {"chips", 0.50},
                                           {"candy", 0.65}};
    bool isValidCoin(string);
    bool soldOut(int);
public:
    VenderMachine();
    void acceptCoin(int, char*[]);
    void selectProduct();
    void addCoin();
    void makeChange();
    void returnCoin();
};

#endif