class Solution {
public:
    string longestPalindrome(string s) {
        int n =s.length();
        vector<vector<int>>dp(n,vector<int>(n,false));
        int idx = 0 , maxlen = 0 ;

        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
            maxlen = 1 ; 
        }

        for(int L=2;L<=n;L++){
            for(int i=0 ; i<n-L+1 ; i++){
                int j = L+i-1 ; 
                if(s[i]==s[j] and L==2){
                    dp[i][j]=1;
                    maxlen = 2 ; 
                    idx = i ;

                }
                else if (s[i]==s[j] and dp[i+1][j-1]== true){
                    dp[i][j] = 1 ; 
                    if(j-i+1 > maxlen){
                        maxlen = j-i+1;
                        idx = i ; 
                    }
                }
                else{
                    dp[i][j] = false;
                }
            }
        }
        return s.substr(idx,maxlen);
    }
};
