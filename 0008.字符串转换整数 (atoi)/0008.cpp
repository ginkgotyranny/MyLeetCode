class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int len = s.size();
        long ans = 0;
        bool neg = false;
        while(s[i] == ' ' && i<len){
            i++;
        }
        //cout <<"space "<< i <<endl;
        if(s[i]=='-'){
            neg = true;
            i++;
        }
        else if(s[i] =='+'){
            i++;
        }
        //cout <<"flag "<< i <<endl;
        for(; i<len; i++){
            if(s[i]<='9' && s[i]>='0'){
                ans = ans*10 + s[i] - '0';
                if(neg && -ans < INT_MIN){
                    return INT_MIN;
                }
                else if(!(neg) && ans > INT_MAX){
                    return INT_MAX;
                }
            }
            else{
                break;
            }
        }
        return (neg)?-ans:ans;
    }
};