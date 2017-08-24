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

	int n, k, seat_wing, seat_middle, seat_ms = 0;
	cin >> n >> k;

	seat_middle = n;
	seat_wing = n * 2;

	int t;

	for(int i = 0; i < k; ++i){
		cin >> t;

		while( t > 3 && seat_middle > 0){
			seat_middle--;
			t -= 4;
		}

		if( !seat_middle ){
			while(t > 3 && seat_wing > 1){
				t -= 4;
				seat_wing -= 2;
			}
		}

		if(seat_wing < 2){

			if(t > 3 && seat_wing == 1){
				--seat_wing;
				if(seat_ms > 1){
					seat_ms -= 2;
					t -= 4;
				}
				else{
					cout << "NO\n";
					return 0;
				}
			}
			while(t > 3 && seat_ms > 3){
				t -= 4;
				seat_ms -= 4;
			}
		}
		if(seat_ms < 4 && t > 3){
			cout << "NO\n";
			return 0;
		}

		if(t%4 == 1){
			if(seat_ms)
				--seat_ms;
			else if(seat_middle){
				++seat_wing;
				--seat_middle;
			}
			else if(seat_wing){
				--seat_wing;
			}
			else{
				cout << "NO\n";
				return 0;
			}
		}
		else if(t%4 == 2){
			
			if(seat_wing){
				--seat_wing;
			}
			else if(seat_middle){
				++seat_ms;
				--seat_middle;
			}
			else if(seat_ms > 1){
				seat_ms -= 2;
			}
			else
			{
				cout << "NO\n";
				return 0;
			}
		}
		else if(t%4 == 3){
			if(seat_middle)
				--seat_middle;

			else if(seat_wing >= 1)
			{
				seat_wing--;
				if(seat_ms > 0)
					--seat_ms;
				else if(seat_wing > 0)
					--seat_wing;
				else{
					cout << "NO\n";
					return 0;
				}
			}
			else if(seat_ms > 2){
				seat_ms -= 3;
			}
			else{
				cout << "NO\n";
				return 0;
			}
		}
	}
	cout << "YES\n";
}