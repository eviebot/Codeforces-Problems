#include <bits/stdc++.h>
#include <time.h>
using namespace std;
#define endl "\n"

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long int n, i=0, no_of_digits, index_of_max= 0, digits[100]={0}, j=0, sum = 0;
    bool flag = true;
    cin >> n;
    no_of_digits = 0;
    while(n!=0)
    {
        digits[i] = n%10;
        if((n%10)%2==0)
         { j++;

         }
        no_of_digits++;
        i++;
        n/=10;
    }
    if(j==0)
        cout << "-1";
    else{
    for(i= 0; i<no_of_digits;i++)
    {
        if(digits[i]%2==0)
        {
            if(flag)
            {
                flag = false;
                index_of_max = i;
            }
            if(digits[i] < digits[0])
                index_of_max = i;
        }
    }
    for(i = no_of_digits-1; i>=1;i--)
    {
        if(index_of_max==i)
            sum += digits[0];
        else
            sum += digits[i];
        sum *=10;
    }
    sum += digits[index_of_max];
    cout << sum;
    }
}
