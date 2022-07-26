class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        int i=0;
        int j=0;
        while(i<firstList.size() && j<secondList.size()){
            
            if(firstList[i][0]<=secondList[j][1] && firstList[i][1]>=secondList[j][0] ){
                vector<int> temp(2);
                temp[0] = max(firstList[i][0] , secondList[j][0]);
                temp[1] = min(firstList[i][1] , secondList[j][1]);
                ans.push_back(temp);
            }
            
             if(firstList[i][1] > secondList[j][1]){
                    j++;
                }else i++;
            
        }
        return ans;
    }
};