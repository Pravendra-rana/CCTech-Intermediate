#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findClosestNumber(int arr[])
{
    int ans = arr[0];
    int min = abs(arr[0]);
    for (int i = 0; i < (sizeof(arr)/sizeof(arr[0])); i++)
    {
        if(abs(arr[i]) < min)
        {
            ans = arr[i];
            min = abs(arr[i]);
        }
    }
    return ans;
}
int main()
{
    int n, arr[20];
    cout << "Enter a no : ";
    cin >> n;
    cout << "Enter list element : "; 
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Closest no to zero is : " << findClosestNumber(arr);
    return 0;
}