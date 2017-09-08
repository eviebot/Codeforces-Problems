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

bool coprime(int i, int j){
	if(__gcd(i, j) == 1)
		return true;
	return false;
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	int n, i, j, t1, t2;
	double x = 0;
	cin >> n;

	for(i = 1; i <= 1000; ++i){
		for(j = i+1; j <= 1000; ++j){
			if(i+j == n && coprime(i, j) && (double)(i)/j > x){
				x = (double)(i)/j;
				t1 = i;
				t2 = j;
			}
		}
	}
	cout << t1 << " "<< t2 << "\n";
}