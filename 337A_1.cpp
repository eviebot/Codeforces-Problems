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
    int comp = pien[n-1]-pien[0];
    for(int i = n;i<m;i++)
    {
        if((pien[i]-pien[i-n+1]) < comp)
            comp = (pien[i]-pien[i-n+1]);
    }
    cout << comp;
}
