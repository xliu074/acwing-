#include<iostream>
using namespace std;
const int N = 100010;
int skt[N], hh, tt = -1, m;
int main ()
{
    cin >> m;
    while(m --)
    {
        string op;
        int x;
        cin >> op;
        if(op == "push")
        {
            cin >> x;
            skt[++ tt] = x;
        }
        else if(op == "pop") hh ++;//fifo
        else if(op == "empty") cout << ((hh <= tt) ? "NO" : "YES") << endl;
        else cout << skt[hh] << endl;
    }
    return 0;
}
