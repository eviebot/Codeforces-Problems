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

	fastIO;
	int n, i, t, req = 0;
	int used[210000];
	int arr[210000];
	bool flag[210000];
	cin >> n;
	
	for(i = 1; i <= n; ++i){
		flag[i] = 1;
		used[i] = 0;
	}
	for(i = 1; i <= n; ++i){
		cin >> arr[i];
		if(used[arr[i]]){
			++req;
		}
		++used[arr[i]];
	}
	int index = 1;
	cout << req << "\n";

	for(i = 1; i <= n; ++i){
		if(used[arr[i]] > 1){
			while(used[index])
				++index;
			if(flag[arr[i]]){
				if(arr[i] < index){
					cout << arr[i] << " ";
					flag[arr[i]] = 0;
				}else{
					cout << index++<< " ";
					used[arr[i]]--;
				}
			}else{
				cout << index++ << " ";
				used[arr[i]]--;
			}
		}else{
			cout << arr[i] << " ";
		}
	}
	cout << "\n";
}