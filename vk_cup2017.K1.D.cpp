#include<stdio.h>
#define mx 16383
using namespace std;

int arr[mx + 1];

void cnk(int a, int n, int k)
{
    if (n == k)
    {
        ++arr[a ^ ((mx << k) & mx)];
        return;
    }
    if (!k)
    {
        ++arr[a];
        return;
    }
    cnk(a ^ (1 << (14 - n)), n - 1, k - 1);
    cnk(a, n - 1, k);
}

int main()
{
    int n, k, a, res = 0;
    for (int i = 0; i < mx + 1; ++i)
    {
        arr[i] = 0;
    }
    scanf("%d %d\n", &n, &k);
    for (int i = n - 1; i >= 0; --i)
    {
        scanf("%d", &a);
        res += arr[a];
        cnk(a, 14, k);
    }
    printf("%d", res);
    return 0;
}
