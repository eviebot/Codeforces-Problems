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
int k;
void adder(int x, char add){
	int i, t;
	for(i = 1; ; ++i){
		t = (i*(i-1))/2;
		if(t > x){
			i--;
			break;
		}
	}
	t = (i *(i-1))/2;
	k -= t;
	for(int j = 1; j <= i; ++j)
		s += add;
	return ;
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	int i;
	char cur = 'a';

	cin >> k;
	if(k == 0){
		cout << "a\n";
		return 0;
	}

	while(k){
		adder(k, cur);
		++cur;
	}

	cout << s << "\n";
}