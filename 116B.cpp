#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define pb push_back

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int i, n, m, j, sum = 0;
    char c;
    scanf("%d %d", &n, &m);
    int grid[n][m];
    bool top_row_flag, bot_row_flag, left_col_flag, right_col_flag ;
    for(i = 0; i< n;i++)
    {
        for(j=0;j< m;j++)
        {
            cin >> c;
            if(c=='.'){grid[i][j]=0;}
            else if(c=='P'){grid[i][j]=1;}
            else {grid[i][j]=2;}
        }
    }
    for(i = 0; i< n;i++)
    {
        for(j=0;j<m;j++)
        {   top_row_flag= true; bot_row_flag= true;left_col_flag= true;right_col_flag = true;
            if(grid[i][j]==2)
            {
                if(i==0)
                    top_row_flag =false;
                else if(i==n-1)
                    bot_row_flag = false;
                if(j==0)
                    left_col_flag = false;
                else if(j==m-1)
                    right_col_flag =false;
                if(grid[i][j+right_col_flag]==1){sum++;grid[i][j+right_col_flag]= 0;}
                else if(grid[i][j-left_col_flag]==1){sum++;grid[i][j-left_col_flag]=0;}
                else if(grid[i+bot_row_flag][j]==1){sum++;grid[i+bot_row_flag][j]=0;}
                else if(grid[i-top_row_flag][j]==1){sum++;grid[i-top_row_flag][j]=0;}
            } //cout << top_row_flag<<bot_row_flag<<left_col_flag<<right_col_flag;
        }//cout << "\n";
    }
    cout << sum;
}
