class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans;
        
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0;i<m;i++)
        {
            int x = 0;
            int y = i;
            cout<<"current ball :"<<i<<endl;
            while(y<m && y>=0&&x<n)
            {
                if(grid[x][y]==1)
                {
                    cout<<"1 ";
                    if( y+1>=m || grid[x][y+1] == -1 )
                    {
                        cout<<"break1"<<endl;
                        ans.push_back(-1);
                        break;
                    }else{
                        x+=1;
                        y+=1;
                    }
                }
                
               else if(grid[x][y]==-1)
               {
                    cout<<"-1 ";
                   
                    if(y-1<0 || grid[x][y-1]==1 )
                    {
                        cout<<"break2"<<endl;
                        
                        ans.push_back(-1);
                        break;
                    }else{
                        x+=1;
                        y-=1;
                    }
                }
                cout<<endl<<"x: "<<x<<" y "<<y<<endl;
                // if(x==n-1){
                //     if(y>=0)
                //     ans.push_back(y-1);
                //     else{
                //         ans.push_back(-1);
                //     }
                //     break;
                // } else
                // if(x>n-1)
                // {
                //     if(y>=0)
                //     ans.push_back(y);
                //     else{
                //         ans.push_back(-1);
                //     }
                //     break;
                // }
            }
            if(x>=n){
                ans.push_back(y);
            }
        }
        return ans;
    }
};