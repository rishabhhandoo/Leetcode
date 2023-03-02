class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        if(n==0||n==1)    return n;
        int uniq=0;
        int counter=1;
        int up=0;
        char prev=chars[0];
        int i=0;
        for(i;i<n-1;i++)
        {
            char curr=chars[i];
            cout<<"current char : "<<chars[i]<<endl;
            if(i>0){
                chars[up++]=prev;
                if(counter>1){
                    string num = to_string(counter);
                    for(int j=0;j<num.size();j++)
                    {
                        chars[up++]=num[j];
                    }
                counter=1;
                }
            }
            while(i<n-1 && curr==chars[i+1])
            {
                counter++;
                i++;
            }

            prev=curr;
            uniq++;
        }
        chars[up++]=prev;
        if(counter>1){
            string num = to_string(counter);
            for(int j=0;j<num.size();j++){
                chars[up++]=num[j];
            }
        }
        if(i==n-1)
        {
            chars[up++]=chars[n-1];
        }

        return up;
    }
};
      