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
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	vector <pair <int, int>> generator, constructor;
	vector <int> orig, origc;
	int n, t, i;
	lli sumg = 0, sumc = 0, sumgt =0 , sumct = 0, temp;

	cin >> n;
	bool flags[n+1];
	generator.pb(MP(0, 0));
	constructor.pb(MP(0, 0));
	orig.pb(0);
	origc.pb(0);
	for(i = 1; i <= n; ++i){
		cin >> t;
		flags[i] = 0;
		generator.pb(MP(t, i));
		orig.pb(t);
		sumgt += t;
	}
	for(i = 1; i <= n; ++i){
		cin >> t;
		constructor.pb(MP(t, i));
		sumct += t;
		origc.pb(t);
	}


	sort(generator.begin(), generator.end());

	int k = (n/2)+1;

	for(i = n; i > n-k; --i){
		sumg += (lli)(generator[i].fi);

		sumc += (lli)(constructor[generator[i].se].fi);
		flags[generator[i].se] = 1;
	}

	sort(constructor.begin(), constructor.end());

	if(2 * sumc > sumct){

		cout << k << "\n";
		for(i = 1; i <= n; ++i){
			if(flags[i])
				cout << i << " ";
		}
		cout << "\n";
		return 0;
	}

	
	int indexs = n-k+1, indexb = n+1;
	while(!(2 * sumc > sumct)){

		for(i = indexb-1; ; --i){
			if(!flags[constructor[i].se]){
				indexb = i;
				break;
			}
		}

		//cout << indexs << " "<< constructor[indexb].se << "\n";
		
		temp = orig[constructor[indexb].se]-generator[indexs].fi;

		if( 2*(sumg+temp) > sumgt){
			sumg += temp;
			sumc += constructor[indexb].fi;
			sumc -= origc[generator[indexs].se];

			flags[constructor[indexb].se] = 1;
			flags[generator[indexs].se] = 0;
			++indexs;
		}
	}
	cout << k << "\n";
	for(i = 1; i <= n; ++i){
		if(flags[i])
			cout << i << " ";
	}
	cout << "\n";
	//cout << sumg << " "<< sumc << "\n";
}