#include <iostream>
#include <algorithm>
using namespace std;
const int N = 5;
int A[N];
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }
    sort(A, A + n);
    int ind = (n - 1)/2;
    cout << A[ind];
    return 0;
}
