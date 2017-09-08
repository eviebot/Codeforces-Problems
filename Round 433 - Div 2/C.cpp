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
#define maxn 310000
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");
	fastIO
	lli n, k, i;
	lli t, arr[maxn], newarr[maxn], arrsum = 0, sum = 0;

	priority_queue <pair <lli, lli>> myq;

	cin >> n >> k;

	for(i = 1; i <= n; ++i)
		cin >> arr[i];

	for(i = 1; i <= k; ++i){
		sum += arr[i]*(k+1-i);
		myq.push(MP(arr[i], i));
		arrsum += arr[i];
	}

	for(i = k+1; i <= n; ++i){
		myq.push(MP(arr[i], i));
		arrsum += arr[i];
		pair <lli, lli> pp = myq.top();
		myq.pop();
		newarr[pp.se] = i;
		arrsum -= pp.fi;

		sum += arrsum;
	}

	for(i = n+1; i <= n+k; ++i){
		pair <lli, lli> pp = myq.top();
		myq.pop();
		newarr[pp.se] = i;
		arrsum -= pp.fi;
		sum +=arrsum;
	}
	cout << sum << "\n";
	for(i= 1; i <= n; ++i){
		cout << newarr[i] << " ";
	}
	cout << "\n";
}
