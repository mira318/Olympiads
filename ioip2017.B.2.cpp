#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <cstdio>
using namespace std;
const int N = int(1e5) + 7;
int Am[N];
int m, n;
multiset<int> All;
vector<int> Click;
bool check(int k)
{
    //cout << "check(" << k << ")" << endl;
    int need = m;
    //cout << "m = " << m << endl;
    //cout << "((k*(k - 1))/2) = " << ((k*(k - 1))/2) << endl;
    if(m < ((k*(k - 1))/2))
    {
        return false;
    }
    //cout << "well" << endl;
    for(int i = 0; i < n; ++i)
    {
        All.insert(-Am[i]);
    }
    for(int i = 0; i < k; ++i)
    {
        //cout << "i = " << i << endl;
        int v = *All.begin();
        //cout << "v = " << v << endl;
        All.erase(All.find(v));
        Click.push_back(v);
    }
    for(int i = 0; i < k; ++i)
    {
        Click[i] = Click[i] + k - 1;
        if(Click[i] > 0)
        {
            Click.clear();
            All.clear();
            return false;
        }
        All.insert(Click[i]);
    }
    need = need - (k*(k - 1)/2);
    while(need > 0)
    {
        int v = *All.begin();
        //cout << "v = " << v << endl;
        All.erase(All.find(v));
        int u = *All.begin();
        //cout << "u = " << u << endl;
        All.erase(All.find(u));
        if(u < 0 && v < 0)
        {
            u++;
            v++;
            All.insert(u);
            All.insert(v);
            need--;
        }
        else
        {
            Click.clear();
            All.clear();
            return false;
        }
    }
    Click.clear();
    All.clear();
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("gotham.in", "r", stdin);
    freopen("gotham.out", "w", stdout);
    cin >> n >> m;
    if(n == 1)
    {
        if(m > 0)
        {
            cout << "-1";
        }
        else
        {
            cout << "1";
        }
        return 0;
    }
    for(int i = 0; i < n; ++i)
    {
        cin >> Am[i];
    }
    int l = 0;
    int r = n + 1;
    while(r - l > 1)
    {
        //cout << "l = " << l << endl;
        //cout << "r = " << r << endl;
        int mid = (l + r)/2;
        //cout << "mid = " << mid << endl;
        if(check(mid))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    if(l == 0)
    {
        cout << "-1";
    }
    else
    {
        cout << l;
    }
    return 0;
}
