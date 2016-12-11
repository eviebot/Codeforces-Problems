#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define pb push_back

int main()
{
    int n, i;
    scanf("%d", &n);
    int home = n-1, away = n-1;
    int away_col[n], home_col;
    map <int, int> mymap;
    for(i = 0; i< n;i++)
    {
        scanf("%d %d", &home_col, &away_col[i]);
        mymap[home_col]++;
    }
    for(i = 0; i< n;i++)
    {
        cout << home+mymap[away_col[i]] << " "<<away-mymap[away_col[i]]<< "\n";
    }
}
