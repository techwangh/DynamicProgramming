class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = 0;
        if(m > 0) n = matrix[0].size(); 
        sums.resize(m+1, vector<int>(n+1,0));
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                sums[i][j] = sums[i][j-1] + sums[i-1][j] - sums[i-1][j-1] + matrix[i-1][j-1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2+1][col2+1] - sums[row2+1][col1] - sums[row1][col2+1] + sums[row1][col1];
    }
    
private:
    vector<vector<int>> sums;
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);