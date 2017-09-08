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

int test, n, as, ae;
int counter[300][10], dist[300];
bool graph[300][300], visited[300];
string s;
void bfs(){
	queue <int> myq;
	myq.push(as);
	visited[as] = 1;
	dist[as] =0;
	int temp, j;
	while(!myq.empty()){
		temp = myq.front();
		myq.pop();
		if(temp == ae)
			return ;
		for(j= 1; j <= n; ++j){
			if(!visited[j] && graph[temp][j]){
				visited[j] = 1;
				myq.push(j);
				dist[j] = dist[temp]+1;
			}
		}
	}
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	int i, j;
	cin >> test;

	for(int z = 0; z < test; ++z){

		for(i = 1; i <= 250; ++i){
			for(j = 1; j <= 250; ++j){
				graph[i][j] = 0;
			}
			for(j = 0; j < 10; ++j)
				counter[i][j] = 0;
			dist[i] = -1;
			visited[i] = 0;
		}

		cin >> n >> as >> ae;
		for(i = 1; i <= n; ++i){
			cin >> s;
			for(j = 0; j < 20; ++j){
				counter[i][s[j]-'0']++;
			}
		}

		for(i = 1; i <= n; ++i){
			for(j = i+1; j <=n; ++j){
				int sum =0 ;
				for(int k = 0; k < 10; ++k){
					sum += min(counter[i][k], counter[j][k]);
				}
				if(sum == 17){
					graph[i][j] = 1;
					graph[j][i] = 1;
				}
			}
		}
		bfs();
		
		cout << dist[ae] << "\n";
	}
}