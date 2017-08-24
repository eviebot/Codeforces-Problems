//SAMPLE NOTE I AM A FAGGOT BECAUSE I FORGOT SIMPLE STUFF FUCK ME PLEASE SEND NUDES

#include <bits/stdc++.h>

using namespace std;

void SWAP(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}


int main()
{
    int stg, n, i, j;
    scanf("%d %d", &stg, &n);
    int d_stg[n], bonus[n];
    bool flag= true;
    for(i = 0; i< n; i++)
        scanf("%d %d", &d_stg[i], &bonus[i]);

    for(i= 0; i< n;i++)
    {
        for(j=n-1;j>i;j--)
        {
            if(d_stg[j]<d_stg[j-1])
            {
                SWAP(&d_stg[j], &d_stg[j-1]);
                SWAP(&bonus[j], &bonus[j-1]);
            }
        }
    }
    //for(i=0;i<n;i++)
    //    cout << d_stg[i]<<" " <<bonus[i]<< endl;

    for(i = 0; i<n; i++)
    {
        if(stg <=d_stg[i])
        {
            flag = false;
            break;
        }
        else
        {

            stg+= bonus[i];
        }
    }
    if(flag)
        cout << "YES";
    else
        cout << "NO";
}
