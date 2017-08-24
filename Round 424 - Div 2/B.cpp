#include <bits/stdc++.h>
using namespace std;

#define fastIO ios::sync_with_stdio(false);cout.tie(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair
#define inf INT_MAX
#define minf INT_MIN

typedef long long int lli;

ofstream outfile;
ifstream infile;

int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	string first, second, s;
	char c;
	cin >> first >> second >> s;

	int matcher[26], i, t;

	for(i = 0; i < 26; ++i)
	{
		matcher[first[i]-'a'] = second[i]-'a';
	}

	for(i = 0; i < s.size(); ++i)
	{
		c = s[i];
		if( (c >= 'a' && c <= 'z'))
		{
			t = (int)(c-'a');
			cout << (char)( matcher[t]+'a' );
		}
		else if( (c >= 'A' &&  c<= 'Z'))
		{
			t = (int)(c+32-'a');
			cout << (char)(matcher[t]+'a'-32);
		}
		else
		{
			cout << (char)(c);
		}
	}
	cout << "\n";
}