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

lli zz, zo, oz, oo, a, b;

lli search(lli x){
	lli upper = 1000000, lower = 0, mid;

	while(lower <= upper){
		mid = (upper+lower)/2;

		lli temp = ((mid)*(mid-1))/2;
		//cout << mid << "\n";
		if(temp < x){
			lower = mid+1;
		}
		else if(temp > x){
			upper = mid-1;
		}else{
			
			if( (mid)*(mid+1) == x ){
				return mid+1;
			}
			return mid;
		}
	}
	return -1;
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	
	cin >> zz >> zo >> oz >> oo;
	string fin;

	a = search(zz);
	b = search(oo);

	//cout << a << " "<< b << "\n";


	if( a == -1 || b == -1){
		cout << "Impossible\n";
		return 0;
	}
	else if( a == 1 && b == 1){
		if(zo == 1 && !oz){
			cout << "01\n";
		}
		else if(oz == 1 && !zo){
			cout << "10\n";
		}
		else if(!zo && !oz){
			cout << "0\n";
		}else{
			cout << "Impossible\n";
		}
		return 0;
	}

	lli t = a * b - oz, zot = zo;

	if( zo != t ){
		if(a == 1){
			a = 0;
		}
		else if(b == 1)
			b = 0;

		t = a * b - oz;
		if(zo != t){
		cout << "Impossible\n";
		return 0;}

	}

	t = b;
	vector <lli> pos;

	for(lli i = 1; i <= t; ++i){
		if(!zot){
			pos.pb(0);
			continue;
		}

		if(zot - a >= 0){
			zot -= a;
			pos.pb(a);
		}
		else{
			pos.pb(zot);
			zot = 0;
		}
	}

	lli count0 =0, c =0;

	sort(pos.begin(), pos.end());

	
	/*for(lli z = 0; z < pos.size(); ++z){
		cout << pos[z] << "\n";
	}*/

	
	while(count0 < a){
		while( c < pos.size() && pos[c] == count0 ){
			fin += '1';
			++c;
		}
		fin += '0';
		++count0;	
	}

	while( c < pos.size() && pos[c] == a ){
		fin += '1';
		++c;
	}
	cout << fin << "\n";
}