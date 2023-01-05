#include "vendingMachine.h"

VenderMachine::VenderMachine()
{
    totalAmount = 0.0;
    productPrice = 0.0;
    noOfCola = 10;
    noOfChips = 10;
    noOfCandy = 10;
}

bool VenderMachine::isValidCoin(string coin)
{
    if(coin == "nickels" || coin == "dimes" || coin == "quarter")
       return true;
    return false;
}

bool VenderMachine::soldOut(int noOfProduct)
{
    return noOfProduct <= 0;
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
           cerr << "INVALID COINS, PLEASE COLLECT YOUR COIN AND TRY AGAIN WITH VALID COINS." << endl;
           return;
        }
    }
    selectProduct();
}

void VenderMachine::selectProduct()
{   
    int item;
    cout << "SELECT OPTION:\n1. cola    2. chips\n3. candy  4. return-coin" << endl;
    cin >> item;
    switch (item)
    {
    case 1:
        if(soldOut(noOfCola))
        {
            cout << "SOLD OUT!" << endl;
            cout << "Please choose different option" << endl;
            selectProduct();
        }
        else {
            productPrice += product["cola"];
            noOfCola--;
        }
        break;
    case 2:
        if(soldOut(noOfChips))
        {
            cout << "SOLD OUT!" << endl;
            cout << "Please choose different option" << endl;
            selectProduct();
        }
        else {
            productPrice += product["chips"];
            noOfChips--;
        }
        break;
    case 3:
        if(soldOut(noOfCandy))
        {
            cout << "SOLD OUT!" << endl;
            cout << "Please choose different option" << endl;
            selectProduct();
        }
        else {
            productPrice += product["candy"];
            noOfCandy--;
        }
        break;
    case 4:
        returnCoin();
        return;
    default:
        cout << "INVALID OPTION! Please try again." << endl;
        selectProduct();
        break;
    }
    // if(item == "return-coin")
    //    returnCoin();
    // else
    //    productPrice += product[item];
    if(totalAmount < productPrice)
    {
        cout << "Insufficient coins!\nInserted money : " << totalAmount
             << "\nProduct price : " << productPrice << "\nPlease add "
             << productPrice - totalAmount << "$ or more to proceed." << endl;
        addCoin();
    }
    else
        makeChange();
}

void VenderMachine::addCoin()
{
    string coin;
    cout << "INSERT COIN!" << endl;
    cin >> coin;
    if(isValidCoin(coin))
        totalAmount += coins[coin];
    else
    {
        cerr << "INVALID COINS, PLEASE COLLECT IT AND TRY AGAIN WITH VALID COINS." << endl;
        addCoin();
    }
    productPrice = 0.0;
    selectProduct();
}

void VenderMachine::makeChange()
{
    if(totalAmount == productPrice)
    {
        totalAmount = 0.0;
        cout << "Collect your product"<< endl
             << "THANK YOU." << endl
             << "----------" << endl;
    }
    else if(totalAmount > productPrice)
    {
        cout << "Collect your change : " << totalAmount - productPrice<< " & collect your product"<< endl
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
