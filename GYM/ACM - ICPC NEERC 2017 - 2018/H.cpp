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

int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");
	
	fastIO;
	lli n, i, t;
	vector <pair <lli, lli>> DPL, DPR;
	cin >> n;
	lli arr[n+1];
	DPL.resize(n+1);
	DPR.resize(n+1);

	for(i = 1; i <= n; ++i){
		cin >> arr[i];
	}

	DPL[1].fi = 0;
	DPL[1].se = arr[1];
	for(i = 2; i <= n; ++i){
		if(arr[i] > DPL[i-1].se){
			DPL[i].se = arr[i];
			DPL[i].fi = DPL[i-1].fi;
		}else{
			DPL[i].se = DPL[i-1].se+1;
			DPL[i].fi = DPL[i-1].fi + (DPL[i].se - arr[i]);
		}
	}

	DPR[n].se = arr[n];
	DPR[n].fi = 0;

	for(i = n-1; i >= 1; --i){
		if(arr[i] > DPR[i+1].se){
			DPR[i].se = arr[i];
			DPR[i].fi = DPR[i+1].fi;
		}else{
			DPR[i].se = DPR[i+1].se+1;
			DPR[i].fi = DPR[i+1].fi + (DPR[i].se - arr[i]);
		}
	}

	lli mini = 10000000000000000ll;

	for(i = 1; i <= n; ++i){

		if(DPL[i].se > DPR[i].se){
			mini = min(mini, DPL[i].fi+DPR[i+1].fi);
		}else{
			mini = min(mini, DPR[i].fi+DPL[i-1].fi);
		}
	}

	cout << mini << "\n";
}