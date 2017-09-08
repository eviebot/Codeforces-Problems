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

	
	int n, t1, t2, t3, t4, t5;
	cout << 1000 << "\n";
	for(int i = 1; i <= 1000; ++i){
		t1 = rand()%1000;
		t2 = rand()%1000;
		t3 = rand()%1000;
		t4 = rand()%1000;
		t5 = rand()%1000;
		cout << t1 << " "<< t2 <<  " "<< t3 << " "<< t4 << " "<< t5 << "\n";
	}
}