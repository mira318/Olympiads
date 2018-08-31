#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
const int N = int(1e5) + 7;
vector<int> Graph[N];
int Tin[N];
int Tout[N];
int time, l;
bool Was[N];
int Ways[N];
int have, maxhave;
void dfs(int v, int p)
{
    time++;
    Tin[v] = time;
	for (int i = 0; i < Graph[v].size(); ++i)
    {
		int to = Graph[v][i];
		if (to != p)
        {
			dfs (to, v);
        }
	}
	time++;
	Tout[v] = time;
}
bool one (int a, int b)
{
	return Tin[a] <= Tin[b] && Tout[a] >= Tout[b];
}
void dfs2(int v, int now)
{
    now = now + Ways[v];
    maxhave = max(maxhave, now);
    for(int i = 0; i < Graph[v].size(); ++i)
    {
        if(!Was[Graph[v][i]])
            dfs(v, now);
    }
    now = now - Ways[v];
}
int main()
{
    //freopen("paths.in", "r", stdin);
    //freopen("paths.out", "w", stdout);
    have = 0;
    maxhave = 0;
    int n;
    cin >> n;
    int a, b;
    for(int i = 0; i < n - 1; ++i)
    {
        cin >> a >> b;
        a--;
        b--;
    }
    l = 1;
    while (1 << l <= n)
    {
        l++;
    }
    dfs(0, 0);
    int q, x, y;
    cin >> q;
    for(int i = 0; i < q; ++i)
    {
        cin >> x >> y;
        if(one(x, y))
        {
            have++;
            int v = -1;
            for(int i = 0; i < n; ++i)
            {
                if(Tin[i] > x && Tout[i] >= Tout[y])
                {
                   if(v == -1 || (Tin[v] > Tin[i]))
                   {
                       v = i;
                   }
                }
            }
            Ways[v]--;
            Ways[y]++;
        }
        else
        {
            if(one(y, x))
            {
                have++;
                int v = -1;
                for(int i = 0; i < n; ++i)
                {
                    if(Tin[i] > y && Tout[i] >= Tout[x])
                    {
                        if(v == -1 || (Tin[v] > Tin[i]))
                        {
                            v = i;
                        }
                    }
                }
                Ways[y, x]--;
                Ways[x]++;
            }
            else
            {
                Ways[x]++;
                Ways[y]++;
            }
        }
    }
    dfs2(0, have);
    cout << maxhave;
    return 0;
}
