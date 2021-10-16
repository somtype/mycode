#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define INITSIZE 100
#define MAXN 1010
#define INF 0x3f3f3f3f
struct Course {
    int crsID, credit, maxStu, Stu;
    char name[110], teacher[110];
    /*ID:课程编号  credit:学分  maxS:最大学生人数  S:已选学生人数
     * name[110]:课程名  teacher[110]:老师姓名*/
    struct Course *next;
};
struct selectedcrs {
    //用于学生已选课程的编号
    int crsID;
    struct selectedcrs *next;
};
struct Stuinfo {
    //记录学生信息
    int stuID;
    struct selectedcrs *crsIDlist;
    /*stuID:学号  crsIDlist:已选课程编号*/
    struct Stuinfo *next;
};
int stuID, stuNum = 0, crsNum = 0; // stuID:用于记录学号 stuNum:用于记录学生总数
                                   // crsNum:用于记录课程总数
struct Course *crsList = NULL;  //用于记录课程
struct Stuinfo *stuList = NULL; //用于记录学生信息
struct Stuinfo *person = NULL;  //用于定位当前学生
int isIncrsList(int crsID) {
    //判断课程是否存在
    struct Course *p;
    int flag = 0;
    for (p = crsList; p != NULL; p = p->next)
        if (p->crsID == crsID)
            flag = 1;
    return flag;
}
int isIncrsIDlist(int crsID) {
    //判断学生课表中是否有这门课
    struct selectedcrs *pc;
    for (pc = person->crsIDlist; pc != NULL; pc = pc->next) {
        if (pc->crsID == crsID)
            return 1;
    }
    return 0;
}
int readCourses(FILE *fp) {
    //读取课程信息
    struct Course *p1, *p2;
    crsList = p1 = p2 = NULL;
    while (!feof(fp)) {
        p2 = (struct Course *)malloc(sizeof(struct Course));
        char temp[110] = "\0";
        fgets(temp, 6, fp); //接收name:
        fscanf(fp, "%s", p2->name);
        fgetc(fp);
        fgets(temp, 9, fp); //接收teacher:
        fscanf(fp, "%s", p2->teacher);
        fgetc(fp);
        fgets(temp, 4, fp); //接收ID:
        fscanf(fp, "%d", &p2->crsID);
        fgetc(fp);
        fgets(temp, 8, fp); //接收credit:
        fscanf(fp, "%d", &p2->credit);
        fgetc(fp);
        fgets(temp, 8, fp); // maxStu:
        fscanf(fp, "%d", &p2->maxStu);
        fgetc(fp);
        fgets(temp, 5, fp); // stu:
        fscanf(fp, "%d", &p2->Stu);
        fgetc(fp);
        fgetc(fp);
        if (crsList == NULL)
            crsList = p2;
        else
            p1->next = p2;
        p1 = p2;
    }
    p1->next = NULL;
    return 0;
}
int readStudents(FILE *fp) {
    //读取学生信息
    struct Stuinfo *p1, *p2;
    stuList = p1 = p2 = NULL;
    while (!feof(fp)) {
        //建立学生选课信息的链表
        p2 = (struct Stuinfo *)malloc(sizeof(struct Stuinfo));
        char temp[110];
        fgets(temp, 4, fp); //接收ID:
        fscanf(fp, "%d", &p2->stuID);
        fgetc(fp);
        //读取该学生已选课程的编号
        fgets(temp, 18, fp); //接收selected courses:
        fgetc(fp);
        char ch;
        struct selectedcrs *pp1, *pp2;
        p2->crsIDlist = pp1 = pp2 = NULL;
        while ((ch = fgetc(fp)) != EOF) {
            fseek(fp, -1, 1);
            if (ch == '\n')
                break;
            //建立已选课程编号的链表
            pp2 = (struct selectedcrs *)malloc(sizeof(struct selectedcrs));
            fscanf(fp, "%d", &pp2->crsID);
            fgetc(fp);
            if (p2->crsIDlist == NULL)
                p2->crsIDlist = pp2;
            else
                pp1->next = pp2;
            pp1 = pp2;
        }
        fgetc(fp);
        pp1->next = NULL;
        if (stuList == NULL)
            stuList = p2;
        else
            p1->next = p2;
        p1 = p2;
    }
    p1->next = NULL;
    return 0;
}
int writeCourses() {
    //将课程信息写入文件
    FILE *fp;
    if ((fp = fopen("/mnt/d/code-c/week6/1.txt", "w")) == NULL)
        exit(1);
    int first = 1;
    struct Course *p;
    for (p = crsList; p != NULL; p = p->next) {
        if (first)
            first = 0;
        else
            fprintf(fp, "\n");
        fprintf(fp, "name:%s\n", p->name);
        fprintf(fp, "teacher:%s\n", p->teacher);
        fprintf(fp, "ID:%d\n", p->crsID);
        fprintf(fp, "credit:%d\n", p->credit);
        fprintf(fp, "maxStu:%d\n", p->maxStu);
        fprintf(fp, "stu:%d\n", p->Stu);
    }
    fclose(fp);
    rename("/mnt/d/code-c/week6/1.txt",
           "/mnt/d/code-c/week6/Courses'Information.txt");
    return 0;
}
int writeStudents() {
    //将学生信息写入文件
    FILE *fp;
    if ((fp = fopen("/mnt/d/code-c/week6/2.txt", "w")) == NULL)
        exit(1);
    int first = 1;
    struct Stuinfo *p;
    for (p = stuList; p != NULL; p = p->next) {
        if (first)
            first = 0;
        else
            fprintf(fp, "\n");
        fprintf(fp, "ID:%d\n", p->stuID);
        struct selectedcrs *pc;
        fprintf(fp, "selected courses:\n");
        for (pc = p->crsIDlist; pc != NULL; pc = pc->next) {
            fprintf(fp, "%d\n", pc->crsID);
        }
    }
    fclose(fp);
    rename("/mnt/d/code-c/week6/2.txt",
           "/mnt/d/code-c/week6/Students'Information.txt");
    return 0;
}
int AddCourse() {
    int crsID, credit, maxStu;
    char name[110], teacher[110];
    printf("课程编号:");
    scanf("%d", &crsID);
    getchar();
    if (isIncrsList(crsID)) {
        printf("课程编号已存在\n");
        return -1;
    }
    printf("课程名称:");
    scanf("%s", name);
    getchar();
    printf("科任老师:");
    scanf("%s", teacher);
    getchar();
    printf("学分:");
    scanf("%d", &credit);
    getchar();
    printf("最大学生人数:");
    scanf("%d", &maxStu);
    getchar();
    struct Course fakehead, *p, *p2;
    fakehead.next = crsList;
    for (p = &fakehead; p->next != NULL; p = p->next)
        ;
    p2 = (struct Course *)malloc(sizeof(struct Course));
    p2->next = NULL;
    p2->crsID = crsID;
    memcpy(p2->name, name, sizeof(name));
    memcpy(p2->teacher, teacher, sizeof(teacher));
    p2->credit = credit;
    p2->maxStu = maxStu;
    p2->Stu = 0;
    p->next = p2;
    crsList = fakehead.next;
    printf("添加课程成功\n");
    return 0;
}
int DeleteCourse() {
    int crsID;
    printf("课程编号:");
    scanf("%d", &crsID);
    getchar();
    if (!isIncrsList(crsID)) {
        printf("课程不存在\n");
        return -1;
    }
    //删除这门课↓↓↓
    struct Course fakehead, *p;
    fakehead.next = crsList;
    for (p = &fakehead; p->next != NULL; p = p->next)
        if (p->next->crsID == crsID) {
            p->next = p->next->next;
            crsList = fakehead.next;
            break;
        }
    //从选了这门课的学生的课表中退选本课↓↓↓
    struct Stuinfo *ps;
    for (ps = stuList; ps != NULL; ps = ps->next) {
        struct selectedcrs fakehead, *pc;
        fakehead.next = ps->crsIDlist;
        for (pc = &fakehead; pc->next != NULL; pc = pc->next) {
            if (pc->next->crsID == crsID) {
                pc->next = pc->next->next;
                ps->crsIDlist = fakehead.next;
                break;
            }
        }
    }
    printf("取消课程成功\n");
    return 0;
}
int SeletCourse() {
    int crsID;
    printf("课程编号:");
    scanf("%d", &crsID);
    getchar();
    if (!isIncrsList(crsID)) {
        //判断课程是否存在
        printf("课程不存在\n");
        return -1;
    }
    if (isIncrsIDlist(crsID)) {
        //判断是否已选择这门课程
        printf("您已选该课程\n");
        return -1;
    }
    struct Course *p;
    for (p = crsList; p->crsID != crsID; p = p->next)
        //定位课表所在位置，判断是否可选
        ;
    if (p->Stu >= p->maxStu) {
        printf("课程人数已满\n");
        return -1;
    }
    //所有条件均满足，开始选课
    p->Stu++;
    struct selectedcrs fakehead, *pc, *pc2;
    fakehead.next = person->crsIDlist;
    for (pc = &fakehead; pc->next != NULL; pc = pc->next)
        //定位课表末尾
        ;
    //添加新课程↓↓↓
    pc2 = (struct selectedcrs *)malloc(sizeof(struct selectedcrs));
    pc2->next = NULL;
    pc2->crsID = crsID;
    pc->next = pc2;
    person->crsIDlist = fakehead.next;
    printf("选课成功\n");
    return 0;
}
int DropCourse() {
    int crsID;
    printf("课程编号:");
    scanf("%d", &crsID);
    getchar();
    struct selectedcrs fakehead, *pc;
    fakehead.next = person->crsIDlist;
    for (pc = &fakehead; pc->next != NULL; pc = pc->next) {
        if (isIncrsIDlist(pc->next->crsID)) {
            //判断是否选了该门课，若是，则退课
            pc->next = pc->next->next;
            person->crsIDlist = fakehead.next;
            //定位所选课程,并减少该门课程已选课的人数
            struct Course *p;
            for (p = crsList; p->crsID != crsID; p = p->next)
                ;
            p->Stu--;
            printf("退课成功\n");
            return 0;
        }
    }
    printf("您未选该课程\n");
    return -1;
}
int CheckOptionalCourse() {
    //查询可选课程
    struct Course *p;
    for (p = crsList; p != NULL; p = p->next) {
        if (p->Stu < p->maxStu && !isIncrsIDlist(p->crsID)) {
            //已选人数少于最大人数，且没有选的课程
            printf("%d   %s\n", p->crsID, p->name);
        }
    }
    return 0;
}
int CheckSelectedCourse() {
    //查询已选课程
    struct Course *p;
    for (p = crsList; p != NULL; p = p->next) {
        if (isIncrsIDlist(p->crsID))
            printf("%d   %s\n", p->crsID, p->name);
    }
    return 0;
}
int main() {
    FILE *fpSinfo, *fpCinfo;
    if ((fpCinfo = fopen("/mnt/d/code-c/week6/Courses'Information.txt",
                         "r+")) == NULL)
        exit(1);
    if ((fpSinfo = fopen("/mnt/d/code-c/week6/Students'Information.txt",
                         "r+")) == NULL)
        exit(1);
    readCourses(fpCinfo);
    readStudents(fpSinfo);
    printf("请输入学号：\n");
    scanf("%d", &stuID);
    getchar();
    //判断学号是否正确
    int flag = 0;
    for (struct Stuinfo *p = stuList; p != NULL; p = p->next)
        if (p->stuID == stuID) {
            flag = 1;
            person = p;
            break;
        }
    if (!flag) {
        printf("学号错误\n");
        return 0;
    }
    //进入系统
    for (int i = 0; i < 30; i++)
        printf("-");
    printf("\n");
    for (int i = 0; i < 10; i++)
        printf(" ");
    printf("学生选课系统\n");
    for (int i = 0; i < 30; i++)
        printf("-");
    printf("\n");
    while (1) {
        printf("请选择功能（按其他任意键结束）：\n");
        printf(
            "1、查询可选课程  2、选课  3、查询已选课程  4、退课  5、新增课程  "
            "6、删除课程\n");
        char ch = getchar();
        getchar();
        if (ch == '1')
            CheckOptionalCourse();
        else if (ch == '2')
            SeletCourse();
        else if (ch == '3')
            CheckSelectedCourse();
        else if (ch == '4')
            DropCourse();
        else if (ch == '5')
            AddCourse();
        else if (ch == '6')
            DeleteCourse();
        else
            break;
    }
    fclose(fpCinfo);
    fclose(fpSinfo);
    writeCourses();
    writeStudents();
    printf("退出成功\n");
    return 0;
}