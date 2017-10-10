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
int n, L[110][2];
void print(){
	for(int i = 1; i <= n; ++i){
		cout << L[i][0] << " "<< L[i][1] << "\n";
	}
}
int follow(int root){
	if(!L[root][1])
		return root;
	return follow(L[root][1]);
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	int i;
	cin >> n;
	for(i = 1; i <= n; ++i){
		cin >> L[i][0] >> L[i][1];
	}

	vector <pair <int, int>> linker;
	for(i = 1; i <= n; ++i){
		if(!L[i][0]){
			int t = follow(i);
			linker.pb(MP(i, t));
		}
	}

	if(linker.size() == 1){
		print();
		return 0;
	}
	L[linker[0].se][1] = linker[1].fi;
	int t = linker.size();
	for(i = 1; i < t-1; ++i){
		L[linker[i].se][1] = linker[i+1].fi;
		L[linker[i].fi][0] = linker[i-1].se;
	}
	L[linker[t-1].fi][0] = linker[t-2].se;

	print();
}