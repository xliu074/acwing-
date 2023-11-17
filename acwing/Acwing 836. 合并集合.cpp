#include<iostream>

using namespace std;

const int N = 100010;

int p[N];
int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);//递归
    return p[x];
}
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) p[i] = i;
    while(m --)
    {
        char op[2];//技巧,防空格
        int a, b;
        scanf("%s%d%d", op, &a, &b);
        if(*op == 'M')//*op == op[0]
        {
            p[find(a)] = find(b);//
        }
        else
        {
            if(find(a) == find(b)) puts("Yes");
            else puts("No");
        }
        
    }
    return 0;
}

