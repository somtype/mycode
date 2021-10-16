#include "stdio.h"
struct Student
{
    char num[200], name[30];
    int score[3];
};
int main()
{
    void print(struct Student * s);
    struct Student s[5];
    int i;
    for (i = 0; i <= 0; i++)
    {
        scanf("%s%s", (s+i)->num, (s+i)->name);
        for (int j = 0; j <= 2; j++)
        {
            scanf("%d", (s+i)->score+j);
        }
    }
    print(s);
    return 0;
}
void print(struct Student *s)
{
    int i, j;
    for (i = 0; i <= 0; i++)
    {
        puts((s + i)->num);
        puts((s + i)->name);
        for (j = 0; j <= 2; j++)
        {
            printf("%d ", *((s + i)->score+j));
        }
        printf("\n");
    }
}