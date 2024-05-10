//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string longestPalindrome(string S){
        // code here 
        int n=S.length();
        int maxlen=0;
        string ans="";
        string res="";
        int l=0,h=0;
        for(int i=0;i<n;i++){
            // for odd substrings
            l=i;
            h=i;
            while(l>=0 && h<S.length() && S[l]==S[h]){
                ans=S.substr(l,h-l+1);
                if(ans.length()>maxlen){
                    maxlen=ans.length();
                    res=ans;
                }
                l--;
                h++;
            }

            // for even substrings
            l=i;
            h=i+1;
            while(l>=0 && h<S.length() && S[l]==S[h]){
                ans=S.substr(l,h-l+1);
                if(ans.length()>maxlen){
                    maxlen=ans.length();
                    res=ans;
                }
                l--;
                h++;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends