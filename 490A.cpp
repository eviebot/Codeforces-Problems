#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
int main()
{
    int n, i, one = 0, two = 0, three = 0, num_teams;
    scanf("%d", &n);
    int sto[n];
    for(i = 0; i< n; i++)
    {
        scanf("%d", &sto[i]);
        (sto[i]==3?three++:(sto[i]==2?two++:one++));
    }
    if(one==0||two==0||three==0)
        printf("0");
    else
    {
    num_teams = min(one, min(two, three));
    printf("%d\n", num_teams);
    int index_one[num_teams], index_two[num_teams], index_three[num_teams];
    one =0;
    two=0;
    three=0;
    i =0;
    bool flag_one= true, flag_two=true, flag_three=true;
    while(flag_one || flag_two || flag_three)
    {  
        if(sto[i]==1&& flag_one)
        {
            index_one[one]= (i+1);
            one++;
            if(one == num_teams)
                flag_one = false;
        }
        else if(sto[i]==2&& flag_two)
        {
             index_two[two]= (i+1);
             two++;
             if(two==num_teams)
                flag_two = false;
        }
        else if(sto[i]==3&& flag_three)
        {
            index_three[three]=(i+1);
            three++;
            if(three == num_teams)
                flag_three = false;
        }
        i++;
        // ****************cout << &index_three[8] << " "<< &index_one[0] <<endl;*******************
    }

    for(i=0; i< num_teams;i++)
    {
        printf("%d %d %d\n", index_one[i], index_two[i], index_three[i]);
    }
    }
}
