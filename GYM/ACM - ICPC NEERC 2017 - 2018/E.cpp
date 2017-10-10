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

vector <int> asterisk, packmen;
int n;
bool visited[100010];

bool checker(int time){
	int t1 = asterisk.size(), t2 = packmen.size(), i, j, curP = 0, curA = 0, curPos;

	while(curP != t2 && curA != t1){
		curPos = packmen[curP];
		if(asterisk[curA] > curPos){
			curPos += time;
		}
		else{
			if(time < curPos - asterisk[curA])
				break;
			int right1 = time - 2*(curPos - asterisk[curA]), right2 = (time - (curPos - asterisk[curA]))/2;
			
			curPos += max(right2, right1);
		}
		
		while(curA != t1){
			if(asterisk[curA] > curPos)
				break;
			curA++;
		}

		curP++;
	}
	if(curA == t1)
		return true;
	return false;
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

fastIO;
	string s;
	int i;
	
	cin >> n >> s;
	for(i= 0; i < n; ++i){
		if(s[i] == '*')
			asterisk.pb(i);
		else if(s[i] == 'P')
			packmen.pb(i);
	}

	int lower = 1, upper = 200000, mid;
	while(upper > lower){

		mid = (upper+lower)/2;
		if(checker(mid)){
			upper = mid;
		}else{
			lower = mid+1;
		}
	}
	cout << upper << "\n";
}