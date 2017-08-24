#include <bits/stdc++.h>
using namespace std;

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

ofstream outfile;
ifstream infile;

int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	string s;
	cin >> s;

	string fin;
	int i;
	bool flag = false;
	while(i < s.length()){
		
		if(s[i] == 'a'){
			fin += 'a';
			++i;
			continue;
		}
		while( i < s.length() && s[i] != 'a'){
			flag = true;
			fin += (char)(s[i]-1);
			++i;
		}
		while(i < s.length()){
			fin += s[i];
			++i;
		}
		break;
	}
	if(!flag){
		fin[i-1] = 'z';
	}
	cout << fin << "\n";
}