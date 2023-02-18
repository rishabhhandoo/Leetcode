// class Solution {
// public:
//     void helper(int ogi, int ogj , int i , int j , int previ,int prevj , vector<vector<pair<int,int>>> &vis,vector<vector<int>>& height,int n,int m)
//     {
//         if(i==-1 || j==-1)
//         {
//             vis[ogi][ogj].first=1;
//             cout<<vis[ogi][ogj].first<<" , "<<vis[ogi][ogj].second<<endl;
//             cout<<"pacific"<<previ<<" "<<prevj<<"|"<<i<<","<<j<<endl;
//             return;
//         }
//         else if(i==n || j==m)
//         {
//             vis[ogi][ogj].second=1;
//             cout<<vis[ogi][ogj].first<<" "<<vis[ogi][ogj].second<<endl;
//             cout<<"atlantic"<<previ<<" "<<prevj<<"|"<<i<<","<<j<<endl;
//             return;
//         }        
//         if(height[previ][prevj] < height[i][j])
//             return;
        
//         if(vis[ogi][ogj].first==1 && vis[ogi][ogj].second==1)
//         {
//             return;
//         }
//         if(vis[i][j].second == 1 || vis[i][j].first==1)
//         {
//             if(vis[i][j].second==1)
//                 vis[ogi][ogj].second=1;
//             if(vis[i][j].first==1)
//                 vis[ogi][ogj].first=1;
//             return;
//         }

//         if(i-1 != previ)
//             {helper(ogi,ogj,i-1,j,i,j,vis,height,n,m);
//             // cout<<" up"<<endl;
//             }
//         if(i+1 != previ)
//             {helper(ogi,ogj,i+1,j,i,j,vis,height,n,m);
//             // cout<<" down"<<endl;
//             }
//         if(j+1 != prevj)
//             {helper(ogi,ogj,i,j+1,i,j,vis,height,n,m);
//               // cout<<" right"<<endl;
//             }
//         if(j-1 != prevj)
//            { helper(ogi,ogj,i,j-1,i,j,vis,height,n,m);
//               // cout<<" left"<<endl;
//            }
            
//     }
    
    
//     vector<vector<int>> pacificAtlantic(vector<vector<int>>& height) {
//         //creating a visited which will save if pacific vissited then 1 = first and second for atlantic
//         vector<vector<int>> ans;
        
//         int n = height.size();
//         int m = height[0].size();
        
//         vector<vector<pair<int,int>>> vis;
        
//         for(int i =0 ; i<n ; i++)
//         {
//             vector<pair<int,int>> level;
//             for(int j=0;j<m;j++)
//             {
//                 level.push_back({0,0});
//                 // cout<<"insertion"<<endl;
//             }
            
//             vis.push_back(level);
//         }
        
//         for(int i =0 ; i<n ; i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 cout<<"_____________"<<i<<" "<<j<<"_____________"<<endl;
//                 helper(i,j,i,j,i,j,vis,height,n,m);
//             }
//         }
        
//         //travers and find the ones which are 1 both the times
//         // cout<<"reached till here"<<endl;
        
//         for(int i=0 ; i<n ; i++)
//         {
            
//             for(int j =0 ; j<m ; j++)
//             {
//                 if(vis[i][j].first == 1 && vis[i][j].second ==1)
//                 {
//                     // cout<<i<<","<<j<<"  ";

//                     vector<int> level;
//                     level.push_back(i);
//                     level.push_back(j);
//                     ans.push_back(level); 
//                 }
//                 // else cout<<" __ ";
//             }
//             cout<<endl;
//         }
//     return ans;
    
//     }
    
    
// };
class Solution {
public:
    int m, n;
	// denotes cells reachable starting from atlantic and pacific edged cells respectively
    vector<vector<bool> > atlantic, pacific;
	vector<vector<int> > ans;    
    vector<vector<int> > pacificAtlantic(vector<vector<int>>& mat) {
        if(!size(mat)) return ans;
        m = size(mat), n = size(mat[0]);
        atlantic = pacific = vector<vector<bool> >(m, vector<bool>(n, false));
		// perform dfs from all edge cells (ocean-connected cells)
        for(int i = 0; i < m; i++) dfs(mat, pacific, i, 0), dfs(mat, atlantic, i, n - 1);
        for(int i = 0; i < n; i++) dfs(mat, pacific, 0, i), dfs(mat, atlantic, m - 1, i);             
        return ans;
    }
    void dfs(vector<vector<int> >& mat, vector<vector<bool> >& visited, int i, int j){        
        if(visited[i][j]) return;
        visited[i][j] = true;
		// if cell reachable from both the oceans, insert into final answer vector
        if(atlantic[i][j] && pacific[i][j]) ans.push_back(vector<int>{i, j});    
		// dfs from current cell only if height of next cell is greater
/*⬇️*/  if(i + 1 <  m && mat[i + 1][j] >= mat[i][j]) dfs(mat, visited, i + 1, j); 
/*⬆️*/  if(i - 1 >= 0 && mat[i - 1][j] >= mat[i][j]) dfs(mat, visited, i - 1, j);
/*➡️*/  if(j + 1 <  n && mat[i][j + 1] >= mat[i][j]) dfs(mat, visited, i, j + 1); 
/*⬅️*/  if(j - 1 >= 0 && mat[i][j - 1] >= mat[i][j]) dfs(mat, visited, i, j - 1);
    }
};