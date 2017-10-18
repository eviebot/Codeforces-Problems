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

int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO
	int n, k, t, i, maxi = INT_MIN, mini = INT_MAX;
	cin >> n >> k;
	if(k >= 3){
		for(i = 1; i <= n; ++i){
			cin >> t;
			maxi = max(maxi, t);
		}
		cout << maxi << "\n";
		return 0;
	}
	if(k == 1){
		for(i = 1; i <= n; ++i){
			cin >> t;
			mini= min(mini, t);
		}
		cout << mini << "\n";
		return 0;
	}

	int arr[100010];
	for(i =1 ; i <= n; ++i){
		cin >> arr[i];
	}
	multiset <int> set1, set2;
	set1.insert(arr[1]);

	for(i = 2; i <= n; ++i){
		set2.insert(arr[i]);
	}

	multiset <int>::iterator it1, it2;
	it1 = set1.begin();it2 = set2.begin();
	maxi = max(*it1, *it2);
	//cout << *it1 << " "<< *it2 << " "<< maxi << "\n";

	for(i = 2; i < n; ++i){
		set2.erase(set2.find(arr[i]));
		set1.insert(arr[i]);
		it1 = set1.begin();
		it2 = set2.begin();
		maxi = max(maxi, max(*it1, *it2));
	}
	cout << maxi << "\n";
}