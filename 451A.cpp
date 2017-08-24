#include <bits/stdc++.h>

using namespace std;

void throw_it_baby(int x)
{
    if(x%2 == 0)
        cout << "Malvika";
    else
        cout << "Akshat";
}

int main()
{
    int n, m;
    cin >> n >> m;
    throw_it_baby(n<m?n:m);

}
