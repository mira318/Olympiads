#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = int(1e5) + 7;
int Am[N];
int Am2[N];
int main()
{
    freopen("gotham.in", "r", stdin);
    freopen("gotham.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    long long sum = 0;
    for(int i = 0; i < n; ++i)
    {
        cin >> Am[i];
        Am2[i] = Am[i];
    }
    sort(Am, Am + n);
    sort(Am2, Am2 + n);
    int res = 0;
    int i = n - 1;
    while(res < m && i >= 1)
    {
        //cout << "i = " << i << endl;
        while(Am[i] > 0 && res < m)
        {
            int j = i - 1;
            //cout << "j = " << j << endl;
            while(res < m && j >= 0 && Am[i] > 0)
            {
                if(i != j && Am[j] > 0)
                {
                    Am[i]--;
                    Am[j]--;
                    res++;
                }
                j--;
                //cout << "j = " << j << endl;
                //cout << "res = " << res << endl;
            }
        }
        i--;
        //cout << "i = " << i << endl;

    }
    if(res < m)
    {
        cout << "-1";
        return 0;
    }
    int ans = -1;
    for(int i = 0; i < n; ++i)
    {
        //cout << "Am2[" << i << "] = " << Am2[i] << endl;
        //cout << "n - 1 - i = " << n - 1 - i << endl;
        //cout << "v = " << n - i << endl;
        if(ans == -1 && Am2[i] >= n - 1 - i && ((n - 1 - i)*(n - i))/2 <= m)
        {
            ans = n - i;
        }
    }
    cout << ans;
    return 0;
}
