#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define pb push_back

int main()
{
    int r, x, y, x1, y1;
    double dist;
    scanf("%d %d %d %d %d", &r, &x, &y, &x1, &y1);
    dist = sqrt(double(pow((x-x1), 2)+pow((y-y1), 2)));
    dist =dist/(2*r);
    cout << int(ceil(dist));
}
