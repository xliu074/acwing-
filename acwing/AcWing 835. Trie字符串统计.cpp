#include<iostream>
using namespace std;
const int N = 100010;
int son[N][26], cont[N], idx;
char str[N];
void insert(char* str)
{
    int p = 0;
    for(int i = 0; str[i]; i ++)
    {
        int u = str[i] - 'a';
        if(!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];//update p as a son 
        
    }
    cont[p] ++;//以p为终点的个数++
}
int query(char* str)
{
    int p = 0;
    for(int i = 0; str[i]; i ++)
    {
        int u = str[i] - 'a';
        if(!son[p][u]) return 0;
        p = son[p][u];
        
    }
    return cont[p];
}

int main()
{
    int n;
    cin >> n;
    while(n --)
    {
        char op[2], str[N];
        scanf("%s%s ", op, str);//指针
        if(*op == 'I') insert(str);
        else printf("%d\n", query(str));
    }
    return 0;
    
    
}

