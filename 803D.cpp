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


int k;
string s;
bool checker(int width)
{
	int sum = 0, t =1, words = 0;
	stringstream ss(s);
	string temp;
	
	while(ss >> temp){
		
		sum += temp.size();
		if(ss.peek() != EOF){
			
			if(temp.size()+1> width)
				return false;
			++sum;
		}
		else
		{
			if(temp.size() > width)
				return false;
		}

		if(sum > width)
		{
			sum = temp.size()+1;
			++t;
		}
		//cout << temp << " "<< sum << " "<< t << "\n";
	}
	if(t > k)
		return false;
	return true;
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	getline(cin, s);
	istringstream iss(s);
	iss >> k;
	getline(cin, s);

	for(int i = 0; i < s.size(); ++i)
	{
		if(s[i] == '-')
		{
			s[i]= ' ';
		}
	}
	//cout << checker(6)<< "\n";
	int upper = 1000000, lower = 0, mid;

	
	while(upper != lower)
	{
		mid = (upper+lower)/2;
		if(checker(mid))
			upper = mid;
		else
			lower = mid+1;
	}
	cout << upper << "\n";

}