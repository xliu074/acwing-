#include<iostream>

using namespace std;

const int N = 1000010;

int a[N], q[N];

int main()
{
    int k, n;
    cin >> n >> k;
    for(int i = 0; i < n; i ++) scanf("%d", &a[i]);
    int hh = 0, tt = 1;//just two marks
    for(int i = 0; i < n; i ++)
    {
        while(hh <= tt && a[q[tt]] >= a[i]) tt --;
        if(hh <= tt && i - k + 1 > q[hh]) hh ++;
        q[++ tt] = i;
        if(i >= k - 1) printf("%d ", a[q[hh]]);//i start from 0, so since i >= k - 1 -> print
    }
    puts("");
    hh = 0; tt = 1;
    for(int i = 0; i < n; i ++)
    {
        while(hh <= tt && a[q[tt]] <= a[i]) tt --;
        if(hh <= tt && i - k + 1 > q[hh]) hh ++;
        q[++ tt] = i;
        if(i >= k - 1) printf("%d ", a[q[hh]]);
    }
    return 0;
}
