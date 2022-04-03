#include "my_list.h"
#include <iostream>
#include <sstream>
#include <time.h>
using namespace std;
my_list::my_list(double new_l_1, double new_l_5, double new_l_15)
    : l_1(new_l_1), l_5(new_l_5), l_15(new_l_15) {

    //读取当前系统的时间，并把时，分，秒分别赋值给h,m,s
    time_t now = time(NULL);
    tm *tm_t = localtime(&now);
    this->h = tm_t->tm_hour; //时
    this->m = tm_t->tm_min;  //分
    this->s = tm_t->tm_sec;  //秒
}
string my_list::get_time() const {
    //根据h,m,s生成易于阅读的时间戳字符串  xx时xx分xx秒
    stringstream ss;
    ss << this->h << "时" << this->m << "分" << this->s << "秒";
    return ss.str();
}
double my_list ::get_l_1() const {
    //获取过去1分钟负载
    return this->l_1;
}
double my_list ::get_l_5() const {
    //获取过去5分钟负载
    return this->l_5;
}
double my_list ::get_l_15() const {
    //获取过去15分钟负载
    return this->l_15;
}