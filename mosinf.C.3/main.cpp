#include <iostream>
#include <cstdio>
using namespace std;
int S[10001];
int Numbers[21];
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < k; ++i)
    {
        cin >> S[i];
    }
    for(int i = 0; i < n; ++i)
    {
        if((i % 10) >= 5)
        {
            while(Numbers[i] != (i % 10))
            {
                cout << '-';
                Numbers[i]--;
                if(Numbers[i] == -1)
                {
                    Numbers[i] = 9;
                }

            }
        }
        else
        {
            while(Numbers[i] != (i % 10))
            {
                cout << '+';
                Numbers[i]++;
                if(Numbers[i] == 10)
                {
                    Numbers[i] = 0;
                }
            }
        }
        if(i != 19)
            cout << '>';
    }
    int pos = 19;
    for(int i = 0; i < k; ++i)
    {
        int am = 0;
        int np = pos;
        while(am <= 5 && Numbers[np] != S[i])
        {
            np++;
            am++;
            if(np == 20)
            {
                np = 0;
            }
        }
        if(am <= 5 && Numbers[np] == S[i])
        {
            for(int j = 0; j < am; ++j)
            {
                cout << '>';
            }
            cout << 'P';
            pos = np;
        }
        else
        {
            am = 0;
            np = pos;
            while(am <= 5 && Numbers[np] != S[i])
            {
                cout << '<';
                np--;
                am++;
                if(np == -1)
                {
                    np = 19;
                }
            }
            cout << 'P';
            pos = np;
        }
    }
    return 0;
}
