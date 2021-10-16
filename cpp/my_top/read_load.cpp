#include "read_load.h"
#include <fstream>
#include <iostream>
using namespace std;
int read_load(double &l_1, double &l_5, double &l_15) {
    ifstream loadavg("/proc/loadavg", ios::in); //打开文件
    if (!loadavg.good()) {
        cout << "Read error!" << endl;
        return 0;
    }
    loadavg >> l_1 >> l_5 >> l_15; //读取负载
    loadavg.close();
    return 1;
}