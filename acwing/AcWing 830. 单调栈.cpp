#include<iostream>
using namespace std;
const int N = 100010;
int n, stk[N], tt;
int main()
{
    cin >> n;
    while(n --)
    {
        int x; 
        cin >> x;
        while(tt && stk[tt] >= x) tt --;
        if(!tt) cout << -1 << ' ';
        else cout << stk[tt] << ' ';
        stk[++ tt] = x;//注意进厂时机
    }
    return 0;
}
