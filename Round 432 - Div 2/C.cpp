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

vector <vector <int>> points;
vector <int> temp;

int checker(int start, int f1, int f2){
	int sum = 0;

	for(int i = 1; i <= 5; ++i){
		sum += (points[f1][i]- points[start][i])*(points[f2][i]-points[start][i]);
	}
	return sum;
}
void remove_points(int a, int b, int c){
	int t1, t2, t3;
	t1 = checker(a, b, c);
	t2 = checker(b, a, c);
	t3 = checker(c, a, b);
	//cout << t1 << " "<< t2 << " "<< t3 << "\n";
	if(t1 <= 0){
		points[b][6] = 0;
		points[c][6] = 0;
		return;
	}
	if(t2 <= 0){
		points[a][6] = 0;
		points[c][6] = 0;
		return ;
	}
	if(t3 <= 0){
		points[a][6] = 0;
		points[b][6] = 0;
		return ;
	}
	points[a][6] = 0;
	points[b][6] = 0;
	points[c][6] = 0;
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	int n, t, i, j, sum;
	cin >> n;
	for(i = 0; i <= 7; ++i){
		temp.pb(0);
	}
	for(i =0 ;i <= n; ++i)
		points.pb(temp);

	for(i =1; i <= n; ++i){
		points[i][6] = 1;
		for(j = 1; j <= 5; ++j){
			cin >> t;
			points[i][j] = t;
		}
	}
	if(n == 1){
		cout << "1\n" << 1 << "\n";
		return 0;
	}
	else if( n == 2){
		cout << "2\n"<< 1 << "\n"<< 2 << "\n";
		return 0;
	}
	int index[4];
	while(true){
		sum = 0;
			for(i = 1; i <= n; ++i){
				if(points[i][6]){
					++sum;
					index[sum] = i;
				}
				if(sum == 3){
					break;
				}
			}
		if(sum == 2){
			for(i = 1; i <= n; ++i){
				if(!points[i][6]){
					index[3] = i;
					break;
				}
			}
		}
		else if(sum <= 1){
			break;
		}
		remove_points(index[1], index[2], index[3]);
	}

	if(sum){
		int challenge;
		for(i = 1; i <= n; ++i){
			if(points[i][6])
				challenge = i;
		}

		for(i = 1; i <= n; ++i){
			for(j = 1; j <= n; ++j){
				if(i != j && i != challenge && j != challenge){
					remove_points(i, j, challenge);
				}
			}
		}

		for(i =1 ; i <= n; ++i){
			if(points[i][6]){
				cout << "1\n"<< i << "\n";
				return 0;
			}
		}
	}
	cout << "0\n";
}
