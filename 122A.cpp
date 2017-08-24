#include <bits/stdc++.h>

using namespace std;


bool checkIfLucky(int x)
{
    while(x>0)
    {
        if(x%10 == 4 || x%10 == 7)
        {
            x/=10;
        }
        else{return false;}
    }
    return true;
}
int main()
{
    int number, i;
    bool flag = false;
    cin >> number;
    for(i = 1; i<= number; i++)
    {
        if(checkIfLucky(i) && number % i == 0)
        {
            cout << "YES";
            flag = true;
            break;
        }
    }
    if(!flag)
    {
        cout << "NO";
    }
}
