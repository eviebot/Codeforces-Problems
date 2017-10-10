#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
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

#define mod 998244353
#define MAXN 5100
lli x, y, gcd;
lli factorials[MAXN];

void create_table(){
	factorials[0] = 1;
	factorials[1] = 1;
	for(lli i = 2; i < MAXN; ++i){
		factorials[i] = (factorials[i-1]*i)%mod;
	}
}

void extended_euclid(lli a, lli b){
	if(!a){
		x = 0;
		y = 1;
		gcd = b;
		return ;
	}
	extended_euclid(b%a, a);

	lli x1 = y - (b/a)*x;
	lli y1 = x;
	x = x1;
	y = y1;
}
lli nPr(lli n, lli r){
	if(n < r || r < 0)
		return 0;
	lli p1 = factorials[n], p2 = (factorials[n-r])%mod;
	extended_euclid(p2, mod);
	x = (x%mod+mod)%mod;

	return (p1*x)%mod;
}
lli nCr(lli n, lli r){
	if(n < r || r < 0)
		return 0;
	lli p1 = factorials[n], p2 = (factorials[n-r]*factorials[r])%mod;
	extended_euclid(p2, mod);
	x = (x%mod+mod)%mod;

	return (p1*x)%mod;
}

lli solve(lli x, lli y){
	lli i =0, ans = 0;
	//cout << x << " "<< y << "\n";
	for(i = 0; i <= x; ++i){ 
		//cout << i << "\n";
		lli t = (nCr(x, i))%mod;
		t = (t*nPr(y, i))%mod;
		//cout << t << "\n";
		ans = (ans+t)%mod;
	}
	//cout << ans << "\n";
	return ans;
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");
	
	create_table();
	lli a, b, c, ans = 1;
	cin >> a >> b >> c;

	vector <lli> arr = {a, b, c};
	sort(arr.begin(), arr.end());

	ans = (ans*solve(arr[0], arr[1]))%mod;
	ans = (ans*solve(arr[0], arr[2]))%mod;
	ans = (ans*solve(arr[1], arr[2]))%mod;

	cout << ans << "\n";
}