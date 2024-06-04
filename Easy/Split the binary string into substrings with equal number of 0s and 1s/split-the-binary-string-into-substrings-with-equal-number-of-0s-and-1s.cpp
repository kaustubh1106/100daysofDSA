//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int maxSubStr(string str){
        //Write your code here
        int len = str.size();
        if(len%2!=0){
            return -1;
        }
        unordered_map<char,int> mp;
        for (char ch : str) {
            mp[ch]++;
        }
        if(mp['0']!=mp['1']){
            return -1;
        }
        int count0 = 0, count1 = 0;
        int substrCount = 0;
    
        for (char ch : str) {
            if (ch == '0') {
                count0++;
            } else if (ch == '1') {
                count1++;
            }
    
            if (count0 == count1) {
                substrCount++;
            }
        }
    
        // If we can't find any valid substring, return -1
        if (substrCount == 0) {
            return -1;
        }
    
        return substrCount;
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
	    cin >> str;
	    Solution ob;
	    int ans = ob.maxSubStr(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends