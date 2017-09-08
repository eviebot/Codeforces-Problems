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

	
	lli ax, ay, bx, by, cx, cy, dist1, dist2;

	cin >> ax >> ay >> bx >> by >> cx >> cy;

	dist1 = (ax-bx)*(ax-bx) + (ay-by)*(ay-by);
	dist2 = (bx-cx)*(bx-cx) + (by-cy)*(by-cy);

	if(dist1 != dist2){
		cout << "NO\n";
		return 0;
	}

	lli slope1[2], slope2[2];

	slope1[0] = by-ay;
	slope1[1] = bx-ax;
	slope2[0] = cy-by;
	slope2[1] = cx-bx;

	lli t1 = __gcd(slope1[0], slope1[1]), t2 = __gcd(slope2[0], slope2[1]);

	slope1[0] /= t1;slope1[1] /= t1;
	slope2[0] /= t2;slope2[1] /= t2;

	if( slope1[0] == slope2[0] && slope1[1] == slope2[1] ){
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
}