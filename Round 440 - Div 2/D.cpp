#include <bits/stdc++.h>


#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define fastIO ios::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
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

int n;
int built[5001][5001], b0[5001], p0[5001], b[5001], p[5001], ans[5001];

bool checker(){
	for(int i = 0; i < n; ++i){
		if(p[b[i]] != i)
			return false;
	}
	return true;
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	int i, j, t;
	cin >> n;
	for(i = 0; i < n; ++i){
		cout << "? "<< i << " 0"<< "\n";
		fflush(stdout);
		cin >> b0[i];
	}
	p0[0] = b0[0];
	for(i = 1; i < n; ++i){
		cout << "? 0 "<< i << "\n";
		fflush(stdout);
		cin >> p0[i];
	}

	for(i = 0; i < n; ++i){
		for(j = 0; j < n; ++j){
			built[i][j] = b0[i]^p0[0]^p0[j];
		}
	}

	int sum = 0;
	for(i = 0; i < n; ++i){
		b[0] = i;
		for(j = 0; j < n; ++j)
			p[j] = built[j][0]^b[0];
		for(j = 0; j < n; ++j)
			b[j] = built[0][j]^p[0];
		
		if(checker()){
			++sum;
			for(j= 0; j < n; ++j)
				ans[j] = p[j];
		}
	}

	cout << "! "<< sum << "\n";
	for(i = 0; i <n; ++i)
		cout << ans[i] << ' ';
	cout << '\n';
	fflush(stdout);
}