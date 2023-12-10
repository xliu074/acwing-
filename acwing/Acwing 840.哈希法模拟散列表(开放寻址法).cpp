#include<iostream>
#include<cstring>
using namespace std;

const int N = 200003, null = 0x3f3f3f3f;//表示无穷大的正整数

int h[N];

int find(int x)
{
    int t = (x % N + N) % N;
    while(h[t] != null && h[t] != x)
    {
        t ++;
        if(t == N) t = 0;
    }
    return t;
}

int main()
{
    int n;
    scanf("%d", &n);
    
    memset(h, 0x3f, sizeof h);
    while(n -- )
    {
        char op[2];
        int x;
        scanf("%s%d", op, &x);
        if(!strcmp(op, "I")) h[find(x)] = x;
        else
        {
            if(h[find(x)] == null) puts("No");
            else puts("Yes");
        }
    }
    return 0;
}





