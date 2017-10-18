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

	int n, m, t, i;
	int count1[10], count2[10];
	memset(count1, 0, sizeof(count1));
	memset(count2, 0, sizeof(count2));

	cin >> n >> m;
	for(i = 1; i <= n; ++i){
		cin >> t;
		count1[t]++;
	}
	for(i = 1; i <= m; ++i){
		cin >> t;
		count2[t]++;
	}

	for(i = 1;i <= 9; ++i){
		if(count1[i] && count2[i]){
			cout << i << "\n";
			return 0;
		}
	}
	int min1, min2;
	for(i = 1; i <= 9; ++i){
		if(count1[i]){
			min1 = i;
			break;
		}
	}
	for(i = 1; i <= 9; ++i){
		if(count2[i]){
			min2 = i;
			break;
		}
	}
	cout << min(min1, min2)<< max(min1, min2) << "\n";
}