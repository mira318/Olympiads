#include <iostream>
#include <vector>
using namespace std;
const int N = int(1e5) + 7;
int Mass[N];
vector <int> Pos;
vector <int> Ch;
bool Was[N];
int main()
{
    int t;
    cin >> t;
    for(int p = 0; p < t; ++p)
    {
        int n;
        cin >> n;
        for(int i = 1; i <= n; ++i)
        {
            cin >> Mass[i];
            if(Mass[i] == 0)
            {
                Pos.push_back(i);
            }
            else
            {
                Was[Mass[i]] = true;
            }
        }
        for(int i = 1; i <= n; ++i)
        {
            if(!Was[i])
            {
                Ch.push_back(i);
            }
        }
        //cout << "Pos:" << endl;
        //for(int i = 0; i < Pos.size(); ++i)
        //{
          //  cout << Pos[i] << " ";
        //}
        //cout << endl;
        //cout << "Ch:" <<  endl;
       // for(int i = 0; i < Ch.size(); ++i)
        //{
          //  cout << Ch[i] << " ";
        //}
        //cout << endl;
        int l, r;
        l = 0;
        r = Pos.size() - 1;
        for(int i = 0; i < Ch.size(); ++i)
        {
            if(i % 2 == 0)
            {
                Mass[Pos[r]] = Ch[i];
                r--;
            }
            else
            {
                Mass[Pos[l]] = Ch[i];
                l++;
            }
        }
        for(int i = 1; i <= n; ++i)
        {
            cout << Mass[i] << " ";
        }
        cout << endl;
        Pos.clear();
        Ch.clear();
        for(int i = 1; i <= n; ++i)
        {
            Was[i] = false;
        }
    }
    return 0;
}
