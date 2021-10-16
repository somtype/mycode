#include "algorithm"
#include "cstring"
#include "iostream"
#define maxN 1010
using namespace std;
typedef struct {
    int *data;  //数据
    int *F;     // 频度
    int length; //数据长度
} FTable;
void initTable(FTable &Table) {
    //初始化数据表
    Table.length = 0;
    Table.data = (int *)malloc(maxN * sizeof(int));
    memset(Table.data, 0, sizeof(Table.data));
    Table.F = (int *)malloc(maxN * sizeof(int));
    memset(Table.F, 0, sizeof(Table.F));
}
void ReadInfo(FILE *fp, FTable &Table) {
    //读取数据
    fread(&Table.length, sizeof(int), 1, fp);
    fread(Table.data + 1, sizeof(int), Table.length, fp);
    fread(Table.F + 1, sizeof(int), Table.length, fp);
}
int WriteInfo(FILE *fp, FTable Table) {
    //写入数据
    fwrite(&Table.length, sizeof(int), 1, fp);
    fwrite(Table.data + 1, sizeof(int), Table.length, fp);
    fwrite(Table.F + 1, sizeof(int), Table.length, fp);
    return 1;
}
void AddInfo(FTable &Table) {
    //添加数据
    cout << "输入需要添加的数据数量\n";
    int n;
    cin >> n;
    cout << "输入需要添加的数据\n";
    for (int i = 1; i <= n; i++)
        cin >> Table.data[Table.length + i];
    Table.length += n;
    cout << endl;
}
int adjust(FTable &Table, int index) {
    //根据访问频度调整数据顺序
    int *dp, *fp, d, f;
    dp = Table.data + index;
    fp = Table.F + index;
    d = *dp;
    f = (*fp) + 1;
    while (fp > Table.F + 1 && *(fp - 1) < f) {
        *(fp) = *(fp - 1);
        *(dp) = *(dp - 1);
        fp--;
        dp--;
    }
    *dp = d;
    *fp = f;
    return dp - Table.data;
}
int srch(FTable &Table) {
    //带频度的顺序查找
    cout << "输入查找数据\n";
    int key;
    cin >> key;
    Table.data[0] = key;
    int i, result;
    for (i = Table.length; Table.data[i] != key; i--)
        ;
    if (i == 0) {
        cout << "数据不存在\n\n";
        return 0;
    }
    result = adjust(Table, i);
    cout << "所在位置\n";
    cout << result << endl << endl;
    return 1;
}
void Pnt(FTable Table) {
    //打印当前的数据表
    cout << "当前数据\n";
    cout << "数据     ";
    for (int i = 1; i <= Table.length; i++)
        printf("%-5d", Table.data[i]);
    cout << endl;
    cout << "访问频数 ";
    for (int i = 1; i <= Table.length; i++)
        printf("%-5d", Table.F[i]);
    cout << endl << endl;
}
int main() {
    FTable Table;
    initTable(Table);
    FILE *fp;
    if ((fp = fopen("basement", "rb")) == NULL) exit(1);
    ReadInfo(fp, Table);
    fclose(fp);
    while (1) {
        for (int i = 0; i < 30; i++)
            cout << "-";
        cout << endl;
        cout << "1、查找数据     2、添加数据     3、检查数据     "
                "(输入其他任意键结束)\n";
        char flag;
        cin >> flag;
        if (flag == '1') {
            srch(Table);
        } else if (flag == '2') {
            AddInfo(Table);
        } else if (flag == '3') {
            Pnt(Table);
        } else {
            cout << "退出\n";
            break;
        }
    }
    if ((fp = fopen("basement", "wb")) == NULL) exit(0);
    WriteInfo(fp, Table);
    fclose(fp);
    return 0;
}