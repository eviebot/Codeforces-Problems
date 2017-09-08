#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define endl '\n'
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define fi first
#define se second
#define all(cc) (cc).begin(),(cc).end()
using lli = long long int ;
using pii = pair<int, int> ;
using vi = vector<int> ;
using vb = vector<bool> ;
using vvi = vector<vector<int>> ;
using vlli = vector<long long int> ;
using vpii = vector<pair<int, int>> ;

int T, n, q, l, r ;
long long int ans[110000];

int calc(lli x)
  {
    if(x == 1) return 0;
    else if(x==2) return 1 ;
    
    if(x%2) return calc(x/2)+2;
    return calc(x/2)+1;
  }

int main()
  {
    //ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    scanf("%d", &T);
    long long int t;
    while(T--)
      {
        scanf("%d %d", &n, &q);
        
        for(int i=0 ; i<n ; i++){
          scanf("%lld", &t);
          ans[i]=calc(t) ;
        }
        for(int i=1 ; i<n ; i++)
          ans[i]+=ans[i-1] ;
        for(int i=0 ; i<q ; i++)
          {
            scanf("%d %d", &l, &r);
            l-- ; r-- ;
            if(l) printf("%lld\n", ans[r] - ans[l-1]);
            else printf("%lld\n", ans[r]);
          }
      }
  }