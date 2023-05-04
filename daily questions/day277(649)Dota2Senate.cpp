class Solution {
public:
    string predictPartyVictory(string senate) {
        
        bool check1=true,check2=true;
        int rc=0,dc=0;
        
        while(check1 && check2)
        {
            string temp = "";
            int n = senate.size();
            check1=false;
            check2=false;
            cout<<senate<<endl;

            for(int i=0;i<n;i++)
            {
                if(senate[i]=='D')
                {
                    cout<<"D: "<<i;
                    if(rc>0){    rc--;continue;}
                    if(senate[i]=='D')  dc++,temp.push_back('D');
                    cout<<"i:"<<i;
                    check1=true;

                }else if(senate[i]=='R')
                {
                    cout<<"R: "<<i;
                    if(dc>0) {   dc--;continue;}
                    if(senate[i]=='R')  rc++,temp.push_back('R');
                    cout<<"i:"<<i;
                    check2=true;
                }
            }
            // rc=0;
            // dc=0;
            senate = temp;
        }
        if(check1==true)   return "Dire";
        else return "Radiant"; 
    }
};

