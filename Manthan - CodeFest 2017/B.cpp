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

lli arr[200000];

pair <lli, lli> findmin(lli start, lli end){
	if(start > end)
		return {0, -1};
	lli mini = 1000000000000ll, index;
	for(lli i = start; i <= end; ++i){
		if(arr[i] < mini){
			mini = arr[i];
			index = i;
		}
	}
	return MP(mini, index );
}
pair <lli, lli> findmax(lli start, lli end){
	if(start > end)
		return {0, -1};
	lli maxi = -1000000000000ll, index;
	for(lli i = start; i <= end; ++i){
		if(arr[i] > maxi){
			maxi= arr[i];
			index = i;
		}
	}
	return MP(maxi, index);
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	lli n, p, q, r;
	cin >> n >> p >> q >> r;
	
	lli t, i, j, k;
	for(i = 1; i <= n; ++i){
		cin >> arr[i];
	}
	lli maxi = -3000000000000000001ll;
	if(n <= 11){
		for(i = 1; i <= n; ++i){
			for(j = i; j <= n; ++j){
				for(k = j; k <= n; ++k){
					maxi = max(arr[i]*p+arr[j]*q+arr[k]*r, maxi);
					//cout << arr[i]*p+arr[j]*q+arr[k]*r << "\n";
				}
			}
		}
		cout << maxi << "\n";
		return 0;
	}

	maxi = -3000000000000000001ll;
	
	pair <lli , lli> temp1, temp2, temp3;
	temp1 = findmin(1, n);
	vector <pair <lli, lli>> fin;

	fin.pb(temp1);

	temp2 = findmin(1, temp1.se-1);

	if(temp2.se != -1){
		fin.pb(temp2);}

	temp3 = findmin(temp1.se+1, n);
	if(temp3.se != -1){
	fin.pb(temp3);}

	temp1 = findmax(1, n);

	fin.pb(temp1);

	temp2 = findmax(1, temp1.se-1);
	if(temp2.se != -1){
	fin.pb(temp2);}

	temp3 = findmax(temp1.se+1, n);

	if(temp3.se != -1){
	fin.pb(temp3);}


	for(i = 0; i < fin.size(); ++i){
		for(j = 0; j < fin.size(); ++j){
			for(k = 0; k < fin.size(); ++k){
				if(fin[i].se <= fin[j].se && fin[j].se <= fin[k].se){
					maxi = max(maxi, p*fin[i].fi+q*fin[j].fi+r*fin[k].fi);
				}
			}
		}
	}
	cout << maxi << "\n";
}