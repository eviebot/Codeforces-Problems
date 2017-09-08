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

	int i, n, start, x, val, prev, next;

	cin >> n >> start >> x;

	if(n < 2000){
		cout << "? "<< start << "\n";
		fflush(stdout);
		cin >> val >> next;
		if(val >= x){
			cout << "! "<< start << "\n";
			fflush(stdout);
			return 0;
		}
		prev = next;
		while( next != -1 ){
			cout << "? "<< prev << "\n";
			fflush(stdout);
			cin >> val >> next;
			if(val >= x){
				cout << "! "<< prev << "\n";
				fflush(stdout);
				return 0;
			}

			prev = next;
		}
		cout << "! -1\n";
		fflush(stdout);
		return 0;
	}

	srand(time(NULL));
	vector <tuple <int, int, int>> queries;

	queries.pb(MT(0, start, 0));

	unordered_set <int> repeats;
	repeats.insert(start);

	for(i = 0; i < 999; ++i){
		while(true){
			int t1 = rand()%50000, t2 = rand()%50000;
			int t = 1+(t1+t2)%n;

			if(  repeats.find(t) == repeats.end()){
				cout << "? "<< t << "\n";
				fflush(stdout);
				cin >> val >> next;
				repeats.insert(t);
				queries.pb(MT(val, t, next));
				break;
			}
		}
	}

	sort(queries.begin(), queries.end());

	if( get<0>(queries[0]) >= x){
		cout << "! "<< start << "\n";
		fflush(stdout);
		return 0;
	}
	else if(get<0>(queries[999]) < x){
		prev = get<2>(queries[999]);
		while(prev != -1){
			cout << "? "<< prev << "\n";
			fflush(stdout);
			cin >> val >> next;
			if(val >= x){
				cout << "! "<< prev << "\n";
				fflush(stdout);
				return 0;
			}
			prev = next;
		}
		cout << "! -1\n";
		fflush(stdout);
		return 0;
	}

	for(i = 0; i < 1000; ++i){
		if(get<0>(queries[i]) >= x){
			prev = get<2>(queries[i-1]);
			break;
		}
	}

	while(true){
		cout << "? "<< prev << "\n";
		fflush(stdout);

		cin >> val >> next;
		if(val >= x){
			cout << "! "<< prev << "\n";
			fflush(stdout);
			return 0;
		}
		prev = next;
	}
}