#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define pb push_back

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int i, j, k, p, q, l, r, c, d, sum = 0;
    scanf("%d %d %d %d", &p, &q, &l, &r);
    map <int, bool> mymap;
    int a[p], b[p];
    for(i= 0; i< p; i++)
    {
        scanf("%d %d", &a[i], &b[i]);
    }
    for(i = 0; i<q;i++)
    {
        scanf("%d %d", &c, &d);
        for(j = 0; j< p;j++)
        {
            for(k = ((a[j]-d)<0?0:a[j]-d) ; k< ((b[j]-c)<0?0:b[j]-c)+1;k++)
            {
                if(!mymap[k])
                {
                    mymap[k] = true;
                }
            }
        }
    }
    for(i = l;i<=r;i++){
        sum += mymap[i];}
    cout << sum ;
}
