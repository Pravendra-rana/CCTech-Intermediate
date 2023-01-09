#include "currencyConvertor.h"

#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

int main()
{
    bool choice = false;
    do
    {
        cout << "Welcome to CCTech Currency converter:" << endl;
        USD usd;
        INR inr;
        GBP gbp;
        EUR eur;
        vector<CurrencyConverter *> inputCurrencies = {&usd, &inr, &gbp, &eur};
        vector<string> inputCurrencyNames = {"USD", "INR", "GBP", "EUR"};
        CurrencyConverter *inputCurrency;
        int inputCurrencyIndex;
        {

            while (1)
            {
                cout << "Select the input currency from the list" << endl;
                {
                    int i = 1;
                    for (auto currencyName : inputCurrencyNames)
                        cout << i++ << "." << currencyName << endl;
                }
                string temp;
                cin >> temp;
                if (all_of(temp.begin(), temp.end(), ::isdigit) && (stoi(temp) >= 0 && stoi(temp) < inputCurrencies.size()))
                {
                    inputCurrencyIndex = stoi(temp);
                    break;
                }
                if (all_of(temp.begin(), temp.end(), ::isdigit))
                {
                    cout << "Please enter a valid number" << endl;
                }
                else if (stoi(temp) >= 0 && stoi(temp) < inputCurrencies.size())
                {
                    cout << "The number is out of range" << endl;
                }
            }
            inputCurrency = inputCurrencies.at(inputCurrencyIndex - 1);
        }

        vector<CurrencyConverter *> outputCurrencies = {&usd, &inr, &gbp, &eur};
        vector<string> outputCurrencyNames = {"USD", "INR", "GBP", "EUR"};
        CurrencyConverter *outputCurrency;
        int outputCurrencyIndex;
        while (1)
        {
            cout << "Select the output currency from the list" << endl;

            {
                int j = 1;
                for (auto currencyName : outputCurrencyNames)
                    cout << j++ << "." << currencyName << endl;
            }
            string temp;
            cin >> temp;
            if (all_of(temp.begin(), temp.end(), ::isdigit) && (stoi(temp) >= 0 && stoi(temp) < inputCurrencies.size()))
            {
                outputCurrencyIndex = stoi(temp);
                break;
            }
            if (all_of(temp.begin(), temp.end(), ::isdigit))
            {
                cout << "Please enter a valid number" << endl;
            }
            else if (stoi(temp) >= 0 && stoi(temp) < inputCurrencies.size())
            {
                cout << "The number is out of range" << endl;
            }
            
            outputCurrency = outputCurrencies.at(outputCurrencyIndex - 1);
        }
        double moneyInInPutCurrency;
        cout << "Please enter the amount\n>";
        cin >> moneyInInPutCurrency;
        
        inputCurrency->getExchangeRate();
        double moneyInGBP = inputCurrency->toGBPCurrency(moneyInInPutCurrency);
        outputCurrency->getExchangeRate();
        double moneyInOutPutCurrency = outputCurrency->fromGBPCurrency(moneyInGBP);
        cout << moneyInInPutCurrency << inputCurrencies.at(inputCurrencyIndex - 1) << " would be "
             << moneyInOutPutCurrency << outputCurrencies.at(outputCurrencyIndex - 1) << " on"
             << " 2023-01-06" << endl;

        char Continue;
        cout << "Do you want to continue with another conversion (Y/N)" << endl;
        cin >> Continue;
        while (true)
        {
            if (tolower(Continue) == 'y' || tolower(Continue) == 'n')
                break;
            cout << "Invalid input, please enter Y/N" << endl;
            cin >> Continue;
        }
        if (tolower(Continue) == 'y')
            choice = true;
        else if (tolower(Continue) == 'n')
            choice = false;
    } while (choice);
}