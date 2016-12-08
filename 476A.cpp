#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, init_moves, final_moves;
    cin >> n  >> m;
    init_moves = n/2+(n%2);
    if(n < m)
    {
        cout << "-1";
    }
    else
    {
        if(init_moves%m == 0)
           {
               final_moves = init_moves;
           }
        else
        {
             final_moves = init_moves+(m-init_moves%m);
        }
        cout << final_moves;
    }
}
