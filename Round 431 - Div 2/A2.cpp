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

	int n, a[1005];
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	int st = 0;
	if(a[st]%2 == 0){cout << "NO\n";
return 0;}

	int len = 0, num = 0;
	for(int i =0 ;i <n; ++i){
		if(i!= 0 && (a[i-1]&1) && (a[i] &1) && (len&1))len = 0, num++;
		len++;
	}
	if((len&1)&&(a[n-1]&1))num++,len=0;

	if(len ==0 &&num&1)cout<< "YES\n";
	else cout<< "NO\n";
}