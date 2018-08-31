#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>
using namespace std;
bool Was[1000];
long long bests;
int n;
vector<int> Ans;
int X[1000];
int Y[1000];
void easy(long long s, int x1, int y1, vector<int> Way)
{
    //for(int i = 0; i < Way.size(); ++i)
    //{
      //  cout << Way[i] << " ";
    //}
    //cout << endl;
    if(Way.size() == n)
    {
        if(bests > (s + fabs(x1) + fabs(y1)))
        {
            bests = s + fabs(x1) + fabs(y1);
            Ans = Way;
        }
    }
    else
    {
        if(s < bests)
        {
            for(int i = 0; i < n; ++i)
            {
                int next = i;
                if(!Was[i])
                {
                    Was[i] = true;
                    Way.push_back(next);
                    easy(s + fabs(X[i] - x1) + fabs(Y[i] - y1), X[i], Y[i], Way);
                    Way.erase(Way.end() - 1);
                    Was[i] = false;
                }
            }
        }
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    bests = 1e18;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> X[i] >> Y[i];
    }
    vector<int> Way;
    easy(0, 0, 0, Way);
    for(int i = 0; i < n; ++i)
    {
        cout <<Ans[i] + 1 << " ";
    }
    cout << "bests = " << bests << endl;
    return 0;
}
