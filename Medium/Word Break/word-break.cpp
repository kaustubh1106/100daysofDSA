//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings

class Solution
{
public:
    int wordBreak(int n, string s, vector<string> &dictionary) {
        //code here
        int len = s.size();
        unordered_set<string> wordSet(dictionary.begin(),dictionary.end());
        vector<bool> dp(len+1,false);
        dp[0]=true;
        for(int i = 1 ; i<=len;i++ ){
            for(int j = 0 ; j<i ; j++){
                if(dp[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end()){
                    dp[i]=true;
                    break;
                }
                //check if(dictionary includes sub)
                //if(yes && dp[j-1]==true) dp[i]=true
            }
        }
        return dp[len];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends