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

int findP(string s){
	int n = s.size(), l, r;
	s = '#'+s;
	bool isPal[n+2][n+2];
    memset(isPal, false, sizeof(isPal)) ;
    for(int i=1 ; i<= n; i++) isPal[i][i]=true ;
    for(int len=2 ; len<=n ; len++)
    for(int i=1 ; i+len-1<=n ; i++)
    {
          l=i ; r=i+len-1 ;
          if(len==2) isPal[l][r]=(s[l]==s[r]) ;
          else isPal[l][r]=((s[l]==s[r])&&isPal[l+1][r-1]) ;
	}
	int t = 0, i, j;
	for(i = 1; i <= n; ++i){
		for( j = 1; j <= n; ++j){
			if(isPal[i][j])
				++t;
		}
	}
	return t;
}
int tree[310000][2], arr[310000];
void build_tree(int node, int start, int end){
	int mid = (start+end)/2, x1 = node*2, x2 = node*2+1;
	if(start == end){
		tree[node][0] = arr[start];
		tree[node][1] = start;
		return ;
	}
	build_tree(x1, start, mid);
	build_tree(x2, mid+1, end);
	if(tree[x1][0] > tree[x2][0]){
		tree[node][0] = tree[x1][0];
		tree[node][1] = tree[x1][1];
	}else if(tree[x1][0] == tree[x2][0] && tree[x1][1] < tree[x2][1]){
		tree[node][0] = tree[x1][0];
		tree[node][1] = tree[x1][1];
	}else{
		tree[node][0] = tree[x2][0];
		tree[node][1] = tree[x2][1];
	}
}
pair <int, int> query(int node, int start, int end, int l, int r){
	if(start > r || end < l)
		return MP(-1, -1);
	int mid = (start+end)/2, x1 = node*2, x2 = node*2+1;
	if(start >= l && end <= r){
		return MP(tree[node][0], tree[node][1]);
	}
	pair <int, int> t1 = query(x1, start, mid, l, r), t2 = query(x2, mid+1, end, l, r);
	if(t1.fi > t2.fi)
		return MP(t1.fi, t1.se);
	else if(t1.fi == t2.fi && t1.se < t2.se)
		return MP(t1.fi, t1.se);
	return MP(t2.fi, t2.se);
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	int test, n, q, i, j;
	string a, b, s;
	cin >> test;

	
	for(int z =0 ; z < test; ++z){

		cin >> n >> q;
		unordered_map <string, pair <int, int>> mapper;

		for(i = 1; i <= n; ++i){
			cin >> s;
			int t = findP(s);
			//cout << s << " "<< t << "\n";
			arr[i] = t;
			mapper.insert(MP(s, MP(t, i)));

		}
		build_tree(1, 1, n);
		for(i = 1; i <= q; ++i){
			cin >> a >> b;
			int l = mapper[a].se, r = mapper[b].se;
			//cout << l << " "<< r << "\n";
			if(l > r){
				int temp = r;
				r = l;
				l = temp;
			}
			pair <int, int> kkk =query(1, 1, n, l, r);

			cout << kkk.se << "\n";
		}
	}
}