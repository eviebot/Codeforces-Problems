#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x1, y1, x2, y2, x3, y3, x4, y4;
    scanf("%d %d %d %d" , &x1, &y1, &x2, &y2);
    bool flag = true;
    if(abs(x2-x1)== abs(y2-y1))
    {
        x3 = x2; y3 = y1; x4 = x1; y4 = y2;
    }
    else if(x1 == x2)
    {
        x3 = x1+abs(y2-y1);y3 = y2; x4 = x3; y4 = y1;
    }
    else if(y1 == y2)
    {
        x3 = x1; y3 = y1+abs(x2-x1); x4 = x2; y4 = y3;
    }
    else
        flag = false;
    if(flag)
        cout << x3 << " " << y3<<" " << x4 << " "<< y4;
    else
        cout << "-1";
}
