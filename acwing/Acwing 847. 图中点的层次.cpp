#include<iostream>
#include<cstring>
using namespace std;

const int N = 100010, M = N * 2;
int h[N], e[M], ne[M], idx, n, m;
int q[N], d[N];
void add(int a, int b)
{
    e[idx] = b; ne[idx] = h[a]; h[a] = idx ++;
}

int bfs()
{
    int hh = 0, tt = 0;
    q[0] = 1;
    memset(d, -1, sizeof d);
    d[1] = 0;
    while(hh <= tt)
    {
        int t = q[hh ++ ];
        for(int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(d[j] == -1)
            {
                d[j] = d[t] + 1;
                q[++ tt] = j;
            }
        }
    }
    return d[n];
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for(int i = 0; i < m; i ++ )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }
    cout << bfs() << endl;
    return 0;
}