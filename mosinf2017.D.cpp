#include <iostream>
#include <bitset>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;
map<vector<int>, bool> M;
int main()
{
    freopen("output.txt", "w", stdout);
    for(int i = 0; i < 1025; ++i)
    {
        int sum1 = 0;
        int sum2 = 0;
        bitset<10> X(i);
        vector<int> Group1;
        vector<int> Group2;
        for(int j = 0; j < 10; ++j)
        {
            if(X[j] == 0)
            {
                sum1++;
                Group1.push_back(j);
            }
            else
            {
                sum2++;
                Group2.push_back(j);
            }
        }
        if(sum1 == sum2 && M.find(Group1) == M.end() && M.find(Group2) == M.end() && X[1] != X[2])
        {
            M[Group1] = true;
            M[Group2] = true;
            for(int j = 0; j < 10; ++j)
            {
                if(X[j] == 1)
                    cout << X[j] << " ";
                else
                    cout << 2 << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
