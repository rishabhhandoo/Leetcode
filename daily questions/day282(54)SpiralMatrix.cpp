class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>res; int R,C,l,r,t,b,n;   // R --row, C --col, l --left, r --right , t --top,  b --bottom
        if((R=matrix.size())==0) return res;  
        C=matrix[0].size(), n=R*C,t=0,l=0, r=C-1,b=R-1;
        while(res.size()!=n){
            for(int i=l;i<=r;i++) res.push_back(matrix[t][i]);
            t++;
            for(int i=t;i<=b;i++) res.push_back(matrix[i][r]);
            r--;
            if(res.size()==n) break;
            for(int i=r; i>=l;i--) res.push_back(matrix[b][i]);
            b--;
            for(int i=b;i>=t;i--) res.push_back(matrix[i][l]);
            l++;
        }
       return res;
    }
};