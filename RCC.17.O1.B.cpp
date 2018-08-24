#include <iostream>

using namespace std;
long long nod(long long q, long long k)
{
    while(q != 0 && k != 0)
    {
        if(q > k)
        {
            q = q % k;
        }
        else
        {
            k = k % q;
        }
    }
    if(k == 0)
    {
        return q;
    }
    else
    {
        return k;
    }
}
int main()
{
    int t;
    cin >> t;
    for(int n = 0; n < t; ++n)
    {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        long long q = nod(b, d);
        long long p = a*c/nod(a, c);
        cout << p << " " << q << endl;
    }
    return 0;
}
