#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s, out="";
    unsigned int i;
    bool flag = false;
    getline(cin, s);
    for(i=0;i<s.length();i++)
    {
        if(s.substr(i, 3)!="WUB")
        {
            out += s[i];
            flag = true;
        }
        else
        {   i+=2;
            if(flag)
                out+=" ";

        }

    }

    cout << out;

}
