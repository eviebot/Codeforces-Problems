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
    int index = 1, n, sum = 0, t;
    string dec;

    cin >> n;
    stack <int> arr;
    for(int i = 0 ; i < 2 *n; ++i)
    {
        cin >> dec ;
        if( dec == "remove")
        {
            if( arr.empty())
            {
                ++index;
                continue;
            }
            if( arr.top() != index)
            {
                ++sum;
                while(++i != 2*n)
                {

                    ++index;
                    cin >> dec;
                    if( dec == "add")
                    {
                        while(!arr.empty())
                            arr.pop();
                        cin >> t;
                        arr.push(t);
                        break;
                    }
                }
            }
            else
            {
                arr.pop();
                ++index;
            }
        }
        else
        {
            cin >> t;
            arr.push(t);
        }
    }
    cout << sum;
}
