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

	string s;
	cin >> s;

	int sum1 = 0, sum2= 0, i;
	int higher[3], lower[3];
	for(i = 0; i < 3; ++i){
		sum1 += s[i]-'0';
	}
	for(i = 3; i < 6; ++i){
		sum2 += s[i]-'0';
	}

	if(sum2 == sum1){
		cout << "0\n";
		return 0;
	}

	if(sum2 > sum1){
		for(i = 0; i < 3; ++i)
			lower[i] = s[i]-'0';
		for(i = 3; i < 6; ++i)
			higher[i-3] = s[i]-'0';
	}
	else{
		for(i = 0; i < 3; ++i)
			higher[i] = s[i]-'0';
		for(i = 3; i < 6; ++i)
			lower[i-3] = s[i]-'0';
	}

	int diff = abs(sum1 - sum2), c = 0;

	while(diff > 0){
		int maxi = 0, index;
		for(i = 0; i < 3; ++i){
			if(9-lower[i] > maxi){
				maxi = max(9-lower[i], maxi);
				index = i;
			}
		}
		
		for(i = 3; i < 6; ++i){
			if(higher[i-3] > maxi){
				index = i;
				maxi = max(higher[i-3], maxi);
			}
		}
		if(index < 3){
			lower[index] = 9;
		}else{
			higher[index-3] = 0;
		}

		diff -= maxi;
		++c;
	}

	cout << c << "\n";
}