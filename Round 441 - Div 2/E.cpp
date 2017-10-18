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
#define clr(ar) memset(ar, 0, sizeof(ar));

typedef long long int lli;

using namespace std;

ofstream outfile;
ifstream infile;
bool vis[100010];
int n, m, type[100010];
set <int> ans;
vector <vector <int>> listt, graph;
bool dfs(int root){
	if(type[root] == -1)
		return false;
	if(type[root] == 1)
		ans.insert(root);
	if(vis[root])
		return true;
	vis[root] = true;
	bool f = true;
	for(auto it:graph[root]){
		f = f & dfs(it);
	}
	return f;
}

int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	int i, l, t, j;
	

	cin >> n >> m;
	listt.resize(n+1);
	graph.resize(n+1);
	clr(type);
	clr(vis);

	for(i = 1; i <= n; ++i){
		cin >> l;
		listt[i].pb(l);
		for(j =0 ; j < l; ++j){
			cin >> t;
			listt[i].pb(t);
		}
	}

	for(i = 1; i < n; ++i){
		bool flag = true;
		for(j = 1; j <= min(listt[i][0], listt[i+1][0]) && flag; ++j){
			if(listt[i][j] < listt[i+1][j]){
				flag = false;
				graph[listt[i+1][j]].pb(listt[i][j]);
			}else if(listt[i][j] > listt[i+1][j]){
				type[listt[i][j]] = 1;
				type[listt[i+1][j]] = -1;
				flag = false;
			}
		}
		if(flag){
			if(listt[i][0] > listt[i+1][0]){
				cout << "No\n";
				return 0;
			}
		}
	}

	for(i = 1; i <= m; ++i){
		if(type[i] == 1){
			if(!dfs(i)){
				cout << "No\n";
				return 0;
			}
		}
	}

	cout << "Yes\n";
	cout << ans.size() << "\n";
	for(auto it:ans)
		cout << it << " ";
	cout << '\n';
}