#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int findClosestNumber(int arr[], int n)
{
    int ans = arr[0];
    int min = std::abs(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if(std::abs(arr[i]) < min)
        {
            ans = arr[i];
            min = std::abs(arr[i]);
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
    cout << "Closest no to zero is : " << findClosestNumber(arr, n);
    return 0;
}