//这道题目估计每一句话都有注释,QwQ
//一边写题目,一边写注释,感觉思路清晰地很啊!
#include <bits/stdc++.h>                                //万能头文件
using namespace std;                                    //命名空间
#define N 510                                           //最大数据范围
#define fir(i, a, b) for (int i = a; i <= b; i++)       // for循环,宏定义
const int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0}; //普通的方向数组
struct rec {
    int x, y,
        lie; // x坐标,y坐标,lie表示放置的方式,以及上下放置,还是左右放置.0为竖着放置,1,2为上下,左右放置
};
char s[N][N];            //地图
rec st, ed;              //起点和终点
int n, m, d[N][N][3];    // d数组记录步数
queue<rec> q;            //状态的队列
bool valid(int x, int y) //判断在不在地图的边界内
{
    return x >= 1 && x <= n && y >= 1 &&
           y <= m; //如果都满足了,说明的确在地图的边界内
}
void st_ed() //找起点and终点
{
    fir(i, 1, n) fir(j, 1, m) //遍历地图
        if (s[i][j] == 'O')   //终点
    {
        ed.x = i; //初始化
        ed.y = j;
        ed.lie = 0;    //为0是1*1站着的方式
        s[i][j] = '.'; //可以看作是硬地被利用.(题目描述)
    }
    else if (s[i][j] == 'X') //起点
    {
        fir(k, 0, 3) //四个方向
        {
            int x = i + dx[k], y = j + dy[k]; //四个方向临时变量
            if (valid(x, y) && s[x][y] == 'X') //两个相邻的起点.(题目描述)
            {
                st.x = min(i, x);        //选择最小的那个
                st.y = min(j, y);        //选择最小的那个
                st.lie = k < 2 ? 1 : 2;  // 1为左右,2为上下
                s[i][j] = s[x][y] = '.'; //统统看作是硬地.(题目描述)
                break; //因为只有两个,现在找到了,可以退出这个四个方向的循环了
            }
            if (s[i][j] == 'X') //发现只有一个起点
            {
                st.x = i; //初始化
                st.y = j;
                st.lie = 0; //为0是1*1站着的方式
            }
        }
    }
}
bool check(rec Next) //判断这个滚动是否合法,满足题意
{
    if (!valid(Next.x, Next.y)) //不在地图的范围内
        return 0;
    if (s[Next.x][Next.y] == '#') //这个位置是禁地,不可以(题目描述)
        return 0;
    if (Next.lie == 0 &&
        s[Next.x][Next.y] !=
            '.') //如果是1*1直立方式,但是脚下是易碎地面,不可以(题目描述)
        return 0;
    if (Next.lie == 1 &&
        s[Next.x][Next.y + 1] ==
            '#') //如果说是上下横放置的话,且下面是禁地,不可以(题目描述)
        return 0;
    if (Next.lie == 2 &&
        s[Next.x + 1][Next.y] ==
            '#') //如果说是左右横放置的话,且右边是禁地,不可以(题目描述)
        return 0;
    return 1; //全部都满足了条件
}
const int Next_x[3][4] = {
    {0, 0, -2, 1},
    {0, 0, -1, 1},
    {0, 0, -1, 2}}; //在横竖两种摆放方式下的,x坐标的四个方向走法.
const int Next_y[3][4] = {
    {-2, 1, 0, 0},
    {-1, 2, 0, 0},
    {-1, 1, 0, 0}}; //在横竖两种摆放方式下的,y坐标的四个方向走法.
const int Next_lie[3][4] = {
    {1, 1, 2, 2}, {0, 0, 1, 1}, {2, 2, 0, 0}}; //不同走法下,横竖坐标的变化.
int bfs() {
    fir(i, 1, n)         // x坐标
        fir(j, 1, m)     // y坐标
        fir(k, 0, 2)     // 0,1,2三种摆放方式
        d[i][j][k] = -1; //坐标(i,j)的第k种摆放方式,初始化为-1
    while (q.size())     //将上一次剩余的状态,全部清空
        q.pop();
    d[st.x][st.y][st.lie] = 0; //起点步数为0
    q.push(st);                //将起点压入队列
    while (q.size())           //当还有状态时
    {
        rec now = q.front(); //取出队头状态
        q.pop();             //以及拿出来了,需要弹出了
        fir(i, 0, 3)         //四个方向开始枚举
        {
            rec Next;                            //定义下一步的点
            Next.x = now.x + Next_x[now.lie][i]; // x坐标进入下一步
            Next.y = now.y + Next_y[now.lie][i]; // y坐标进入下一步
            Next.lie = Next_lie[now.lie][i];     // lie进入下一步
            if (check(Next) &&
                d[Next.x][Next.y][Next.lie] == -1) //如果这一步都满足了条件
            {
                d[Next.x][Next.y][Next.lie] =
                    d[now.x][now.y][now.lie] + 1; //上一步的步数+1
                q.push(Next); //将这个状态压入队列之中
                if (Next.x == ed.x && Next.y == ed.y &&
                    Next.lie == ed.lie) //发现这个点是终点
                    return d[Next.x][Next.y][Next.lie]; //返回最小步数
            }
        }
    }
    return -1; //无解
}
int main() {
    while (cin >> n >> m && n && m) //如果当前还在读入
    {
        fir(i, 1, n) scanf("%s", s[i] + 1); //每一个s[i]字符串都从第一位开始读入
        st_ed();                            //找起点和终点
        int ans = bfs();                    //搜索答案
        if (ans == -1)                      //找不到答案
            printf("Impossible\n"); //无解
        else
            printf("%d\n", ans); //输出最小步数
    }
    return 0; //程序完美结束
}