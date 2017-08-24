#include <bits/stdc++.h>
using namespace std;

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

ofstream outfile;
ifstream infile;

int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	int n, a, t, i, mini;
	vector <int> array;
	array.pb(-2000000);

	cin >> n >> a;
	if(n == 1){
		cout << "0\n";
		return 0;
	}
	for(i =1; i <= n; ++i){
		cin >> t;
		array.pb(t);
	}

	sort(array.begin(), array.end());

	if(  a <= array[1] || a >= array[n] ){
		if(a <= array[1]){
			cout << array[n-1] - a << "\n";
		}
		else{
			cout << a - array[2] << "\n";
		}
	}
	else if( (a > array[1] && a <= array[2])) {
		int x = a - array[1];
		mini = 2*x + array[n-1]-a;
		mini = min(mini, array[n]-a);

		mini = min(mini, abs(2 * ( array[n-1]-a ) + a - array[1] ));
		cout << mini << "\n";
	}
	else if( a < array[n] && a >= array[n-1] ){
		int x = array[n]-a;
		mini = 2*x + a- array[2];
		mini = min(mini, a- array[1] );
		mini = min(mini, abs(2* (a - array[2]) + array[n]-a ));

		cout << mini << "\n";
	}
	else{
		mini = abs(2 * (a - array[2]) + array[n]-a);

		mini = min(mini, abs(2*(array[n]-a) + a- array[2]) );

		mini = min( mini, abs(2 * ( a - array[1]) + array[n-1]-a)  );

		mini = min( mini, abs(2 * ( array[n-1]-a ) + a- array[1]) );

		cout << mini << "\n";
	}
}