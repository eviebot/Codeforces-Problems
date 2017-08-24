#include <bits/stdc++.h>
using namespace std;

#define fastIO ios::sync_with_stdio(false);cout.tie(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair
#define inf INT_MAX
#define minf INT_MIN

typedef long long int lli;

ofstream outfile;
ifstream infile;

int main()
{
    infile.open("input.txt");
    outfile.open("output.txt");

    int n, m, i, j;
    cin >> n >> m;
    bool flag = true;
    int row[n+1], col[m+1], matrix[n+1][m+1];

    if( n <= m)
    {
        int minimun[n+1];
        for(i = 1; i <= n; ++i){
            row[i] = -1;minimun[i] = 1000000;}
        for(j = 1; j <= m; ++j)
            col[j] = -1;

        for(i = 1; i <= n; ++i)
        {
            for(j = 1; j <= m; ++j)
            {
                cin >> matrix[i][j];
            }
        }

        for(i = 1; i <= n; ++i)
        {
            for(j = 1; j <= m; ++j)
            {
                if( matrix[i][j] < minimun[i])
                    minimun[i] = matrix[i][j];
            }
            row[i] = minimun[i];
        }

        for(i = 1; i <= n && flag; ++i)
        {
            for(j = 1; j <= m; ++j)
            {
                if( col[j] == -1 )
                {
                    col[j] = matrix[i][j] - row[i];
                }
                else
                {
                    if( matrix[i][j] - row[i] != col[j])
                        flag = false;
                }
            }
        }

    }
    else
    {
        int minimun[m+1];
        for(i = 1; i <= n; ++i){
            row[i] = -1;}
        for(j = 1; j <= m; ++j){
            col[j] = -1;minimun[j] = 1000000;}

        for(i = 1; i <= n; ++i)
        {
            for(j = 1; j <= m; ++j)
            {
                cin >> matrix[i][j];
            }
        }

        for(i = 1; i <= m; ++i)
        {
            for(j = 1; j <= n; ++j)
            {
                if( matrix[j][i] < minimun[i])
                    minimun[i] = matrix[j][i];
            }
            col[i] = minimun[i];
        }

        for(i = 1; i <= m && flag; ++i)
        {
            for(j = 1; j <= n; ++j)
            {
                if( row[j] == -1 )
                {
                    row[j] = matrix[j][i] - col[i];
                }
                else
                {
                    if( matrix[j][i] - col[i] != row[j])
                        flag = false;
                }
            }
        }
    }
    if(!flag)
            cout << "-1";
    else
    {
        int sum = 0;
        for(i = 1; i <= n; ++i)
        {
            sum += row[i];
        }
        for(j = 1; j <= m; ++j)
        {
            sum += col[j];
        }
        cout << sum <<"\n";
        for(i = 1; i <= n; ++i)
        {
            if( row[i])
            {
                for(int k = 0; k < row[i]; ++k)
                {
                    cout << "row "<< i << "\n";
                }
            }
        }
        for(j = 1; j <= m; ++j)
        {
            if( col[j])
            {
                for(int k = 0; k < col[j]; ++k)
                {
                    cout << "col "<< j << "\n";
                }
            }
        }
    }
}