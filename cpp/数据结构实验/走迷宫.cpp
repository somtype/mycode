#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stack.h"
#define maxN 10
ElemType NextPos(ElemType curpos, int i)
{
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    curpos.i += dir[i - 1][0];
    curpos.j += dir[i - 1][1];
    return curpos;
}
int MazePath(char (*maze)[maxN], ElemType start, ElemType end)
{
    stack S;
    initstack(S);
    ElemType curpos = start;
    do
    {
        ElemType e;
        if (!maze[curpos.i][curpos.j])
        {
            maze[curpos.i][curpos.j] = 1;
            curpos.di = 1;
            e = curpos;
            push(S, e);
            if (e.i == end.i && e.j == end.j){
                stack ans;
                initstack(ans);
                while(!emptystack(S)){
                    ElemType e;
                    pop(S,e);
                    push(ans,e);
                }
                while(!emptystack(ans)){
                    ElemType e;
                    pop(ans,e);
                    printf("(%d,%d)",e.i,e.j);
                }
                return 1;
            }
            curpos = NextPos(curpos, 1);
        }
        else
        {
            if (!emptystack(S))
            {
                pop(S, e);
                while (e.di == 4 && !emptystack(S))
                {
                    maze[e.i][e.j] = 1;
                    pop(S, e);
                }
            }
            if (e.di < 4)
            {
                e.di++;
                push(S, e);
                curpos = NextPos(e, e.di);
            }
        }
    }while(!emptystack(S));
    printf("NO");
    return 0;
}
int main()
{
    int n;
    char maze[maxN][maxN];
    scanf("%d", &n);
    memset(maze, 1, sizeof(maze));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char ch;
            scanf("%d", &ch);
            if (ch == 0)
                maze[i][j] = 0;
        }
    }
    ElemType start,end;
    start.i=1,start.j=1;
    end.i=n-2,end.j=n-2;
    MazePath(maze,start,end);
    return 0;
}