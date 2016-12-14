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
    int n, A=0, G=0, i, t, g;
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
    for(;it1<=it2;)
    {
        if(A+it1->first-G <=500){
        A+= (it1->first);
        fin[it1->second]='A';it1++;}
        else{
        G += 1000-it2->first;
        fin[it2->second] = 'G';it2--;;
    }}

    if(abs(A-G)>500)
        cout << "-1";
    else{
    //cout << "A="<< A<< " G="<<G<<"\n";
    for(i=0; i<n;i++)
        cout << fin[i];}
}
