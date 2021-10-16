#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
class block {
  private:
    double length, width;

  public:
    block(double a = 1, double b = 1) : length(a), width(b) {}
    void set(double a, double b) {
        length = a;
        width = b;
    }
    double getL() const {
        return length;
    }
    double getW() const {
        return width;
    }
    double getArea() const {
        return length * width;
    }
    bool operator<(const block &tmp) const {
        return (this->length * this->width) < (tmp.length * tmp.width);
    }
    bool operator>(const block &tmp) const {
        return (this->length * this->width) > (tmp.length * tmp.width);
    }
    friend ostream &operator<<(ostream &out, const block &tmp) {
        out << '(' << tmp.length << ',' << tmp.width << ')';
        return out;
    }
};

double total, max_use = 0, B[1010];
int status[1010] = {0};
int max_status[1010] = {0};
bool place(priority_queue<block, vector<block>, less<block>> qs, block *bs,
           int m) {
    block tmp = qs.top();
    return tmp.getL() >= bs[m].getL() && tmp.getW() >= bs[m].getW();
}
int packing(priority_queue<block, vector<block>, less<block>> qs, block *bs,
            int m, int n) {
    if (m == n + 1) {
        double left = 0;
        while (!qs.empty()) {
            left += qs.top().getArea();
            qs.pop();
        }
        double use = total - left;
        if (use > max_use) {
            max_use = use;
            memcpy(max_status, status, sizeof(status));
        }
        return 1;
    }
    for (; m <= n; m++) {
        block tmp = qs.top();
        if (place(qs, bs, m)) { //约束条件
            status[m] = 1;      //记录石块已切割
            priority_queue<block, vector<block>, less<block>> qa = qs;
            block new1(bs[m].getL(), tmp.getW() - bs[m].getW()),
                new2(tmp.getL() - bs[m].getL(), tmp.getW()); //两块较小的石板
            qa.pop();
            if (new1.getArea() != 0)
                qa.push(new1);
            if (new2.getArea() != 0)
                qa.push(new2);
            packing(qa, bs, m + 1, n);
            status[m] = 0;
        }
        B[m + 1] = B[m] - bs[m].getArea();
        if (B[m + 1] > max_use)
            packing(qs, bs, m + 1, n);
    }
    return 0;
}
int main() {
    priority_queue<block, vector<block>, less<block>> qs;
    block bs[1010];
    block tmp(10, 10);
    double l, w;
    cin >> l >> w;
    tmp.set(l, w);
    total = tmp.getArea();
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> l >> w;
        bs[i].set(l, w);
        B[1] += bs[i].getArea();
    }
    sort(bs + 1, bs + n + 1, greater<block>());
    qs.push(tmp);
    packing(qs, bs, 1, n);
    for (int i = 1; i <= n; i++) {
        cout << max_status[i] << ' ';
    }
    cout << endl;
    cout << "result: " << max_use << ' ' << max_use / total << endl;
    return 0;
}
