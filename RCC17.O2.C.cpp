#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i)
    {
        long long ans = 0;
        int A, B;
        cin >> A >> B;
        bool flag = false;
        bool flag2 = false;
        while(!flag && B >= A)
        {
            string S = to_string(B);
            if(S[0] == S[S.length() - 1])
            {
                flag = true;
            }
            else
            {
                B--;
            }
        }
        while(!flag2 && A <= B)
        {
            S = to_string(A);
            if(S[0] == S[S.length() - 1])
            {
                flag2 = true;
            }
            else
            {
                A++;
            }
        }
    }
    if(A == B)
    {
        S = to_tring(A);
        if(S[0] == S[S.length() - 1])
        {
            cout << "1" << endl;
        }
        else
        {
            cout << "0" << endl;
        }

    }
    else
    {
        string a, b;
        a = to_string(A);
        b = to_string(B);
        while(a.length() != b.length())
        {
            int p = ord(b[0]);
            long long h = 0;
            for(int i = 1; i < b.length() - 2; ++i)
            {
                h = h*10 + ord(b[i]);
            }
            ans = ans + p * (h + 1);
            int k = b.length();
            b = "";
            for(int i = 0; i < k - 1; ++i)
            {
                b.push_back('9');
            }
        }
        if(a[0] != b[0])
        {
            int p = b[0] - a[0];
            long long h = 0;
            for(int i = 1; i < b.length() - 2; ++i)
            {
                h = h*10 + ord(b[i]);
            }
            ans = ans + p * (h + 1);

        }
    }
    return 0;
}
