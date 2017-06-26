#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair

typedef long long int lli;
ofstream outfile;
ifstream infile;

int main()
{
    infile.open("input.txt");
    outfile.open("output.txt");

    //ios::sync_with_stdio(false);cout.tie(0);cin.tie(0);

    string s;
    cin >> s;

    int hour = (s[0]-'0')*10+ (s[1]-'0'), minute = (s[3]-'0')*10 + (s[4]-'0');

    //cout << hour << ' ' << minute << '\n';

    if(!hour && !minute)
        cout << 0;
    else if( hour < 1 || (hour == 1 && minute <= 10))
    {
        cout << (1-hour)*60 + (10-minute);
    }
    else if(hour < 2 || (hour ==2 &&minute <= 20))
    {
        cout << (2-hour)*60 + (20-minute);
    }
    else if(hour < 3 || (hour == 3 && minute <= 30))
    {
        cout << (3-hour)*60 + (30-minute);
    }
    else if(hour < 4 || (hour == 4&& minute <= 40))
    {
        cout << (4-hour)*60 + (40-minute);
    }
    else if(hour < 5 || (hour == 5 && minute <= 50))
    {
        cout << (5-hour)*60 + (50-minute);
    }
    else if(hour < 10 || (hour == 10 && minute <= 1))
    {
        cout << (10-hour)*60 + (1-minute);
    }
    else if(hour < 11|| (hour == 11 && minute <= 11))
    {
        cout << (11-hour)*60 + (11-minute);
    }
    else if(hour < 12 || (hour == 12 && minute <= 21))
    {
        cout << (12-hour)*60 + (21-minute);
    }
    else if(hour < 13|| (hour == 13 && minute <= 31))
    {
        cout << (13-hour)*60 + (31-minute);
    }
    else if(hour < 14|| (hour == 14 && minute <= 41))
    {
        cout << (14-hour)*60 + (41-minute);
    }
    else if(hour < 15|| (hour == 15 && minute <= 51))
    {
        cout << (15-hour)*60 + (51-minute);
    }
    else if(hour < 20|| (hour == 20 && minute <= 2))
    {
        cout << (20-hour)*60 + (2-minute);
    }
    else if(hour < 21|| (hour == 21 && minute <= 12))
    {
        cout << (21-hour)*60 + (12-minute);
    }
    else if(hour < 22|| (hour == 22 && minute <= 22))
    {
        cout << (22-hour)*60 + (22-minute);
    }
    else if(hour < 23|| (hour == 23 && minute <= 32))
    {
        cout << (23-hour)*60 + (32-minute);
    }
    else
    {
        cout << 60-minute;
    }


}
