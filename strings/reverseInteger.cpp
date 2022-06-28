class Solution {
public:
    int reverse(int num) {
        bool negative=false;
        long long x=num;
        if(x<0){
            negative = true;
            x*=-1;
        }
        if(x/10==0) return x;
        long long int reversed=0;
        
        while(x>0){

            reversed=reversed*10 + x%10;
            x=x/10;
        }
        
        return (reversed<INT_MIN || reversed>INT_MAX)? 0:((negative)?(-1*reversed):reversed);
    }
};