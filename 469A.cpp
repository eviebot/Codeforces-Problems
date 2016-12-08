#include <bits/stdc++.h>

using namespace std;

int main()
{
    unsigned int n, p , q, sum=0, t, i;
    scanf("%d", &n);
    bool flags[n]= {false};
    scanf("%d", &p);
    for(i = 0; i< p; i++)
    {
        scanf("%d", &t);
        if(!flags[t-1])
        {
            sum++;
            flags[t-1]=true;
        }
    }
    scanf("%d", &q);
    for(i = 0; i< q; i++)
    {
        scanf("%d", &t);
        if(!flags[t-1])
        {
            sum++;
            flags[t-1]=true;
        }
    }
    if(sum == n)
        cout << "I become the guy.";
    else
        cout << "Oh, my keyboard!";
}
