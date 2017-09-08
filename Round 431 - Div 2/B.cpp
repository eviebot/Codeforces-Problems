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

lli diff;
lli ycoords[2000], n;
vector <int> set2;

bool compare(int p11, int p12, int p21, int p22){
	return (ycoords[p12]-ycoords[p11])*(p22-p21) == (ycoords[p22]-ycoords[p21])*(p12-p11);
}
bool checker(){


	bool flag = true;
	for(int i = 2; i < set2.size(); ++i){
		if( !compare( set2[i], set2[0], set2[1], set2[0] ) )
			flag = false;
	}
	return flag;
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	cin >> n;
	int i;
	for(i = 1; i <= n; ++i)
		cin >> ycoords[i];

	diff = ycoords[2] - ycoords[1];
	bool flag = false;
	for(i = 2; i <= n; ++i){
		if(ycoords[i] - ycoords[i-1] != diff)
			flag = true;
	}
	if(!flag){
		cout << "NO\n";
		return 0;
	}

	flag = true;
	for(i = 3; i <= n; ++i){
		if(ycoords[i] - ycoords[i-1] != ycoords[3] - ycoords[2])
			flag = false;
	}
	if(flag){
		cout << "YES\n";
		return 0;
	}
	int index;
	for(i = 2; i <= n; ++i){
	
		set2.clear();
		for(int j = 2; j <= n; ++j){
			if(j != i && !compare(i, 1, j, 1)){
				set2.pb(j);
			}else{
				index = j;
			}
		}
		if(checker()){
			if(set2.size() != 1 && set2.size()!= n-1){
				if( !compare(set2[1], set2[0], index, 1))
					continue;
			}
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
}