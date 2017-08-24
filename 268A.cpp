#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num_teams, sum = 0, hT, gT;
    scanf("%d", &num_teams);
    int home[100]={0}, guest[100]={0};
    for(int i = 0; i< num_teams; i++)
    {
        scanf("%d %d", &hT, &gT);
        home[hT-1]++;
        guest[gT-1]++;
    }
    for(int i = 0; i< 100; i++)
    {
        sum += home[i]*guest[i];
    }
    cout << sum;
}
