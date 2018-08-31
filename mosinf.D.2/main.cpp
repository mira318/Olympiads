#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("output.txt", "w", stdout);
    for(int i = 0; i < 25; ++i)
    {
        cout << " i = " << i << endl;
        for(int j = 4; j > 0; --j)
        {
            //cout << "j = " << j << endl;
            cout << j << " ";
        }
    }
    return 0;
}
