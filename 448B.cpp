#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define pb push_back

bool automaton(string *smaller, string *larger)
{
    string s = *smaller, l = *larger;
    int small[26]={0}, large[26]={0}, i;
    for(i = 0; i< s.length();i++)
        small[s[i]-'a'] ++;
    for(i = 0; i< l.length();i++)
        large[l[i]-'a']++;
    for(i = 0 ; i< 26; i++)
    {
        if(small[i] > large[i])
            return false;
    }
    return true;
}
bool arr(string *smaller, string *larger)
{   string s = *smaller, l = *larger;
    int lens = s.length(), lenl = l.length(), j = 0;
    for(int i= 0; i< lenl;i++)
    {
        if(s[j]==l[i])
            j++;
    }
    if(j == lens)
        return true;
    else
        return false;

}
int main()
{
    string s, t;
    getline(cin, s );
    getline(cin, t );
    if(s.length() < t.length())
    {
        cout << "need tree";
    }
    else if(t.length() < s.length())
    {
        if(automaton(&t, &s))
        {
            if(arr(&t, &s))
                cout << "automaton";
            else
                cout << "both";
        }
        else
        {
            cout << "need tree";
        }
    }
    else
    {
        if(automaton(&s, &t))
        {
            cout << "array";
        }
        else
        {
            cout << "need tree";
        }
    }
}
