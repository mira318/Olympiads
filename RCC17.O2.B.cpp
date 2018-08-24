#include <iostream>
#include <algorithm>
using namespace std;
const int N = int(1e5) + 7;
int main()
{
    int t;
    cin >> t;
    for(int j = 0; j < t; ++j)
    {
        int n;
        long long H, A;
        long long All[N];
        cin >> n >> H >> A;
        for(int i = 0; i < n; ++i)
        {
            long long h, a;
            cin >> h >> a;
            long long p = (h + A - 1)/A;
            long long yr = p*a;
            //cout << "yr = " << yr << endl;
            All[i] = yr;
        }
        sort(All, All + n);
        //for(int i = 0; i < n; ++i)
        //{
          //  cout << All[i] << " ";
        //}
        //cout << endl;
        int k = n - 1;
        while(k >= 0 && H > 0)
        {
            //cout << "k = " << k << endl;
            H = H - All[k];
            //cout << "H = " << H << endl;
            k--;
            //cout << "k = " << k << endl;
        }
        if(H > 0)
        {
            cout << "-1" << endl;
        }
        else
        {
            //cout << "k = " << k << endl;
            cout << n - k - 2 << endl;
        }
    }
    return 0;
}
