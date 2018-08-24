#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, pair<int, int> > > Place;
int Table[27][27];
int main()
{
    int t;
    cin >> t;
    for(int p = 0; p < t; ++p)
    {
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= m; ++j)
            {
                if(i == 1 && j == 1)
                {
                    continue;
                }
                else
                {
                    Place.push_back(make_pair(i - 1 + j - 1, make_pair(i, j)));
                }
            }
        }
        sort(Place.begin(), Place.end());
        int k = 0;
        for(int i = m*n - 1; i > 0; --i)
        {
            Table[Place[k].second.first][Place[k].second.second] = i;
            k++;
        }
        Table[1][1] = m*n;
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= m; ++j)
            {
                cout << Table[i][j] << " ";
            }
            cout << endl;
        }
        Place.clear();
    }
    return 0;
}
