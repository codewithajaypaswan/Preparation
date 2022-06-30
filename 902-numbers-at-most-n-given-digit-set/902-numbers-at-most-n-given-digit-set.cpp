class Solution {
public:
    
    int dp[11][2][2];
    
    int solve(vector<string>& digits, int pos, string num, bool limflag, bool started, string st){
        if(pos==num.size()){
            // cout<<st<<" ";   // you can print all the numbers that are made : blank space means : 0
            return 1;
        }
        int cnt=0;
        if(dp[pos][limflag][started]!=-1) return dp[pos][limflag][started];
        int lim=9;
        if(limflag) lim=num[pos]-'0';
        if(!started) cnt+= solve(digits,pos+1,num,false,false,st);
        for(string d:digits){
            int x = d[0]-'0';
            if(x>lim) continue;
            if(x==lim && limflag) cnt+= solve(digits,pos+1,num,true,true,st+d[0]);
            else cnt+= solve(digits,pos+1,num,false,true,st+d[0]);
        }
        dp[pos][limflag][started] = cnt;
        return cnt;
    }
    
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string num = to_string(n);
        memset(dp,-1,sizeof dp);
        string x;
        return solve(digits, 0, num, true, false, x)-1; // to exclude 0
    }
};