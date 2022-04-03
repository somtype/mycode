#include "my_list.h"
#include "read_load.h"
#include <iostream>
using namespace std;
int main() {
    double l_1, l_5, l_15;
    read_load(l_1, l_5, l_15);     //读取负载
    my_list list1(l_1, l_5, l_15); //生成数据结构
    cout << "Content-Type:text/html;charset=utf-8;" << endl << endl;

    cout << "<table border=\" 1 \">";
    cout << "<tr>";
    cout << "<th>" << "时间" << "</th>";
    cout << "<th>" << "1分钟" << "</th>";
    cout << "<th>" << "5分钟" << "</th>";
    cout << "<th>" << "15分钟" << "</th>";
    cout << "</tr>";
    cout << "<tr>";
    cout << "<th>" << list1.get_time() << "</th>";
    cout << "<th>" << list1.get_l_1() << "</th>";
    cout << "<th>" << list1.get_l_5() << "</th>";
    cout << "<th>" << list1.get_l_15() << "</th>";
    cout << "</tr>";
    cout << "</table>";
    return 0;
}