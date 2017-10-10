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
vector <vector <int>> graph;
unordered_map <string, int> mymap;

int dfs(int node, int par){
	int maxi = 0;
	for(auto it:graph[node]){
		if(it == par)
			continue;
		maxi = max(maxi, dfs(it, node));
	}
	return maxi+1;
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO
	int n, i, c =0;
	string s1, s2, s3;
	cin >> n ;

	graph.resize(300);
	for(i = 1; i <= n; ++i){
		cin >> s1 >> s2 >> s3;
		for(int j= 0; j < s1.size(); ++j){
			if(s1[j] < 'a')
				s1[j] += 32;
		}
		for(int j=0; j < s3.size(); ++j){
			if(s3[j] < 'a')
				s3[j] += 32;
		}
		if(mymap.find(s3) == mymap.end())
			mymap.insert(MP(s3, ++c));
		if(mymap.find(s1) == mymap.end())
			mymap.insert(MP(s1, ++c));

		graph[mymap[s1]].pb(mymap[s3]);
		graph[mymap[s3]].pb(mymap[s1]);
	}
	
	cout << dfs(1, 0) << "\n";
}