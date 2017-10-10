#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define fastIO ios::sync_with_stdio(false);cout.tie(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair
#define inf INT_MAX
#define minf INT_MIN
#define MT make_tuple

typedef long long int lli;

ofstream outfile;
ifstream infile;

int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	int n, m, l, r, i, j, siz, arr[100010], ans[100010];
	unordered_map <int, int> mapper;
	unordered_map <int, int>::iterator iter;
	vector <tuple <int, int, int, int>> queries;
	cin >> n >> m;
	for(i = 1; i <= n; ++i)
		cin >> arr[i];
	siz = sqrt(n);

	for(i = 1; i <= m; ++i){
		cin >> l >> r;
		queries.pb(MT(l/siz, r, l, i));
	}

	sort(queries.begin(), queries.end());
	int start = 1, end = 1, count = 0;
	if(arr[start] == 1)
		count = 1;
	mapper[arr[start]]++;
	for(i = 0; i < m; ++i){
		l = get<2>(queries[i]);
		r = get<1>(queries[i]);
		//cout << l << " "<< r << "\n";
		while(end < r){
			end++;
			iter = mapper.find(arr[end]);
			if(iter == mapper.end())
				mapper.insert(MP(arr[end], 1));
			else
				iter->se++;
			iter = mapper.find(arr[end]);
			if(iter->fi == iter->se)
				++count;
			if(iter->se == iter->fi+1)
				--count;
		}
		while(end > r){
			iter = mapper.find(arr[end]);
			if(iter->fi == iter->se)
				--count;
			if(iter->se == iter->fi+1)
				++count;
			iter->se--;
			--end;
		}
		while(start < l){
			iter = mapper.find(arr[start]);
			if(iter->fi == iter->se)
				--count;
			if(iter->se == iter->fi+1)
				++count;
			iter->se--;
			start++;
		}
		while(start > l){
			start--;
			iter = mapper.find(arr[start]);
			if(iter == mapper.end())
				mapper.insert(MP(arr[start], 1));
			else
				iter->se++;
			iter = mapper.find(arr[start]);
			if(iter->se == iter->fi)
				++count;
			if(iter->se == iter->fi+1)
				--count;
		}
		ans[get<3>(queries[i])] = count;
		//cout << start << " "<< end << " "<< count << "\n";
	}

	for(i = 1; i <= m; ++i)
		cout << ans[i] << "\n";
}