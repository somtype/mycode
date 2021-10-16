#include <iostream>
using namespace std;
class my_list {
  private:
    int h, m, s;           //时，分，秒
    double l_1, l_5, l_15; //三个负载

  public:
    my_list(double new_l_1 = 327, double new_l_5 = 327,
            double new_l_15 = 327); //构造函数，初始值设置为327是为了方便调试
    string get_time() const; //根据h,m,s生成时间戳字符串

    //下面三个函数用来获取负载
    double get_l_1() const;
    double get_l_5() const;
    double get_l_15() const;
};