class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> letters;

        int m = order.size();
        int n = words.size();
        for(int i=0;i<m;i++)
        {
            letters[order[i]] = i;
        }
        
        for(int i=1;i<n;i++)
        {
            cout<<"hmm"<<endl;
            int x=0,y=0;
            int n1=words[i-1].size();
            int n2=words[i].size();
            bool flag= true;
            while(x<n1 && y<n2)
            {
                if( letters[words[i-1][x]] > letters[words[i][y]] )
                {
                    return false;
                }else if(letters[words[i-1][x]] < letters[words[i][y]])
                {
                    flag = false;
                    break;
                }
                x++;
                y++;
            }
            if(flag)
            {
                if(x>=n1)
                {
                    continue;
                }else{
                    return false;
                }
            }
            
        }

        return true;
    }
};