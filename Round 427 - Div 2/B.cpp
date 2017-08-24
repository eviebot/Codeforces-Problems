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

	int k;
	string s;
	cin >> k >> s;
	int sum = 0, final = 0;
	vector <int> arr;

	for(int i =0 ; i < s.size(); ++i)
	{
		sum += (s[i]-'0');
		arr.pb(s[i]-'0');
	}
	if( k > sum){
		int diff = k-sum;
		
		sort(arr.begin(), arr.end());

		for(int i = 0; i < s.size();++i)
		{
			if(diff <= 0)
				break;
			
			diff -= (9-arr[i]);
			++final;
			
		}
		cout << final << "\n";
	}
	else
		cout << "0\n";
}