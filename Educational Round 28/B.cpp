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

lli n, k;
vector <lli> timet;
int checker(int start, lli m){
	int multi = n-start;
	int i = 0, res = 0;
	while(true){
		//cout << timet[i]*multi <<  " "<< m <<" "<< res<< "\n";
		if(timet[i] * multi <= m){
			m -= timet[i]*multi;
			res += multi;

			++i;
		}else{
			return res+(m/timet[i]);
		}

		
	}
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	lli m, i, t, maxi = 0, tsum = 0, tm, j, sum;
	
	fastIO;
	cin >> n >> k >> m;
	tm = m;
	timet.resize(k);

	for(i = 0; i < k; ++i){
		cin >> timet[i];
		tsum += timet[i];
	}
	if(tsum * n <= m){
		cout << (k+1)*n << "\n";
		return 0;
	}
	sort(timet.begin(), timet.end());

	maxi = checker(0, m);
	for(i = 0; i < n; ++i){
		if(m >= tsum){
			sum = (k+1)*(i+1);
			m -= tsum;
			
			sum += checker(i+1, m);
			
			maxi = max(maxi, sum);
		}else
			break;
	}
	cout << maxi << "\n";
}