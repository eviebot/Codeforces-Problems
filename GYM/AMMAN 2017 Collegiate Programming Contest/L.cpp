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
using pii = pair<lli, lli> ;
using vi = vector<lli> ;
using vb = vector<bool> ;
using vvi = vector<vector<lli>> ;
using vlli = vector<long long lli> ;
using vpii = vector<pair<lli, lli>> ;

lli n, m, u, v, c, ans ;
vector <vector <pair <lli, lli>>> adj;
vector <lli> dist;
vector <bool> visit;

bool bellmanFord()
  {
    for(lli i = 1; i <= n; ++i)
      dist[i] = 1000000000000000ll;
    dist[1]=0 ;
    for(lli i=0 ; i<n-1 ; i++)
      for(lli u=1 ; u<=n ; u++)
        for(auto v:adj[u])
          dist[v.fi]=min(dist[v.fi], dist[u]+v.se) ;
    for(lli u=1 ; u<=n ; u++)
      for(auto v:adj[u])
        if(dist[v.fi]>dist[u]+v.se)
          return true ;
    return false ;
  }

void dfs(lli u, lli d)
  {
    visit[u]=true ;
    ans=min(ans, d) ;
    for(auto v:adj[u])
      if(!visit[v.fi])
        dfs(v.fi, v.se+d) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    lli T ;
    cin >> T;
    visit.resize(2002);
    dist.resize(2002);
    while(T--)
      {
        cin >> n >> m;
        adj.clear() ; adj.resize(n+1) ;
        for(lli i=0 ; i<m ; i++)
          {
            cin >> u >> v >> c;
            adj[u].pb(mp(v, c)) ;
          }
        if(bellmanFord()) cout << "-inf\n" ;
        else
          {
            ans=inf ;
            for(lli i=1 ; i<=n ; i++)
              {
                for(lli j = 1; j <= n; ++j)
                  visit[j] = 0;
                dfs(i, 0) ;
              }
          cout << ans << "\n";
          }
      }
  }
