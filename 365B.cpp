#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define pb push_back

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n, i, sum = 2, maxi=2;
    scanf("%d", &n);
    int arr[n];
    if(n==1||n==2)
    {
        cout << n;return 0;
    }
    else
    {
        scanf("%d %d", &arr[0], &arr[1]);
        for(i = 2; i< n;i++)
        {
            scanf("%d", &arr[i]);
            {
                if(arr[i]==arr[i-1]+arr[i-2])
                    sum++;
                else{sum = 2;}
            }

            maxi = (sum >maxi? sum:maxi);
        }
        cout << maxi <<"\n";
    }
    return 0;
}
