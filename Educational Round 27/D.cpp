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

	fastIO;
	int n, i, type, sum = 0, speed, sovertake = 0, tspeed;
	stack<int> sspeed;
	cin >> n;
	for(i = 0; i < n; ++i){
		cin >> type;
		if(type == 2){
			sum += sovertake;
			sovertake = 0;
		}
		else if(type == 4)
			sovertake = 0;
		else if(type == 6)
			++sovertake;

		else if(type == 1){
			cin >> speed;
			while(!sspeed.empty()){
				if(sspeed.top() < speed){
					++sum;
					sspeed.pop();
				}
				else
					break;
			}
		}

		else if(type == 3){
			cin >> tspeed;
			if(tspeed < speed){
				++sum;
			}else{
				sspeed.push(tspeed);
			}
		}
		else{
			while(!sspeed.empty()){
				sspeed.pop();
			}
		}
	}
	cout << sum << "\n";
}