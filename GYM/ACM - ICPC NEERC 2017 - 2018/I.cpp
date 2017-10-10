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

bool visited[300][300];
lli sum[300][300];
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	int n, m, i, j, p, q;
	cin >> n >> m >> q >> p;
	string s;
	vector <tuple <int, int, int>> contender;
	memset(sum, 0 sizeof(sum));
	for(i = 1 ; i <= n; ++i){
		cin >> s;
		for(j = 1; j <= m; ++j){
			if(s[j-1] == '*'){
				sum[i][j] = -1;
			}else{

			}
		}
	}