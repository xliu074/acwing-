#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

const int N = 100010, M = N * 2;
int h[N], e[M], ne[M], idx;
bool st[N];
int ans = N;//
int n;

void add(int a, int b)
{
    e[idx] = b; 
    ne[idx] = h[a];
    h[a] = idx ++ ;
}
int dfs(int u)
{
    st[u] = true;
    int size, sum;
    for(int i = h[u]; i != -1; i = ne[i] )
    {
        int j = e[i];
        if(st[j]) continue;

        int s = dfs(j);
        size = max(size, s);
        sum += s;
    }
    size = max(size, n - sum - 1);
    ans = min(ans, size);
    return sum + 1;
}
int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++ )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}