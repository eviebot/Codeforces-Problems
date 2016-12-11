#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define pb push_back

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long int n, t, i, books=0, sum = 0, j=0, maximum_books = 0;
    cin >> n >> t;
    long long int arr[n];
    for(i = 0;i<n;i++)
    {
        cin >> arr[i];
        sum += arr[i];
        books++;
        if(sum > t)
        {
            sum -= arr[j];
            books--;
            j++;
        }
        //cout << " "<<sum << "\n";
        maximum_books=(books > maximum_books?books:maximum_books);
    }
    cout << maximum_books;
}
