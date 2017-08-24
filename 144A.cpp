#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, i, index_smallest=0, index_largest=0;
    cin >> n;
    int original[n];
    scanf("%d", &original[0]);
    for(i = 1; i< n; i++)
    {
        scanf("%d", &original[i]);
        if(original[i] > original[index_largest])
            index_largest = i;
        else if(original[i] <= original[index_smallest])
            index_smallest = i;
    }
    //cout << index_largest << endl << index_smallest << endl;
    if(index_largest > index_smallest)
    {
        cout << (index_largest)+(n-2-index_smallest);
    }
    else
    {
        cout << (index_largest)+(n-1-index_smallest);
    }

}
