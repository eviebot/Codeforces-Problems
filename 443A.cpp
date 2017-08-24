#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    unsigned int j, i, sum=0;
    getline(cin , s);
    bool flags[26]={false};
    for(i = 1; i<s.length();i+=3)
    {
        j = int(s[i])-97;
        if(!flags[j])
            flags[j] = true;

    }
    for(i = 0; i< 26; i++)
    {
        sum += flags[i];
        //cout << flags[i] << endl;
    }
    cout << sum;
}
