


#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define pb push_back

int main()
{
    
    int n, i, sum = 1, out = 1, t1, t2, t11, t22;
    bool left_flag =true, right_flag = true;
    vector <int> vec;
    scanf("%d", &n);
    int h[n];
    if(n==1){cout << "1";return 0;}
    scanf("%d %d", &h[0], &h[1]);

    for(i = 2; i< n;i++)
    {
        scanf("%d", &h[i]);
        if(h[i-1]>h[i] && h[i-1] >= h[i-1])
            vec.pb(i-1);
    }

    for(i = 1;i<n;i++)
    {
        if(h[i]> h[i-1])
            break;
        sum ++;
    }
    out = max(out, sum);sum=1;

   // for(i=0;i<vec.size();i++)
       // cout << vec[i]<<"\n";
    for(i=n-2;i>=0;i--)
    {
        if(h[i]>h[i+1])
            break;
        sum++;
    }
    out = max(out, sum);sum=1;

    for(i = 0;i<vec.size();i++)
    {
        t1 = vec[i];
        t2 = vec[i];
        while(true)
        {
            t11 = h[t1];
            t22=h[t2];
            if(left_flag &&t1==0){
                left_flag = false;}
            if(right_flag && t2 == (n-1))
                right_flag = false;
            if(left_flag && h[t1-1] > t11 )
                left_flag = false;
            if(right_flag && h[t2+1] > t22)
                right_flag = false;
            if(!left_flag && !right_flag)
            {   //cout << "sum="<<sum << "\n";
                out = max(out, sum);
                sum = 1;
                left_flag = true;
                right_flag = true;
                break;
            }
            sum += left_flag+right_flag;t1--;t2++;
        }
    }
    cout << out;
}

//WHAT IS GOING ON