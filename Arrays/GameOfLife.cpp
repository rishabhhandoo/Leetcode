class Solution {
public:
    int neighbours(vector<vector<int>>& curr, int i, int j, int m, int n) {
	int liveNeighbours = 0;
	if(i>0) {
		//check the upper neighbour
		if(curr[i-1][j] == 1) liveNeighbours++;
	}
	if(i<m-1) {
		//check the lower neighbour
		if(curr[i+1][j] == 1) liveNeighbours++;
	}
	if(j>0) {
		//check the left neighbour
		if(curr[i][j-1] == 1) liveNeighbours++;
	}
	if(j<n-1) {
		//check the right neighbour
		if(curr[i][j+1] == 1) liveNeighbours++;
	}

	if(i>0 && j>0) {
		if(curr[i-1][j-1] == 1) liveNeighbours++;
	}
	if(i>0 && j<n-1) {
		if(curr[i-1][j+1] == 1) liveNeighbours++;
	}
	if(i<m-1 && j>0) {
		if(curr[i+1][j-1] == 1) liveNeighbours++;
	}
	if(i<m-1 && j<n-1) {
		if(curr[i+1][j+1] == 1) liveNeighbours++;
	}
	return liveNeighbours;
}
    
    
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> nextState = board;
        int live=0;
        int dead=0;
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                int num_neighbour = neighbours(board,i,j,board.size(),board[0].size());
                if(board[i][j]==1){     
                    
                    if(num_neighbour<2) nextState[i][j]=0;
                    else if(num_neighbour==2 || num_neighbour==3){
                        nextState[i][j]=1;
                    }else{
                            nextState[i][j]=0;    
                    }
                    
                }else{
                    if(num_neighbour==3) nextState[i][j]=1;
                }
                
            }
        }
        board=nextState;
    }
};