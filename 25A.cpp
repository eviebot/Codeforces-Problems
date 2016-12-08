#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
int main()
{
    int n ,t1, t2, t3;
    scanf("%d %d %d",&n, &t1, &t2);
    if((t1%2)==(t2%2))
    {
        for(int i =3;i<=n;i++)
        {
            scanf("%d", &t3);
            if(t3%2!=t2%2)
            {   cout << i;
                break;
            }

        }
    }
    else
    {
        scanf("%d",&t3);
        cout << (t3%2==t2%2?"1":"2");
    }
}
