#include <bits/stdc++.h>
using namespace std;

#define fastIO ios::sync_with_stdio(false);cout.tie(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair
#define inf INT_MAX
#define minf INT_MIN

typedef long long int lli;

ofstream outfile;
ifstream infile;

int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	int n, i, size, j, value[100], sum[100], sumbob= 0, sumalice = 0;
	sum[0] = 0;

	cin >> n;
	for(i = 1; i <= n; ++i){
		cin >> value[i];
		sum[i] = sum[i-1] + value[i];
	}

	int start = 0;
	bool flag = 1;
	while(start < n){
		cout << start << "\n";
		for(i = n; i > start; --i){
			if(value[i] > sum[i-1] - sum[start]){
				cout << value[i] << " "<< sum[i-1] - sum[start] << "\n";
				if(flag){
					sumbob += value[i];
					sumalice += sum[i-1] - sum[start];
				}else{
					sumalice += value[i];
					sumbob += sum[i-1] - sum[start];
				}
				flag = !flag;
				start = i+1;
				break;
			}
		}
	}
	if(start == n){
		if(flag){
			sumbob += value[n];
		}else{
			sumalice += value[n];
		}
	}
	cout << sumalice << ' ' << sumbob << "\n";
}