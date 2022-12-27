class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> ans;
        
        unordered_map<string , vector<string> > umap;
        
        for(int i=0;i<paths.size();i++)
        {
            string current = paths[i];
            int ptr=0;
            string path="";
            while(current[ptr]!=' ')
            {
                path+=current[ptr++];
            }
            //skippinf the space
            ptr++;
            while(ptr<current.size())
            {
                string file="";
                while(current[ptr]!='(')
                {
                    file+=current[ptr++];
                }
                //now for the content
                ptr++;
                string content="";
                while(current[ptr]!=')')
                {
                    content+=current[ptr++];
                }
                ptr+=2;
                string add = path+"/"+file;
                cout<<content<<endl;
                umap[content].push_back(add);
            }
            
        }
        
        for(auto itr:umap)
        {
            if(itr.second.size()>1)
               ans.push_back(itr.second);
        }
        return ans;
    }
};