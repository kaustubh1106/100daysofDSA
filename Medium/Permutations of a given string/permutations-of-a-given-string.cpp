//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	 vector<string>find_permutation(string S)
        {
            // Code here there
            set<string> ans;
            permutations(S,0,ans);
            vector<string> vc(ans.begin(), ans.end());
            
            return vc;
        }
        void permutations(string &s, int start, set<string> &ans){
            if(start == s.size()-1){
                ans.insert(s);
                return;
            }
            
            unordered_map<char,int> mp;
            for(int i = start; i < s.size(); i++){
                if(mp.find(s[i]) == mp.end()){
                    mp[s[i]]++;
                    
                    if(s[i] != s[start]){
                        swap(s[i],s[start]);
                        permutations(s,start+1,ans);
                    // backtracking step
                    swap(s[i],s[start]);
                        
                    }
                    else
                       permutations(s,start+1,ans);
                }
            }
        }
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends