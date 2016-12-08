#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
int main()
{
    int n, k, t, sum=0;
    scanf("%d %d", &n, &k);
    for(int i = 0; i< n;i++)
    {
        scanf("%d", &t);
        if(5-t>=k)
            sum++;
    }
    cout << sum/3;
}
