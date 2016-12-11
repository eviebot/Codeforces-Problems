#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define pb push_back

int main()
{
    string s;
    int k = 0;
    map <char, bool > mymap;
    getline(cin , s);
    for(int i = 0; i< s.length();i++)
    {
        if(!mymap[s[i]]){k++;mymap[s[i]]=true;}
        else{k--;mymap[s[i]]=false;}
    }
    if(k==0||k%2==1)
        cout << "First";
    else
        cout << "Second";
}
