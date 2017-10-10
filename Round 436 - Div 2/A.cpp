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

int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	int n, i, t, arr[200] = {0};
	for(i = 1;i <= 100; ++i)
		arr[i] = 0;
	cin >> n;
	for(i = 1; i <= n; ++i){
		cin >> t;
		arr[t]++;
	}

	int c = 0;
	for(i = 1; i <= 100; ++i){
		if(arr[i])
			++c;
	}
	if(c != 2){
		cout << "NO\n";
		return 0;
	}
	int val = 0;
	for(i = 1; i <= 100; ++i){
		if(val){
			if(arr[i] && arr[i] != val){
				//cout << arr[i] << " "<< val << "\n";
				cout << "NO\n";
				return 0;
			}
		}else{
			if(arr[i]){
				val = arr[i];
			}
		}
	}
	cout << "YES\n";
	for(i = 1; i <= 100; ++i){
		if(arr[i]){
			cout << i << " ";
		}
	}
	cout << "\n";
}