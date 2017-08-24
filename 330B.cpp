#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define pb push_back

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int i, n, m, x, y, index, j;
    scanf("%d %d", &n, &m);
    bool flag[n]={false};

    for(i=0;i<m;i++)
    {
        scanf("%d %d", &x, &y);
        if(!flag[x-1])
        {
            flag[x-1]=true;
        }
        if(!flag[y-1])
        {
            flag[y-1]=true;
        }
    }
    cout << (n-1)<<"\n";
    for(i = 0;i<n;i++)
    {
        if(!flag[i]){
            index = i;
            for(j=0;j<n;j++)
            {
                if(j!=index)
                    cout << min(j+1, index+1)<< " "<< max(j+1, index+1)<<"\n";
            }
            break;}
    }
}


