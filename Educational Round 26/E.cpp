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

lli x, y, i, t;
vector <lli> xfactor;

lli func(lli x, lli y, lli val){
	if((!y))
		return val;



	lli mini = INT_MAX;
	t = __gcd(x, y);
	//cout << x << " "<< y << " "<< t << "\n";
	getchar();

	if(t == y)
		return val+1;
	if(t == x)
		return val+(y/x);

	for(i = 0; i < xfactor.size(); ++i){
		lli g = t * xfactor[i];

		if( !(x % g) ){
			mini = min(mini, (y-(y/g)*g)/t);
			//cout << xfactor[i] << " "<< mini << "\n";
		}
	}

	return func(x, y-mini*t, mini+val);
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");


	cin >> x >> y;
	for(i = 2; i <= sqrt(x)+1; ++i){
		if( !(x%i)){
			xfactor.pb(i);
			xfactor.pb(x/i);}
	}
	xfactor.pb(x);

	cout << func(x, y, 0)<< "\n";
}
