class Solution {
public:
    string addBinary(string a, string b) {
        
        string ans="";
        int i=a.size()-1,j=b.size()-1;
        bool carry=false;
        while(i>=0 && j>=0)
        {
            if( (a[i]=='0'||b[j]=='0') && carry==false)
            {
                ans.push_back(a[i]-'0' + b[j]);
            }else if((a[i]=='0' && b[j]=='0') && carry==true)
            {
                ans.push_back('1');
                carry=!carry;
            }else if( (a[i]=='0'&& b[j]=='1') || (a[i]=='1'&& b[j]=='0') && carry)
            {
                ans.push_back('0');
            }else if(a[i]=='1' && b[j]=='1')
            {
                if(carry)
                {
                    ans.push_back('1');
                }else{
                    ans.push_back('0');
                    carry=true;
                }
            }
            cout<<a[i]<<" "<<b[j]<<endl;
            cout<<ans<<endl;
            cout<<endl;
            i--,j--;
        }
        while(i>=0)
        {
            if(carry)
            {
                if(a[i]=='0')
                {
                    ans.push_back('1');
                    carry=!carry;
                }else{
                    ans.push_back('0');
                }
            }else{
                if(a[i]=='0')
                {
                    ans.push_back('0');
                }else{
                    ans.push_back('1');
                }    
            }
            cout<<a[i]<<" "<<endl<<ans<<endl<<endl;
            i--;
        }
        while(j>=0)
        {
            if(carry)
            {
                if(b[j]=='0')
                {
                    ans.push_back('1');
                    carry=!carry;
                }else{
                    ans.push_back('0');
                }
            }else{
                if(b[j]=='0')
                {
                    ans.push_back('0');
                }else{
                    ans.push_back('1');
                }    
            }
            j--;
        }


        if(carry)   ans.push_back('1');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};