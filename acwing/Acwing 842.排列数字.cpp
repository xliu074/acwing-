//dfs深度优先搜索
#include<iostream>
using namespace std;
const int N = 10;
int sta[N];//状态数组
int n;
int pr[N];//打印数组
//dfs
void dfs(int u)
{
    if(u == n)
    {
        for(int i = 0; i < n; i ++ ) printf("%d ", pr[i]);//当深搜到u==n时，打印出第一个打印数组
        puts("");
        return ;
    }
    for(int i = 1; i <= n; i ++ )
    {
        if(!sta[i])
        {
            pr[u] = i;
            sta[i] = true;
            dfs(u + 1);
            pr[u] = 0;//回溯
            sta[i] = false;//回溯
        }
    }
}
int main()
{
    cin >> n;
    dfs(0);
    return 0;
}