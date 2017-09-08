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


vector <vector <int>> ans;
vector <int> builder;
int n, i, t;

bool visited[200000];
vector <pair <int, int>> data;

void find_cycle(int root){
	if(visited[root])
	{
		ans.pb(builder);
		builder.clear();
		return ;
	}

	visited[root] = 1;
	builder.pb(root);
	find_cycle( data[root].se );
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	cin >> n;

	data.pb({minf, 0});
	for(i = 1; i <= n; ++i){
		cin >> t;
		visited[i] = 0;
		data.pb( MP(t, i));
	}

	sort(data.begin(), data.end());

	for(i = 1; i <= n; ++i){
		if(!visited[i]){
			find_cycle(i);
		}
	}
	cout << ans.size() << "\n";
	for(i = 0; i < ans.size(); ++i){

		cout << ans[i].size() << " ";
		for(int j = 0; j < ans[i].size(); ++j)
			cout << ans[i][j] << " ";
		cout << "\n";
	}

}