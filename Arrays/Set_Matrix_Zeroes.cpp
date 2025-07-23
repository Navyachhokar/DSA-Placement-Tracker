// ------------------------------------------------
// 🔸 Brute Force
// 💡 Use two nested loops to find zeroes, then mark entire row/column in a temp matrix
// 🕒 Time Complexity: O((n * m) * (n + m))
// 🔍 Space Complexity: O(n * m)
// ------------------------------------------------
void setZeroesBrute(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> temp = matrix;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                for (int k = 0; k < m; k++) temp[i][k] = 0;
                for (int k = 0; k < n; k++) temp[k][j] = 0;
            }
        }
    }

    matrix = temp;
}


// ------------------------------------------------
// 🔸 Better Approach
// 💡 Use two auxiliary arrays to mark rows and columns to be zeroed
// 🕒 Time Complexity: O(n * m)
// 🔍 Space Complexity: O(n + m)
// ------------------------------------------------
void setZeroesBetter(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<int> row(n, 0), col(m, 0);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (matrix[i][j] == 0) row[i] = 1, col[j] = 1;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (row[i] || col[j]) matrix[i][j] = 0;
}


// ------------------------------------------------
// 🔸 Optimal Approach (In-place)
// 💡 Use first row & column as markers, avoid extra space
// 🕒 Time Complexity: O(n * m)
// 🔍 Space Complexity: O(1)
// ------------------------------------------------
void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    bool firstRow = false, firstCol = false;

    for (int i = 0; i < n; i++) if (matrix[i][0] == 0) firstCol = true;
    for (int j = 0; j < m; j++) if (matrix[0][j] == 0) firstRow = true;

    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            if (matrix[i][j] == 0)
                matrix[i][0] = matrix[0][j] = 0;

    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;

    if (firstRow)
        for (int j = 0; j < m; j++) matrix[0][j] = 0;

    if (firstCol)
        for (int i = 0; i < n; i++) matrix[i][0] = 0;
}
