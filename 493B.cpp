#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define pb push_back

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n, i, t;
    long long int sum_pos=0, sum_neg=0;
    bool neg_flag;
    scanf("%d", &n);
    vector <int> vec_pos;
    vector <int> vec_neg;
    for(i=0;i<n;i++)
    {
        scanf("%d", &t);
        if(t<0){
            vec_neg.pb(abs(t));sum_neg+=abs(t);}
        else{
            vec_pos.pb(t);sum_pos+=t;}
        if(i==n-1 && t<0)
            neg_flag = true;
        else
            neg_flag = false;
    }
    if(sum_pos > sum_neg){cout << "first";return 0;}
    else if(sum_pos < sum_neg){cout << "second";return 0;}
    else{
    for(i = 0; i< min(vec_pos.size(), vec_neg.size());i++)
    {
        if(vec_pos[i]>vec_neg[i]){
            cout << "first";return 0;}
        else if(vec_pos[i] < vec_neg[i]){
            cout << "second";return 0;}
    }
    if(vec_pos.size()>vec_neg.size())
    {
        cout << "first";return 0;
    }
    else if(vec_pos.size()< vec_neg.size())
    {
        cout << "second";return 0;
    }
    else
    {
        cout << (neg_flag?"second":"first");
    }}
    return 0;
}
