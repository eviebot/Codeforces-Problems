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
#define mod 1000000007
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	int test, n, i, t;

	cin >> test;
	for(int z =0 ; z < test; ++z){
		cin >> n;
		multiset <int> myset;
		multiset <int>::iterator iter1, iter2;
		vector <int> arr;
		arr.resize(n+1);
		for(i = 0; i < n; ++i){
			cin >> arr[i];
			myset.insert(arr[i]);
		}

		for(i = 0; i < n; ++i){
			t = arr[i];
			myset.erase(myset.find(t));
			iter1 =myset.end();
			iter1--;

			int maxi = (t + *iter1)%mod;

			iter2 = myset.lower_bound(mod - t);
			if(iter2 != myset.begin())
				iter2--;
			maxi = max(maxi, (t+*iter2)%mod);
			cout << maxi << " ";
			myset.insert(t);
		}
		cout << "\n";
	}
}