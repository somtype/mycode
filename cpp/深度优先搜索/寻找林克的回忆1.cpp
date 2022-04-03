#include "algorithm"
#include "cstring"
#include "iostream"
#include "vector"
#define For(a, begin, end) for (register int a = begin; a <= end; ++a)
#define rFor(a, end, begin) for (register int a = end; a >= begin; --a)
using namespace std;
int Sudoku[10][10];
bool row[10][10], col[10][10], grid[10][10];
bool dfs(int r, int c) {
    if (r == 9)
        return true;
    bool flag = false;
    if (Sudoku[r][c]) {
        if (c == 8)
            flag = dfs(r + 1, 0);
        else
            flag = dfs(r, c + 1);
        return flag;
    }
    int k = (r / 3) * 3 + c / 3;
    For(i, 1, 9) {
        if (!row[r][i] && !col[c][i] && !grid[k][i]) {
            row[r][i] = col[c][i] = grid[k][i] = true;
            Sudoku[r][c] = i;
            if (c == 8)
                flag = dfs(r + 1, 0);
            else
                flag = dfs(r, c + 1);
            if (flag)
                return true;
            Sudoku[r][c] = 0;
            row[r][i] = col[c][i] = grid[k][i] = false;
        }
    }
    return false;
}
int main() {
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    memset(grid, 0, sizeof(grid));
    For(i, 0, 8) {
        For(j, 0, 8) {
            char ch;
            cin >> ch;
            Sudoku[i][j] = ch - '0';
            if (Sudoku[i][j]) {
                row[i][Sudoku[i][j]] = true;
                col[j][Sudoku[i][j]] = true;
                grid[(i / 3) * 3 + j / 3][Sudoku[i][j]] = true;
            }
        }
    }
    dfs(0, 0);
    For(i, 0, 8) {
        For(j, 0, 8) {
            cout << Sudoku[i][j];
        }
        cout << endl;
    }
    return 0;
}