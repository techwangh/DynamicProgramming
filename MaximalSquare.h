#ifndef MAXIMALSQUARE
#define MAXIMALSQUARE

class MaximalSquare {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = 0;
        if(m > 0) n = matrix[0].size();

        sums.resize(m+1, vector<int>(n+1,0));
        for(int i = 1; i <=m; ++i) {
            for(int j = 1; j <=n; ++j) {
                int val;
                if(matrix[i-1][j-1] == '1') val = 1;
                else val = 0;

                sums[i][j] = sums[i][j-1] + sums[i-1][j] - sums[i-1][j-1] + val;
            }
        }
        for(int squareSize = min(m,n); squareSize > 0; --squareSize){
            for(int i = 1; i <= m+1-squareSize; ++i) {
                for(int j = 1; j <= n+1-squareSize; ++j) {
                    if(sumRegion(i,j,i+squareSize-1,j+squareSize-1) == squareSize*squareSize) {
                        return squareSize*squareSize;
                    }
                }
            }
        }
        return 0;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2][col2] - sums[row2][col1-1] - sums[row1-1][col2] + sums[row1-1][col1-1];
    }



private:
    vector<vector<int>> sums;
};

#endif // MAXIMALSQUARE

