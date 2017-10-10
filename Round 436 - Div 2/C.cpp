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
lli a, b, f, k;

bool checker(lli tank){
	lli temp = b-f;
	for(lli i = 1; i < k; ++i){
		if(i%2){
			if((a-f)*2 > temp){
				temp = b;
				--tank;
			}
			temp -= 2*(a-f);
		}else{
			if(2 * f > temp){
				temp = b;
				--tank;
			}
			temp -= 2*f;
		}
	}
	if(k%2){
		if(a-f > temp)
			--tank;
	}else{
		if(f > temp)
			--tank;
	}
	if(tank < 0)
		return false;
	return true;
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	lli n, i;
	cin >> a >> b >> f >> k;

	if(k == 1){
		if(f > b || a-f > b)
			cout << "-1\n";
		else if(a > b){
			cout << 1 << "\n";
		}else{
			cout << 0 << "\n";
		}
		return 0;
	}
	else if(k == 2){
		if(f > b || a-f > b){
			cout << "-1\n";
			return 0;
		}
		else if(2*(a-f)>b){
			cout << "-1\n";
			return 0;
		}
	}
	else if( (a-f)*2 > b || 2 * f > b ){
		cout << "-1\n";
		return 0;
	}
	
	lli upper = 100000, lower = 0, mid;

	while(upper != lower){
		mid = (upper+lower)/2;
		//cout << mid << "\n";
		if(checker(mid)){
			upper = mid;
		}else{
			lower = mid+1;
		}
	}
	cout << upper << "\n";
}