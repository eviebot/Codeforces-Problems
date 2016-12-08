#include <bits/stdc++.h>
#include <time.h>
using namespace std;
#define endl "\n"

bool checker(char *y)
{   char x = *y;
    if(x == '2' || x == '4' || x== '6' || x=='8' || x=='0')
        return true;
    else
        return false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    char c;
    bool flag_1 = false, flag_2 = false;
    cin >> s;
    unsigned int len= s.length(), j,i;
    for(i = 0; i< s.length(); i++)
    {
        if(checker(&s[i]))
        {
            flag_1 = true;
            j = i;
            if(s[i] < s[len-1])
            {
                c = s[i];
                s[i] = s[len-1];
                s[len-1] = c;
                flag_2 = true;
                break;
            }
        }

    }
    if(flag_1 && !flag_2)
    {
        c = s[j];
        s[j] = s[len-1];
        s[len-1] = c;
    }
    if(flag_1)
        cout << s;
    else
        cout << "-1";

}
