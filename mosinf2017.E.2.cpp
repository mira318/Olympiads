#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <set>
using namespace std;
int X[1001];
int Y[1001];
bool Was[1001];
vector<int> Way;
vector<int> Ans;
long long bests;
int n;
int go(int x1, int y1, long long s)
{
    //cout << "go( " << x1 << ", " << y1 << ", " << s << ")" << endl;
    if(Way.size() < n)
    {
        if(s < bests)
        {
            set<pair<long long, int> > To;
            for(int i = 0; i < n; ++i)
            {
                if(!Was[i])
                {
                    To.insert(make_pair(fabs(X[i] - x1) + fabs(Y[i] - y1), i));
                }
            }
            int have = To.size();
            for(int i = 0; i < min(3, have); ++i)
            {
                long long near = To.begin()->first;
                int v = To.begin()->second;
                To.erase(To.find(make_pair(near, v)));
                Way.push_back(v);
                Was[v] = true;
                go(X[v], Y[v], s + near);
                Way.erase(Way.end() - 1);
                Was[v] = false;
            }
        }
    }
    else
    {
        //cout << "hey2" << endl;
        if(s + fabs(x1) + fabs(y1) < bests)
        {
            bests = s + fabs(x1) + fabs(y1);
            for(int i = 0; i < Way.size(); ++i)
            {
                Ans.push_back(Way[i]);
            }
        }
    }
    //cout << "ended" << endl;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    bests = 2*1e18;
    cin >> n;
    //cout << "hey" << endl;
    for(int i = 0; i < n; ++i)
    {
        cin >> X[i] >> Y[i];
    }
    go(0, 0, 0);
    cout << "hey" << endl;
    for(int i = 0; i < n; ++i)
    {
        cout << Ans[i] + 1 << " ";
    }
    cout << endl;
    cout << "bests = " << bests << endl;
    return 0;
}
