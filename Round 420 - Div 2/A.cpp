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

    fastIO;
    int n, i, j, k, l;
    cin >> n;
    int arr[n][n];
    for( i = 0; i < n; ++i)
    {
        for(j = 0; j < n ; ++j)
        {
            cin >> arr[i][j];
        }
    }
    bool majorflag = true;
    for(i =0; i < n && majorflag; ++i)
    {
        for(j = 0; j < n; ++j)
        {
            if(arr[i][j] != 1)
            {
                bool flag = false;
                for(k = 0; k < n; ++k)
                {
                    for(l = 0; l < n; ++l)
                    {
                        if( arr[l][j] + arr[i][k] == arr[i][j])
                            flag = true;
                    }
                }
                if( majorflag && !flag){
                        majorflag = false;break;}
            }
        }
    }
    if( majorflag)
        cout << "Yes";
    else
        cout << "No";
}
