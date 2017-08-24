#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, a, b;
    cin >> n >> m;
    int pien[m]={0};
    for(int i = 0; i< m; i++)
    {
        scanf("%d", &pien[i]);
    }
    sort(pien, pien +m);
   /* for(int i = 0; i< m; i++)
    {
        cout << pien[i] << endl;
    }*/
    if(m%2==1)
    {
        if(n%2==0)
        {
            a = (pien[m/2+n/2]-pien[m/2-n/2+1]);
            b = pien[m/2+n/2-1]-pien[m/2-n/2];
            cout << (a<b?a:b);
        }
        else
        {
            cout << (pien[m/2+n/2]-pien[m/2-n/2]);
        }

    }
    else
    {
        if(n%2==1)
        {
            a = pien[m/2+n/2]-pien[m/2-n/2];
            b = pien[m/2+n/2-1]-pien[m/2-n/2-1];
            cout << (a<b?a:b);
        }
        else
        {
            cout << pien[m/2+n/2-1]-pien[m/2-n/2];
        }
    }
}
