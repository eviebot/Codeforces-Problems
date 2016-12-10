#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define pb push_back


int main()
{
    int n, s, fin, i, sum = 1;
    scanf("%d %d %d", &n, &s, &fin);
    map <int, bool> mymap;
    int arr[n];
    if(s ==fin)
        cout << "0";
    else{
    for(i = 0;i< n;i++)
        scanf("%d", &arr[i]);
    while(true)
    {   if(mymap[s])
        {
            cout << "-1\n";break;
        }
        else if(arr[s-1]==fin){
            cout << sum<<"\n";
            break;
        }
        else
        {
            mymap[s] = true;
            s= arr[s-1];
            sum++;
        }

    }
    }
   /* for(map<int, bool >::iterator i = mymap.begin();i!=mymap.end();i++)
    {
        cout << i->first << " " << i->second << "\n";
    }*/
}
