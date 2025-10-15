#include <bits/stdc++.h>
using namespace std;

// 시계 방향 90도 회전 
vector<vector<int>> rotate90Clockwise(const vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> rotated(m, vector<int>(n));

    for (int i = 0; i<n; i++)
        for (int j = 0; j<m; j++)
            rotated[j][n - 1 - i] = matrix[i][j];

    return rotated;
}

// 반시계 방향 90도 회전
vector<vector<int>> rotate90CounterClockwise(const vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> rotated(m, vector<int>(n));

    for (int i = 0; i<n; i++)
        for (int j = 0; j<m; j++)
            rotated[m - 1 - j][i] = matrix[i][j];

    return rotated;
}