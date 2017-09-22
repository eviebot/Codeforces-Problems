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

lli checker(lli builder, lli n){
	lli ans = builder*2;
	while(n - builder >= 0){
		ans += 2;
		n-= builder;
	}
	if(n)
		ans +=2;
	return ans;
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	lli n, t;
	cin >> n;
	t = sqrt(n);

	lli mini = checker(t, n);
	mini = min(mini, checker(t+1, n));

	cout << mini << "\n";
}