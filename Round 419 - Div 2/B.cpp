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

const int maxn = 200000;
int n, k, q;
vector <int> lazy, tree, segtree;
vector <bool> basis;

void checktree(int node, int start, int end)
{
    if( lazy[node])
    {
        if(start != end)
        {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        tree[node] += lazy[node];
        lazy[node] = 0;
    }
    if( start == end )
    {
        if( tree[node] >= k)
        {
            basis[start] = 1;
        }
        
        return ;
    }
    int mid = (start+end)/2;

    checktree(node*2, start, mid);
    checktree(node*2+1, mid+1, end);
}
void buildsegtree(int node, int start, int end)
{
    if(start == end)
    {
        segtree[node] = basis[start];
        return;
    }
    int mid = (start+end)/2;

    buildsegtree(node*2, start, mid);
    buildsegtree(node*2+1, mid+1, end);
    segtree[node] = segtree[node*2] + segtree[node*2+1];
}
void build(int node, int start, int end, int l, int r)
{
    
    if( lazy[node] )
    {
        tree[node] += lazy[node];
        if( start != end)
        {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        
        lazy[node] = 0;
    }

    if( r < start || end < l)
        return;

    int mid = (start+end)/2;

    if( start >= l && end <= r )
    {
        
        tree[node] += 1;
        if( start != end){
        lazy[node*2]++;
        lazy[node*2+1]++;}
       
        return;
    }

    build(node*2, start, mid, l, r);
    build(node*2+1, mid+1, end, l, r);

}
int solve(int node, int start, int end, int l, int r)
{
   
    if( start > r ||  end < l)
    {
        return 0;
    }

    if( start >= l && end <= r)
    {
        return segtree[node];
    }
    int mid = (start+end)/2;

    return solve(node*2, start, mid, l, r)+solve(node*2+1, mid+1, end, l, r);

}
int main()
{
    infile.open("input.txt");
    outfile.open("output.txt");

    fastIO;
    int l, r;
    cin >> n >> k >> q;

    int i, j;
    for(i = 0; i <= 2*maxn; ++i)
    {
        lazy.pb(0);
        tree.pb(0);
        basis.pb(0);
        segtree.pb(0);
    }
    for(i = 0; i < n; ++i)
    {
        cin >> l >> r;
        build(1, 1, maxn, l, r);
    }
    
    checktree(1, 1, maxn);

    buildsegtree(1, 1, maxn);
   
    for(i = 0; i < q; ++i)
    {
        cin >> l >> r;
        cout << solve(1, 1, maxn, l, r)<< "\n";
    }
}
