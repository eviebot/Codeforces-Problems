#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define pb push_back

int main()
{
    int m, n, i, j, t, com_rows=0, com_columns = 0;
    scanf("%d %d", &m , &n);
    int rows[m]={0}, columns[n] = {0};
    for(i = 0; i< m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d", &t);
            if(t)
            {
                rows[i]++;
                columns[j]++;
            }
            if(columns[j]==m)
                com_columns ++;
        }
        if(rows[i]==n)
            com_rows++;
    }
    if((com_columns >0 || com_rows>0) && com_columns*com_rows==0)
    {
        cout << "NO";
        return 0;
    }
    //cout << "complete rows="<<com_rows<<" and completed col = "<<com_columns<<"\n";
    for(i = 0; i< m;i++)
    {   //cout << rows[i] << " ";
        if(rows[i]!=n && rows[i] > com_columns)
        {
            cout << "NO";
            return 0;
        }
    }//cout << "\n";
    for(i = 0; i< n;i++)
    {   //cout << columns[i]<<" ";
        if(columns[i]!=m && columns[i] > com_rows)
        {
            cout << "NO";
            return 0;
        }
    }//cout << "\n";
    cout << "YES\n";
    for(i = 0; i< m;i++)
    {
        for(j = 0; j< n;j++)
        {
            cout << (rows[i]/n)*(columns[j]/ m) << " ";
        }
        cout << "\n";
    }
}
