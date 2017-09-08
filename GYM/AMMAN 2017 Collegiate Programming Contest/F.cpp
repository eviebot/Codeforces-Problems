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

#define maxn 100010
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	fastIO;
	int test, n, k, i, t, arr[maxn], next[maxn];
	memset(arr, 0, maxn);
	cin >> test;

	for(int z =0; z < test; ++z){
		int sum = 0;
		cin >> n >> k;
		for(i = 1; i <= n; ++i)
			cin >> arr[i];
		unordered_map <int, int> matcher;
		unordered_map <int, int>::iterator iter;
		unordered_map <int, bool> used;
		unordered_map <int, int> storage;
		for(i= n; i >= 1; --i){
			iter = matcher.find(arr[i]);
			if(iter != matcher.end()){
				next[i] = iter->se;
				iter->se = i;
			}else{
				next[i] = INT_MAX;
				matcher.insert(MP(arr[i], i));
			}
		}
		set <pair <int, int>> myq;
		set <pair <int, int>>::iterator tit;
		for(i = 1; i <= n; ++i){
			if(!used[arr[i]]){
				if(myq.size() == k){
					tit = myq.end();
					advance(tit, -1);
					myq.erase(tit);
					used[tit->se] = 0;
				}
				++sum;
				//cout << sum << "\n";
			}else{
				tit = myq.find(MP(storage[arr[i]], arr[i]));
				myq.erase(tit);
			}
			myq.insert(MP(next[i], arr[i]));
			//cout << next[i] << " "<< arr[i] << "\n";
			storage[arr[i]] = next[i];
			used[arr[i]] = 1;
		}
		cout << sum << "\n";
	}
}