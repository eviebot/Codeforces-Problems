#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
int main()
{
    int n, m, i, j;
    cin >> n >> m;
    for(i =1; i<=n;i++)
    {
        for(j = 1; j<= m; j++)
        {
            if((i%2)==1)
            {
                   printf("#");
            }
            else if(i%4==2)
            {
                if(j==m){printf("#");}

                else{printf(".");}
            }
            else
            {
                if(j==1){printf("#");}

                else{printf(".");}
            }
        }
        printf("\n");
    }
}
