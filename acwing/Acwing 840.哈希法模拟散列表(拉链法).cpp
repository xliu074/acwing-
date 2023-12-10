#include<iostream>
#include<cstring>
using namespace std;

const int N = 100003;

int h[N], e[N], ne[N], idx;
//insert
void insert(int x)
{
    int k = (x % N + N) % N;//find a right position
    e[idx] = x;//add node
    ne[idx] = h[k];//add *node
    h[k] = idx ++;//更新h[k]
    
}
//find
bool find(int x)
{
    int k = (x % N + N) % N;
    for(int i = h[k]; i != -1; i = ne[i])
    {
        if(e[i] == x)
            return true;
    }
    return false;
}
int main()
{
    int n;
    scanf("%d", &n);
    
    memset(h, -1, sizeof h);
    
    while(n -- )
    {
        int x;
        char op[2];
        scanf("%s%d", op, &x);
        if(!strcmp(op, "I")) insert(x);
        else
        {
            if(find(x)) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}
//sum_up:find_func调用时，自后向前遍历子单链表





