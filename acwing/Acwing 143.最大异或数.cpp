#include<iostream>
#include<algorithm>//max
using namespace std;

const int N = 100010, M = 3100010;
int n;
int a[N], son[M][2], idx;

void insert(int x)
{
    int p = 0;
    for(int i = 30; ~i; i --)
    {
        int s = son[p][x >> i & 1];
        if(!s) son[p][x >> i & 1] = ++ idx;
        p = son[p][x >> i & 1];
    }
}
int search(int x)
{
    int p = 0, res = 0;
    for(int i = 30; ~i; i --)
    {
        int s = x >> i & 1;
        if(son[p][!s])
        {
            res += 1 << i;//先<<后+；
            p = son[p][!s];
        }
        else p = son[p][s];
    }
    return res;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        scanf("%d", &a[i]);
        insert(a[i]);
    }
    int res = 0;
    for(int i = 0; i < n; i ++)
    {
        res = max(res, search(a[i]));
    }
    printf("%d", res);
    return 0;
}

