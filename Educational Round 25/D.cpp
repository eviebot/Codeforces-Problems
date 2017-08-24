// HONESTLY I'M SO FUCKING STUPID
// HONESTLY I'M SO FUCKING STUPID
// HONESTLY I'M SO FUCKING STUPID
// HONESTLY I'M SO FUCKING STUPID
// HONESTLY I'M SO FUCKING STUPID
// HONESTLY I'M SO FUCKING STUPID
// HONESTLY I'M SO FUCKING STUPID
// HONESTLY I'M SO FUCKING STUPID
// HONESTLY I'M SO FUCKING STUPID
// HONESTLY I'M SO FUCKING STUPID
// HONESTLY I'M SO FUCKING STUPID
// HONESTLY I'M SO FUCKING STUPID
// HONESTLY I'M SO FUCKING STUPID
// HONESTLY I'M SO FUCKING STUPID
// HONESTLY I'M SO FUCKING STUPID
// HONESTLY I'M SO FUCKING STUPID
// HONESTLY I'M SO FUCKING STUPID
// HONESTLY I'M SO FUCKING STUPID
// HONESTLY I'M SO FUCKING STUPID
// HONESTLY I'M SO FUCKING STUPID
// HONESTLY I'M SO FUCKING STUPID
// HONESTLY I'M SO FUCKING STUPID
// HONESTLY I'M SO FUCKING STUPID
// HONESTLY I'M SO FUCKING STUPID
// HONESTLY I'M SO FUCKING STUPID
// HONESTLY I'M SO FUCKING STUPID
// HONESTLY I'M SO FUCKING STUPID
// HONESTLY I'M SO FUCKING STUPID
// HONESTLY I'M SO FUCKING STUPID
// HONESTLY I'M SO FUCKING STUPID
// HONESTLY I'M SO FUCKING STUPID
// HONESTLY I'M SO FUCKING STUPID
// HONESTLY I'M SO FUCKING STUPID
// HONESTLY I'M SO FUCKING STUPID
// HONESTLY I'M SO FUCKING STUPID
// HONESTLY I'M SO FUCKING STUPID
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

	int req[26], rem[26], tot[26], i, maxi = 0,j, k;
	bool flagg;
	vector <int> candi;
	char c, final[1000001];
	string s, t;
	bool flag[26];

	for(i = 0; i < 26; ++i)
	{
		req[i] = 0;
		rem[i] = 0;
		tot[i] = 0;
		flag[i] = 0;
	}
	cin >> s >> t;
	
	for(i = 0; i < t.size(); ++i)
	{
		flag[t[i]-'a'] = 1;
		++req[t[i]-'a'];
	}

	for(i = 0; i < s.size(); ++i)
	{
		if( s[i] != '?')
		{
			++tot[s[i]-'a'];
			final[i] = s[i];
		}
		else
		{
			candi.pb(i);
		}
	}

	for(i = 0; i < 26; ++i)
	{
		if( flag[i] )
		{
			rem[i] = tot[i]%req[i];
			tot[i] -= rem[i];
			rem[i] = req[i] - rem[i];
			maxi = max(maxi, tot[i]/req[i]);
		}
	}

	for(i = 0; i < candi.size();)
	{
		flagg = false;
		for(j = 0; j < 26 && (i < candi.size()); ++j)
		{
			if( flag[j] && tot[j]/req[j] < maxi)
			{
				flagg = true;
				final[candi[i]] = (char)(j+'a');
				++tot[j];
				++i;
			}
		}
		if( !flagg)
		{
			for(j = 0; j < 26 && (i < candi.size()); ++j)
			{
				while(rem[j] && (i < candi.size()))
				{
					--rem[j];
					final[candi[i]] = (char)(j+'a');
					++i;
				}
			}
			while( i < candi.size())
			{
				for(j = 0; j < 26 && (i < candi.size()); ++j)
				{
					for(k = 0; k < req[j] && (i < candi.size()); ++k)
					{
						final[candi[i]] = (char)(j+'a');
						++i;
					}
				}
			}
			break;
		}
	}
	
	for(i = 0; i < s.size(); ++i)
	{
		cout << final[i] ;
	}
	cout << "\n";
}