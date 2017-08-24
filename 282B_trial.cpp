/*░░░░░░░░░░░░▄▄▄▄░░░░░░░░░░░░░░░░░░░░░░░▄▄▄▄▄░░░░
  ░░░█░░░░▄▀█▀▀▄░░▀▀▀▄░░░░▐█░░░░░░░░░▄▀█▀▀▄░░░▀█▄░
  ░░█░░░░▀░▐▌░░▐▌░░░░░▀░░░▐█░░░░░░░░▀░▐▌░░▐▌░░░░█▀
  ░▐▌░░░░░░░▀▄▄▀░░░░░░░░░░▐█▄▄░░░░░░░░░▀▄▄▀░░░░░▐▌
  ░█░░░░░░░░░░░░░░░░░░░░░░░░░▀█░░░░░░░░░░░░░░░░░░█
  ▐█░░░░░░░░░░░░░░░░░░░░░░░░░░█▌░░░░░░░░░░░░░░░░░█
  ▐█░░░░░░░░░░░░░░░░░░░░░░░░░░█▌░░░░░░░░░░░░░░░░░█
  ░█░░░░░░░░░░░░░░░░░░░░█▄░░░▄█░░░░░░░░░░░░░░░░░░█
  ░▐▌░░░░░░░░░░░░░░░░░░░░▀███▀░░░░░░░░░░░░░░░░░░▐▌
  ░░█░░░░░░░░░░░░░░░░░▀▄░░░░░░░░░░▄▀░░░░░░░░░░░░█░
  ░░░█░░░░░░░░░░░░░░░░░░▀▄▄▄▄▄▄▄▀▀░░░░░░░░░░░░░█░  - PROPRIETARY CODE OF EVIEBOT*/


#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define pb push_back

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n, A=0, G=0, i, t, g, status = 0;
    scanf("%d", &n);
    char fin[n];
    vector <pair <int, int> > vec;
    for(i=0;i<n;i++)
    {
        scanf("%d %d", &g, &t);
        vec.push_back(make_pair(g, i));
    }
    sort(vec.begin(), vec.end());

    vector <pair<int,int> >::iterator it1 = vec.begin();
    vector <pair<int,int> >::iterator it2 = vec.end();
    it2--;
    for(;it1<it2;it1++, it2--, status++)
    {
        if(status%2==0)
        {
            A+= (it1->first);
            fin[it1->second]='A';fin[it2->second]='A';
        }
        else
        {
            A+= (2000-it1->first-it2->first);
            fin[it1->second]='G';fin[it2->second]='G';
        }
    }
    if(vec.size()%2==0)
    {
        G=1000*n-A;
    }
    else
    {
        G = 1000*(n-1)-A;
        if(A<G)
        {
             if(it1->first > 1000-it1->first)
             {
                 fin[it1->second] = 'A';
                 A += it1->first; G += 1000-it1->first;
             }
             else
             {
                 fin[it1->second] = 'G';
                 A += 1000-it1->first; G += it1->first;
             }

        }
        else
        {
            if(it1->first > 1000-it1->first)
             {
                 fin[it1->second] = 'G';
                 G += it1->first; A += 1000-it1->first;
             }
             else
             {
                 fin[it1->second] = 'A';
                 G += 1000-it1->first; A += it1->first;
             }
        }
    }
    cout << "A="<< A<< " G="<<G<<"\n";
    for(i=0; i<n;i++)
        cout << fin[i];
}
