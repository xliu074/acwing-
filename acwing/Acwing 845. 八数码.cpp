#include<iostream>
#include<algorithm>
#include<queue>
#include<unordered_map>

using namespace std;

int bfs(string state)
{
                
    queue<string> q;
    unordered_map<string, int> d;//存储交换次数
    q.push(state);//推入当前最新状态字符串
    d[state] = 0;//初始化步数
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};//定义移动方向数组
    string end = "12345678x";//定义目标字符串
    
    while(q.size())
    {
        auto t = q.front();//string
        q.pop();//状态出队
        
        if(t == end) return d[t];//return 最终步数；
        int distance = d[t];//定义当前步数为距离；
        int k = t.find('x');//confirm position
        int x = k / 3, y = k % 3;//字符串索引转二维数组下标
        
        for(int i = 0; i < 4; i ++ )//尝试上下左右移动
        {
            int a = x + dx[i], b = y + dy[i];//计算移动后坐标
            if(a >= 0 && a < 3 && b >= 0 && b < 3)//判断坐标是否合法
            {
                swap(t[a * 3 + b], t[k]);//合法即交换位置
                if(!d.count(t))//若当前字符串状态没有出现过
                {
                    d[t] = distance + 1;//状态数+1
                    q.push(t);//将当前字符串状态t入队
                }
                swap(t[a * 3 + b], t[k]);//交换其余方向
            }
        }
        
    }
    return -1;
    
}

int main()
{
    char s[2];
    
    string state;
    
    for(int i = 0; i < 9; i ++ )
    {
        cin >> s;
        state += *s;
    }
            
    cout << bfs(state) << endl;
    return 0;
}