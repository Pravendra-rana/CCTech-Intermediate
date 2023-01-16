#include "currencyConverter.h"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getInputCurrency(int lengthOfCurrencyList)
{
    int inputCurrency;
    cin >> inputCurrency;
    if (cin.fail())
    {
        cout << "Please enter a valid number" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getInputCurrency(lengthOfCurrencyList);
    }
    else if (inputCurrency < 1 || inputCurrency > lengthOfCurrencyList)
    {
        cout << "The number is out of range" << endl
             << "Please enter valid number" << endl;
        getInputCurrency(lengthOfCurrencyList);
    }
    return inputCurrency;
}

int getOutputCurrency(int lengthOfCurrencyList)
{
    int outputCurrency;
    cin >> outputCurrency;
    if (cin.fail())
    {
        cout << "Please enter a valid number" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getOutputCurrency(lengthOfCurrencyList);
    }
    else if (outputCurrency < 1 || outputCurrency > lengthOfCurrencyList)
    {
        cout << "The number is out of range" << endl;
        getOutputCurrency(lengthOfCurrencyList);
    }
    return outputCurrency;
}

double getInputAmount()
{
    double inputAmount;
    cin >> inputAmount;
    if(cin.fail())
    {
        cout << "Please enter a valid number" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getInputAmount();
    }
    return inputAmount;
}

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
        CHF chf;
        AUD aud;
        SGD sgd;
        vector<CurrencyConverter *> inputCurrencies = {&usd, &inr, &gbp, &eur, &chf, &aud, &sgd};
        vector<string> inputCurrencyNames = {"USD", "INR", "GBP", "EUR", "CHF", "AUD", "SGD"};
        CurrencyConverter *inputCurrency;
        int inputCurrencyIndex;

        while (1)
        {
            cout << "Select the input currency from the list" << endl;
            {
                int i = 1;
                for (auto currencyName : inputCurrencyNames)
                    cout << i++ << "." << currencyName << endl;
            }
            inputCurrencyIndex = getInputCurrency(inputCurrencies.size());
            inputCurrency = inputCurrencies.at(inputCurrencyIndex - 1);
            break;
        }

        vector<CurrencyConverter *> outputCurrencies;
        vector<string> outputCurrencyNames;
        {
            int it = 0;

            for (int it = 0; it < inputCurrencies.size(); it++)
            {
                if (inputCurrency != inputCurrencies.at(it))
                {
                    outputCurrencies.emplace_back(inputCurrencies.at(it));
                    outputCurrencyNames.emplace_back(inputCurrencyNames.at(it));
                }
            }
        }
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
            outputCurrencyIndex = getOutputCurrency(outputCurrencies.size());
            outputCurrency = outputCurrencies.at(outputCurrencyIndex - 1);
            break;
        }

        double moneyInInPutCurrency;
        cout << "Please enter the amount\n>";
        moneyInInPutCurrency = getInputAmount();

        inputCurrency->getExchangeRate();
        double moneyInGBP = inputCurrency->toGBPCurrency(moneyInInPutCurrency);
        outputCurrency->getExchangeRate();
        double moneyInOutPutCurrency = outputCurrency->fromGBPCurrency(moneyInGBP);
        cout << moneyInInPutCurrency << " " << inputCurrencyNames.at(inputCurrencyIndex - 1) << " would be "
             << moneyInOutPutCurrency << " " << outputCurrencyNames.at(outputCurrencyIndex - 1) << " on"
             << " 2023-01-09" << endl;

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