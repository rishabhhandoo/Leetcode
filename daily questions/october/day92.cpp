class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int row = n-1;
        int col = 0;
        
        while(row>=0)
        {
            int val = matrix[row][col];
            for(int i=1;row+i<n&&col+i<m;i++)
            {
                if(matrix[row+i][col+i] != val) return false;
            }
            row--;
        }
        col++;
        row=0;
        while(col<m)
        {
            int val = matrix[row][col];
            for(int i=1;row+i<n&&col+i<m;i++)
            {
                if(matrix[row+i][col+i]!= val ) return false;
            }
            col++;
        }
        
        return true;
    }
};