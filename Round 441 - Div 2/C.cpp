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
#define clr(ar) memset(ar, 0, sizeof(ar));

typedef long long int lli;

using namespace std;

ofstream outfile;
ifstream infile;

int checker(int x){
	int sum = 0;
	while(x){
		sum += (x%10);
		x /= 10;
	}
	return sum;
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	int n, i;
	vector <int> ans;
	cin >> n;
	for(i = 0; i < 200; ++i){
		int x = n-i;
		if(x <= 0)
			break;
		int t = checker(x);
		if(t + x == n){
			ans.pb(x);
		}
	}
	cout << ans.size() << "\n";
	sort(ans.begin(),ans.end());
	for(auto it:ans)
		cout << it << "\n";
	cout << '\n';
}