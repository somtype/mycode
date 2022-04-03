#include "Stack.h"
#include "iostream"
#include "vector"
using namespace std;
int st[30], n, nsize;
vector<int> ans;
Stack Station;
int trn = 1;
void dfs() {
    if (nsize >= 20)
        return;
    if (ans.size() == n) {
        nsize++;
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i];
        cout << endl;
        return;
    }
    if (!StackEmpty(Station)) {
        int e;
        pop(Station, e);
        ans.push_back(e);
        dfs();
        e = ans.back();
        push(Station, e);
        ans.pop_back();
    }
    if (trn <= n) {
        int e;
        push(Station, trn);
        trn++;
        dfs();
        trn--;
        pop(Station, e);
    }
}
int main() {
    cin >> n;
    dfs();
    return 0;
}