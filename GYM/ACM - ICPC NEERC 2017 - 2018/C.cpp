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

lli n, k;
string s1, s2;

int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	cin >> n >> k;
	lli i, j;
	
	lli t = n*(n-1)/2;
	if(k > t){
		cout << "Impossible\n";
		return 0;
	}
	i = n;
	while(i){
		if(t - (i-1) < k){
			break;
		}
		t -= (i-1);
		--i;
		s1 += "()";
	}
	if(!i){
		cout << s1 << "\n";
		return 0;
	}
	t = k - (t - (i-1));

	for(j = 1; j <= t; ++j){
		s2 += "(";
	}
	s2 += "()";
	for(j = t+1; j < i; ++j){
		s2 += "(";
	}
	for(j = 1; j < i; ++j){
		s2 += ")";
	}
	cout << s1 << s2 << "\n";
}