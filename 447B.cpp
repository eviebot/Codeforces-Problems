#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define pb push_back

int main()
{
    string s;
    int k, i, t, sum =0, maxi = 0;
    char c='a';
    map <char, int> mymap;
    getline(cin , s);
    scanf("%d", &k);
    for(i= 0; i< 26;i++)
    {   scanf("%d", &t);
        mymap['a'+i]  =t;
        if(t>maxi)
            maxi = t;
    }
    for(i = 0; i< s.length();i++)
    {
        sum += (i+1)*mymap[s[i]];
    }
    int size_vec = s.length();

    sum =sum+ maxi*((k+size_vec)*(k+size_vec+1)/2 - (size_vec)*(size_vec+1)/2);
    cout << sum;

}
