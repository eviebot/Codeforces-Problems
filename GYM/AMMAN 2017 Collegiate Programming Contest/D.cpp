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

#define mod 1000000007

lli fact[100010] ;

void init()
  {
    fact[0]=1 ;
    for (int i=1 ; i<=100001 ; i++)
      fact[i]=fact[i-1]*i%mod ;
  }

lli fast_exp(lli base, lli exp)
  {
    lli res=1;
    while(exp>0)
      {
        if(exp%2==1) res=(res*base)%mod;
        base=(base*base)%mod;
        exp/=2;
      }
    return res%mod;
  }

lli getInverse(lli n)
  {
    return fast_exp(n, mod-2) ;
  }

lli divide(lli a, lli b)
  {
    a=a%mod ;
    b=b%mod ;
    return (a*(getInverse(b)%mod))%mod ;
  }

lli nCr(lli n, lli r)
  {
  	//cout << n<< " " << r << "\n";
    if(r>n || r<0) return 0 ;
    return divide(divide(fact[n],fact[r]), fact[n-r])%mod ;
  }


int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	init();
	lli test, a, b;
	cin >> test;
	for(int z =0; z < test; ++z){
		cin >> a >> b;
		cout << (2 * (nCr(a-1, b)%mod)%mod) << "\n";
	}
}