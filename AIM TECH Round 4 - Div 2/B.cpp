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

lli pee(lli x, lli t){
	lli m = 1;
	for(int i = 0; i < t; ++i)
	{
		m *= 2;
	}
	return m;
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	lli n, m, sum = 0, i, j;
	bool matrix[60][60];
	cin >> n >> m;

	for(i = 1; i <= n; ++i){
		for(j = 1; j <= m; ++j){
			cin >> matrix[i][j];
		}
	}

	for(i = 1; i <= n; ++i){
		lli tb= 0, tw = 0;
		for(j = 1; j <= m; ++j){
			if(matrix[i][j])
				++tb;
			else
				++tw;
		}
		lli t1 = pow(2, tb), t2 = pow(2, tw);
		sum += (lli)pow(2, tb) - 1;
		sum += (lli)pow(2, tw) - 1;

		//cout << sum << "\n";
	}

	for(j = 1; j <= m; ++j){
		lli tb = 0, tw = 0;

		for(i= 1; i <= n; ++i){
			if(matrix[i][j])
				++tb;
			else
				++tw;
		}
		lli t1 = pow(2, tb), t2 = pow(2, tw);
		sum +=  (lli)pow(2, tb) - 1 - tb;
		sum +=  (lli)pow(2, tw)- 1 - tw;

		//cout << sum << "\n";
	}

	cout << sum << "\n";
}