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
    VenderMachine()
    {
        totalAmount = 0.0;
        productPrice = 0.0;
    }
    void acceptCoin(int, char*[]);
    void selectProduct();
    void addCoin();
    void makeChange(string);
    void returnCoin();
    void soldOut();
    void exactChange();
};

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

int main(int argc, char* argv[])
{
    VenderMachine ven;
    ven.acceptCoin(argc, argv);
}