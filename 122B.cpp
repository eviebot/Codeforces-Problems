/*░░░░░░░░░░░░▄▄▄▄░░░░░░░░░░░░░░░░░░░░░░░▄▄▄▄▄░░░░
  ░░░█░░░░▄▀█▀▀▄░░▀▀▀▄░░░░▐█░░░░░░░░░▄▀█▀▀▄░░░▀█▄░
  ░░█░░░░▀░▐▌░░▐▌░░░░░▀░░░▐█░░░░░░░░▀░▐▌░░▐▌░░░░█▀
  ░▐▌░░░░░░░▀▄▄▀░░░░░░░░░░▐█▄▄░░░░░░░░░▀▄▄▀░░░░░▐▌
  ░█░░░░░░░░░░░░░░░░░░░░░░░░░▀█░░░░░░░░░░░░░░░░░░█
  ▐█░░░░░░░░░░░░░░░░░░░░░░░░░░█▌░░░░░░░░░░░░░░░░░█
  ▐█░░░░░░░░░░░░░░░░░░░░░░░░░░█▌░░░░░░░░░░░░░░░░░█
  ░█░░░░░░░░░░░░░░░░░░░░█▄░░░▄█░░░░░░░░░░░░░░░░░░█
  ░▐▌░░░░░░░░░░░░░░░░░░░░▀███▀░░░░░░░░░░░░░░░░░░▐▌
  ░░█░░░░░░░░░░░░░░░░░▀▄░░░░░░░░░░▄▀░░░░░░░░░░░░█░
  ░░░█░░░░░░░░░░░░░░░░░░▀▄▄▄▄▄▄▄▀▀░░░░░░░░░░░░░█░  - PROPRIETARY CODE OF EVIEBOT*/


#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define pb push_back

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n, i, a, b, sum=0, c=1, j = 0;
    multiset <int> p2;
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d", &a, &b);
        if(b>0)
        {
            c += (b-1);;
            sum +=a;j++;
        }
        else
        {
            p2.insert(a);
        }
    }
    multiset <int>::reverse_iterator it1 = p2.rbegin();

    c = (c>=n-j?n-j:c);

    while(c!=0)
    {
        sum += *it1;
        it1++;c--;
    }
    cout << sum;
}
