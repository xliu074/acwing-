//朴素dfs解法2
#include<iostream>
using namespace std;

const int N = 20;
int n;
char g[N][N];
bool col[N], row[N], dg[N], udg[N];

void dfs(int x, int y, int u)
{
    if(y == n) y = 0, x ++;
    if(x == n)
    {
        if(u == n)
        {
            for(int i = 0; i < n; i ++ )puts(g[i]);
            puts("");
        }
        return;
    }
    dfs(x, y + 1, u);
    if(!col[y] && !row[x] && !dg[x + y] && !udg[n - x + y])
    {
        g[x][y] = 'Q';
        col[y] = row[x] = dg[x + y] = udg[n - x + y] = true;
        dfs(x, y + 1, u + 1);
        col[y] = row[x] = dg[x + y] = udg[n - x + y] = false;
        g[x][y] = '.';
    }
}
int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++ )
        for(int j = 0; j < n; j ++ )
            g[i][j] = '.';
    
    dfs(0, 0, 0);
    return 0;
}