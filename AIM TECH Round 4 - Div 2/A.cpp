#include <bits/stdc++.h>

#define fastIO ios::sync_with_stdio(false);cout.tie(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair
#define MT make_tuple
#define inf INT_MAX
#define minf INT_MIN

typedef long long int lli;

using namespace std;

ofstream outfile;
ifstream infile;

int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	string s;
	int k;

	cin >> s >> k;

	int n= s.length();

	if(n < k){
		cout << "impossible\n";
		return 0;
	}

	bool letter[30];

	for(int i = 0; i < 26; ++i)
		letter[i] = 0;

	for(int i =0 ; i < n; ++i){
		letter[s[i]-'a'] = 1;
	}

	int sum = 0;
	for(int i = 0; i < 26; ++i){
		sum += letter[i];
	}

	if(k <= sum)
		cout << "0\n";
	else
		cout << k-sum << "\n";
}