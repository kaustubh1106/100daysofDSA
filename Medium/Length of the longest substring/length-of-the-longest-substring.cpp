//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string str){
        vector<int> alf(26, 0);
        int maxLen = 0;
        int n = str.size();
        
        int i = 0, j = 0;
        while(i < n){
            if(alf[str[i] - 'a'] == 0){
                maxLen = max(maxLen, i - j + 1);
                alf[str[i++] - 'a']++;
            }else{
                alf[str[j++] - 'a']--;
            }
        }
        
        return maxLen;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends