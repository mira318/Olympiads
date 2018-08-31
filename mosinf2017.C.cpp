#include <iostream>
#include <cstdio>
using namespace std;
int S[10001];
int n, k;
string Ans;
int Numbers[23];
void easy(int printed, int pos, string Way)
{
    if(printed == k || (Way.length() >= Ans.length() && Ans != ""))
    {
        if(Ans == "" || Ans.length() > Way.length())
        {
            Ans = Way;
        }
    }
    else
    {
        for(int i = 0; i < n; ++i)
        {
            int old = Numbers[i];
            string NW = Way;
            int now = pos;
            if((i > pos && i - pos > n/2) || (i <= pos && pos - i <= n/2))
            {
                while(now != i)
                {
                    NW.push_back('<');
                    now--;
                    if(now == -1)
                    {
                        now = n - 1;
                    }
                }
            }
            else
            {
                while(now != i)
                {
                    NW.push_back('>');
                    now++;
                    if(now == n)
                    {
                        now = 0;
                    }
                }
            }
            if(((S[printed]) > Numbers[i] && S[printed] - Numbers[i] > 5) || (S[printed] <= Numbers[i] && Numbers[i] - S[printed] <= 5))
            {
                while(Numbers[i] != S[printed])
                {
                    //cout << "Numbers[" << i <<"] = " << Numbers[i] << endl;
                    //cout << "S[" << printed << "] = " << S[printed] << endl;
                    NW.push_back('-');
                    Numbers[i]--;
                    if(Numbers[i] == -1)
                    {
                        Numbers[i] = 9;
                    }
                }
            }
            else
            {
                while(Numbers[i] != S[printed])
                {
                    NW.push_back('+');
                    Numbers[i]++;
                    if(Numbers[i] == 10)
                    {
                        Numbers[i] = 0;
                    }
                }
            }
            NW.push_back('P');
            easy(printed + 1, i, NW);
            Numbers[i] = old;
        }
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Ans = "";
    cin >> n >> k;
    //cout << "k = " << k << endl;
    for(int i = 0; i < k; ++i)
    {
        cin >> S[i];
        //cout << "S[" << i << "] = " << S[i] << endl;
    }
    string Way = "";
    easy(0, 0, Way);
    cout << Ans;
    return 0;
}
