#include <bits/stdc++.h>

#define fastIO ios::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);cerr.tie(NULL);
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

lli arr[110000][3];
vector <pair <lli, lli>> sorta, sortb;
lli n, sum = 0, c = 0, totpizzas, maxsum = 0;

int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	lli i, sizes, j, a, b, t, sizea = 0, sizeb= 0, sum1 = 0, sum2 = 0, tsum1, tsum2;
	cin >> n >> sizes ;
	

	for(i = 0; i < n; ++i){
		cin >> t >> a >> b;
		sum += ((lli)(t/sizes))*max(a, b)*sizes;
		t %= sizes;
		if(!t){
			t += sizes;
			sum -= max(a, b)*sizes;
		}

		++c;
		arr[c][0] = t;arr[c][1] = a;arr[c][2] = b;
		if(a > b){
			sorta.pb(MP(a-b, c));
			sum1 += t*a;
			sizea += t;
		}else{
			sortb.pb(MP(b-a, c));
			sum2 += t*b;
			sizeb += t;
		}
	}
	n = c;
	sort(sorta.begin(), sorta.end());
	sort(sortb.begin(), sortb.end());
	reverse(sorta.begin(), sorta.end());
	reverse(sortb.begin(), sortb.end());
	
	lli p1, p2;
	if(sizea%sizes)
		p1 = (lli)(sizea/sizes) + 1;
	else
		p1 = (lli)(sizea/sizes);
	if(sizeb%sizes)
		p2 = (lli)(sizeb/sizes) + 1;
	else
		p2=  (lli)(sizeb/sizes);
	if((sizeb+sizea)%sizes)
		totpizzas = (lli)((sizeb+sizea)/sizes) + 1;
	else
		totpizzas = (lli)((sizeb+sizea)/sizes);

	//cout << p1 << " "<< p2 << " "<< totpizzas << "\n";
	//cout << sum1 << " "<< sum2 << " "<< temp1 << " "<< temp2 << "\n";
	if(p1 +p2 == totpizzas){
		cout <<sum + sum1 +sum2 << "\n";
		return 0;
	}
	lli temp1 = sizea, temp2 = sizeb, c1 = sorta.size()-1, c2 = sortb.size()-1;
	tsum1 = sum1;tsum2 = sum2;
	while(temp1 > (p1-1)*sizes){
		temp1 -= arr[sorta[c1].se][0];
		tsum1 -= arr[sorta[c1].se][0]*sorta[c1].fi;
		--c1;
	}

	temp1 = (p1-1)*sizes - temp1;
	++c1;
	
	//tsum1 += (temp1*sorta[c1].se+ ((arr[sorta[c1].se][0]-temp1)*arr[sorta[c1].se][2]) );
	tsum1 += (temp1*sorta[c1].fi);
	
	maxsum = max(maxsum, tsum1+sum2);


	while(temp2 > (p2-1)*sizes){
		temp2 -= arr[sortb[c2].se][0];
		tsum2 -= arr[sortb[c2].se][0]*sortb[c2].fi;
		--c2;
	}
	temp2 = (p2-1)*sizes - temp2;
	++c2;
	
	//tsum2 += (temp2*sortb[c2].se+ ((arr[sortb[c2].se][0]-temp2)*arr[sortb[c2].se][1]) );
	//sum1 -= (temp2*sortb[c2].se+ ((arr[sortb[c2].se][0]-temp2)*arr[sortb[c2].se][1]) );

	tsum2 += (temp2*sortb[c2].fi);
	maxsum = max(maxsum, tsum2 + sum1);

	cout << sum + maxsum << "\n";	
}