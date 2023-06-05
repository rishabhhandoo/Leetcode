class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int firstx = coordinates[0][0];
        int firsty = coordinates[0][1];
        bool c1=true,c2=false;
        for(int i=1;i<coordinates.size();i++)
        {
            if(firstx!=coordinates[i][0])   {c1=false;}
            if(firsty!=coordinates[i][1])   {c2=false;}
        }        
        if(c1||c2)  return true;
        double slope = (double)(coordinates[1][1]-coordinates[0][1])/(double)(coordinates[1][0]-coordinates[0][0]);


        for(int i=2;i<coordinates.size();i++)
        {
            if(slope != (double)(coordinates[i][1]-coordinates[0][1])/(double)(coordinates[i][0]-coordinates[0][0]))    return false;
        }
        return true;
    }
};