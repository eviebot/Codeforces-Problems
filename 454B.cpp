#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define pb push_back


int main()
{   bool flag = true, minus_flag = false;
    int n, index,first, t, j = 0;
    scanf("%d", &n);
    scanf("%d", &first);
    int first_temp = first;
    for(int i=1; i<n;i++)
    {
        scanf("%d", &t);
        if(t < first)
        {
            if(flag)
            {flag = false;
            j++;
            index = n-i;}
            else
            {
                minus_flag = true;
            }
        }
        if(t>first_temp && !flag)
        {
                minus_flag = true;
                break;
        }
        first = t;
    }
    if(minus_flag)
        cout << "-1";
    else if(j==0)
        cout << "0";
    else
        cout << index;
}

