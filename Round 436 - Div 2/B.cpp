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
string s;
int checker(int start){
	int sum = 0;
	set <char> myset;
	set <char>::iterator iter;
	for(int j = start; j < s.size(); ++j){
		if(s[j] < 'a')
			return sum;
		else{
			iter = myset.find(s[j]);
			if(iter == myset.end()){
				++sum;
				myset.insert(s[j]);
			}
		}
	}
	return sum;
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	
	int n, i, maxi = 0;
	cin >> n >> s;
	for(i = 0; i < n; ++i){
		maxi = max(maxi, checker(i));
	}

	cout << maxi << "\n";
}