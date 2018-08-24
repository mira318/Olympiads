#include <iostream>

using namespace std;
char Ch[27];
int main()
{
    for(int i = 0; i < 26; ++i)
    {
        Ch[i] = char('A' + i);
    }
    //cout << "well" << endl;
    int t;
    cin >> t;
    for(int j = 0; j < t; ++j)
    {
        int n;
        cin >> n;
        n--;
        string S;
        while(n >= 0)
        {
            int p = n % 26;
            S.push_back(Ch[p]);
            n = n / 26;
            n--;
        }
        for(int i = S.size() - 1; i >= 0; --i)
        {
            cout << S[i];
        }
        cout << endl;
    }
    return 0;
}
