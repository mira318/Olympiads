#include <iostream>

using namespace std;
char A[1007][1007];
int main()
{
    int n, m, k, posi, posj;
    cin >> n >> m >> k;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cin >> A[i][j];
            if(A[i][j] == 'X')
            {
                posi = i;
                posj = j;
            }
        }
    }
    //cout << "posi = " << posi << endl;
    //cout << "posj = " << posj << endl;
    if(k % 2 == 1)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    if(posi == n - 1 || (posi < n - 1 && A[posi + 1][posj] != '.'))
    {
        //cout << "1" << endl;
        if(posj == 0 || (posj > 0 && A[posi][posj - 1] != '.'))
        {
            //cout << "2" << endl;
            if(posj == m - 1 || (posj < m - 1 && A[posi][posj + 1] != '.'))
            {
                //cout << "3" << endl;
                if(posi == 0 || (posi > 0 && A[posi - 1][posj] != '.'))
                {
                    //cout << "4" << endl;
                    cout << "IMPOSSIBLE";
                    return 0;
                }
            }
        }
    }
    string Ans = "";
    int time = 0;
    int need = k/2;
    while(time < need)
    {
        if(posi < n - 1 && A[posi + 1][posj] != '*')
        {
            Ans.push_back('D');
            posi++;
        }
        else
        {
            if(posj > 0 && A[posi][posj - 1] != '*')
            {
                Ans.push_back('L');
                posj--;
            }
            else
            {
                if(posj < m - 1 && A[posi][posj + 1] != '*')
                {
                    Ans.push_back('R');
                    posj++;
                }
                else
                {
                    if(posi > 0 && A[posi - 1][posj] != '*')
                    {
                        Ans.push_back('U');
                        posi--;
                    }
                }
            }
        }
        time++;
    }
    cout << Ans;
    for(int i = Ans.length() - 1; i >= 0; --i)
    {
        //cout << "i = " << i << endl;
        if(Ans[i] == 'D')
        {
            cout << 'U';
        }
        if(Ans[i] == 'U')
        {
            cout << 'D';
        }
        if(Ans[i] == 'L')
        {
            cout << 'R';
        }
        if(Ans[i] == 'R')
        {
            cout << 'L';
        }
    }
    return 0;
}
