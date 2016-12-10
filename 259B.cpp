#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define pb push_back

int main()
{
    int r[9], x, y, z, i;
    for(i = 0; i< 9;i++)
        scanf("%d", &r[i]);
    x = (r[3]+r[5]+r[6]+r[7]-r[1]-r[2])/2;
    y = x+r[1]+r[2]-r[3]-r[5];
    z = x+r[1]+r[2]-r[6]-r[7];
    cout << x<< " "<< r[1]<< " "<< r[2]<< "\n";
    cout << r[3]<< " "<< y<< " "<< r[5]<< "\n";
    cout << r[6]<< " "<< r[7]<< " "<< z<< "\n";
}
