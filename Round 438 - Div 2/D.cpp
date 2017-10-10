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

lli fastexp(lli x, lli y){		// find (x^y)%mod
	lli res = 1;
	while(y){
		if(y&1) 
			res = (res*x);
		y = y>>1;
		x = (x*x);
	}
	return res;
}
string s;
int ax;
bool indexx[2000];
bool check(int x){
	//cout << "\n" << x << "\n";
	int siz = fastexp(2, x), i,ans = 0, multi = fastexp(2, x-1);
	for(i = 0; i < siz; ++i)
		indexx[i] = 0;
	for(i = s.size()-x; i < s.size(); ++i)
		ans = ans*2 + (s[i]-'0');
	indexx[ans] = 1;
	
	//cout << ans << "\n";
	for(i = s.size()-x-1; i >= 0; --i){
		ans /= 2;
		ans += (s[i]-'0')*multi;
		//cout << ans << "\n";
		indexx[ans] = 1;
	}
	for(i = 0; i < siz; ++i){
		if(!indexx[i]){
			//cout << i << "s\n";
			return false;
		}
	}
	return true;
}

void checker(){
	for(int k = 1; k <= 10; ++k){
		if(!check(k)){
			cout << k-1 << "\n";
			break;
		}
	}
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO
	int n, i, j, m, a, b;
	
	vector <string> arr;
	arr.resize(300);

	cin >> n;
	for(i = 1; i <= n; ++i){
		cin >> arr[i];
	}
	cin >> m;
	for(j = 1; j <= m; ++j){
		
		cin >> a >> b;
		s = arr[a] + arr[b];
		
		if(s.size() > 5000){
			s = s.substr(0, 1000)+s.substr(s.size()-1000, 1000);
		}
		arr[n+j] = s;
		
		checker();
	}
}