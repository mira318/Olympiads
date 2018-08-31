#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
int X[1001];
int Y[1001];
vector<int> State;
long long E;
int n;
long double T;
long long minE;
map<long long, vector<int> > M;
long long countE()
{
    long long En = 0;
    En = En + fabs(X[State[0]]) + fabs(Y[State[0]]);
    for(int i = 1; i < n; ++i)
    {
        En = En + fabs(X[State[i]] - X[State[i - 1]]) + fabs(Y[State[i]] - Y[State[i - 1]]);
    }
    En = En + fabs(X[State[n - 1]]) + fabs(Y[State[n - 1]]);
    return En;
}
long double getver(long long delta)
{
    return exp(-delta/T);
}
void let(long double tmax, long double tmin)
{
    int k = 1;
    while(T >= tmin)
    {
        int i = rand() % n;
        int j = rand() % n;
        swap(State[i], State[j]);
        long long En = countE();
        if(En < E)
        {
            E = En;
            minE = min(minE, E);
            M[minE] = State;
        }
        else
        {
            long double ver = getver(En - E);
            long double need = rand()/RAND_MAX;
            if(need < ver)
            {
                E = En;
            }
            else
            {
                swap(State[i], State[j]);
            }
        }
        T = (tmax*0.1)/k;
        if(T < tmin)
        {
            cout << "E = " << E << endl;
            for(int i = 0; i < n; ++i)
            {
                cout << State[i] << " ";
            }
            cout << endl;
        }
        k++;
    }
}
int main()
{
    cout.precision(10);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    srand(time(0));
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> X[i] >> Y[i];
        State.push_back(i);
    }
    random_shuffle(State.begin(), State.end());
    E = E + fabs(X[1]) + fabs(Y[1]);
    for(int i = 2; i <= n; ++i)
    {
        E = E + fabs(X[i] - X[i - 1]) + fabs(Y[i] - Y[i - 1]);
    }
    E = E + fabs(X[n]) + fabs(Y[n]);
    minE = E;
    M[minE] = State;
    T = 10000;
    let(10000, 0.00001);
    cout << "minE = " << minE << endl;
    cout << "M[minE]:" << endl;
    for(int i = 0; i < n; ++i)
    {
        cout << M[minE][i] << " ";
    }
    cout << endl;
    return 0;
}
