#include <iostream>
#include <cstdio>
using namespace std;
const int N = int(1e5) + 7;
long long A[N];
int main()
{
    freopen("sum.in", "r", stdin);
    freopen("Sum.out", "w", stdout);
    int n;
    cin >> n;
    long long sum1 = 0;
    long long sum2 = 0;
    long long maxm = 0;
    long long minp = N;
    for(int i = 0; i < n; ++i)
    {
        cin >> A[i];
        if(i % 2 == 0)
        {
            sum1 = sum1 + A[i];
            minp = min(minp, A[i]);
        }
        else
        {
            sum2 = sum2 - A[i];
            maxm = max(maxm, A[i]);
        }
    }
    long long ans;
    if((sum1 + sum2) < (sum1 + sum2 - 2*minp + 2*maxm))
        ans = sum1 + sum2 - 2*minp + 2*maxm;
    else
        ans = sum1 + sum2;
    cout << ans;
    return 0;
}
