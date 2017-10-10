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
#define mod 1000000007
ofstream outfile;
ifstream infile;

lli n, k;
vector <vector <lli>> v1, v2;
vector <lli> temp;
unordered_map <lli, lli> s1, s2;


lli x, y, gcd;
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

lli inverse(lli c){
	extended_euclid(c, mod);

	lli ans = (x%mod+mod)%mod;
	//cout << c << " "<< x << " "<< ans << "\n";
	return ans;
}
void run1(int index, lli multi){
	if(index == n/2+1){
		s1[multi%mod]++;
		return ;
	}
	for(int i = 1; i <= 6; ++i){
		run1(index+1, (multi*v1[index][i])%mod);
	}
}

void run2(int index, lli multi){
	if(index == n+1){
		s2[multi%mod]++;
		return ;
	}
	for(int i = 1; i <= 6; ++i){
		run2(index+1, (multi*v2[index-n/2][i])%mod);
		//cout << index << " "<< multi*v2[index-n/2][i] << " "<< i << "\n";
	}
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	int test, i, j, t;
	temp.resize(7);
	
	cin >> test;
	for(int z =0; z < test; ++z){
		cin >> n >> k;
		lli sum = 0;
		if(n == 1){
			for(j = 1; j <= 6; ++j){
				cin >> t;
				if(t == k)
					++sum;
			}
			cout << sum << "\n";
			continue;
		}
		s1.clear();
		s2.clear();
		v1.resize(n/2+2);
		v2.resize(n/2+2);
		for(i = 1; i <= n/2; ++i){
			v1[i] = temp;
			for(j = 1; j <= 6; ++j){
				cin >> v1[i][j];
			}
		}
		run1(1, 1);

		for(i = n/2+1; i <= n; ++i){
			v2[i-n/2] = temp;
			for(j = 1; j <= 6; ++j){
				cin >> v2[i-n/2][j];
			}
		}
		run2(n/2+1, 1);
		for(auto it:s1){
			lli t = inverse(it.fi);
			sum += (it.se)*s2[(t*k)%mod];
			//cout << it << " "<< t << " "<< (t*k)%mod << " "<< s2.count((t*k)%mod) << "\n";
		}
		cout << sum << "\n";
	}
}