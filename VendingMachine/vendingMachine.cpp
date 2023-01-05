#include "vendingMachine.h"

VenderMachine::VenderMachine()
{
    totalAmount = 0.0;
    productPrice = 0.0;
}

bool VenderMachine::isValidCoin(string coin)
{
    if(coin == "nickels" || coin == "dimes" || coin == "quarter")
       return true;
    return false;
}

void VenderMachine::acceptCoin(int argc, char* argv[])
{
    string coin;
    for(int i = 1; i < argc; i++)
    {
        coin = argv[i];
        if(isValidCoin(coin))
            totalAmount += coins[coin];
        else
        {
           cerr << "INVALID COINS, PLEASE COLLECT IT AND TRY AGAIN WITH VALID COINS." << endl;
           return;
        }
    }
    selectProduct();
}

void VenderMachine::selectProduct()
{   
    string item;
    cout << "SELECT ITEM:\n-> cola    -> chips\n-> candy  -> return-coin" << endl;
    cin >> item;
    if(item == "return-coin")
       returnCoin();
    else
       productPrice += product[item];
    if(totalAmount < productPrice)
    {
        cout << "Insufficient coins!\nInserted money : " << totalAmount
             << "\nProduct price : " << productPrice << "\nPlease add "
             << productPrice - totalAmount << "$ or more to proceed." << endl;
        addCoin();
    }
    else
        makeChange(item);
}

void VenderMachine::addCoin()
{
    string coin;
    cout << "INSERT COIN!" << endl;
    cin >> coin;
    totalAmount += coins[coin];
    productPrice = 0.0;
    selectProduct();
}

void VenderMachine::makeChange(string item)
{
    if(totalAmount == productPrice)
    {
        totalAmount = 0.0;
        cout << "Collect your " << item << endl
             << "THANK YOU." << endl
             << "----------" << endl;
    }
    else if(totalAmount > productPrice)
    {
        cout << "Collect your change : " << totalAmount - productPrice<< " & collect your " << item << endl
             << "THANK YOU." << endl
             << "----------" << endl;
        totalAmount = 0.0;

    }
}

void VenderMachine::returnCoin()
{
    cout << "COINS RETURNED! PLEASE COLLECT YOUR COIN : " << totalAmount << "$" << endl
         << "THANK YOU." << endl;
    totalAmount = 0;
}
