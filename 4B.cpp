/*░░░░░░░░░░░░▄▄▄▄░░░░░░░░░░░░░░░░░░░░░░░▄▄▄▄▄░░░░
  ░░░█░░░░▄▀█▀▀▄░░▀▀▀▄░░░░▐█░░░░░░░░░▄▀█▀▀▄░░░▀█▄░
  ░░█░░░░▀░▐▌░░▐▌░░░░░▀░░░▐█░░░░░░░░▀░▐▌░░▐▌░░░░█▀
  ░▐▌░░░░░░░▀▄▄▀░░░░░░░░░░▐█▄▄░░░░░░░░░▀▄▄▀░░░░░▐▌
  ░█░░░░░░░░░░░░░░░░░░░░░░░░░▀█░░░░░░░░░░░░░░░░░░█
  ▐█░░░░░░░░░░░░░░░░░░░░░░░░░░█▌░░░░░░░░░░░░░░░░░█
  ▐█░░░░░░░░░░░░░░░░░░░░░░░░░░█▌░░░░░░░░░░░░░░░░░█
  ░█░░░░░░░░░░░░░░░░░░░░█▄░░░▄█░░░░░░░░░░░░░░░░░░█
  ░▐▌░░░░░░░░░░░░░░░░░░░░▀███▀░░░░░░░░░░░░░░░░░░▐▌
  ░░█░░░░░░░░░░░░░░░░░▀▄░░░░░░░░░░▄▀░░░░░░░░░░░░█░
  ░░░█░░░░░░░░░░░░░░░░░░▀▄▄▄▄▄▄▄▀▀░░░░░░░░░░░░░█░  - PROPRIETARY CODE OF EVIEBOT*/


#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define pb push_back

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int d, sumTime,i, sum=0, sum1=0, status;
    scanf("%d %d", &d, &sumTime);
    int minmaxi[d][2];
    for(i=0;i<d;i++)
    {
        scanf("%d %d", &minmaxi[i][0], &minmaxi[i][1]);
        sum += minmaxi[i][0];sum1+=minmaxi[i][1];
    }
    if(sum > sumTime || sum1 < sumTime)
        cout << "NO";
    else
    {
        cout << "YES\n";
        status = sumTime-sum;
        for(i = 0; i< d;i++)
        {
            if(status >= minmaxi[i][1]-minmaxi[i][0])
            {   status =status- (minmaxi[i][1]-minmaxi[i][0]);
                minmaxi[i][0]=minmaxi[i][1];
            }
            else
            {
                minmaxi[i][0] += status;
                status = 0;
            }
            cout << minmaxi[i][0]<< " ";
        }
    }
}
