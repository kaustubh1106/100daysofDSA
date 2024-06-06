//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        const int PRIME = 1000000007; // Large prime number for modulus operation

        long long int hashfunction(string &s, int len) {
            long long int hash = 0;
            for (int i = 0; i < len; i++) {
                hash = (hash * 256 + (s[i] - 'a')) % PRIME;
            }
            return hash;
        }
        
        vector<int> search(string pattern, string text) {
            int lenPat = pattern.size();
            int lenTex = text.size();
            
            if (lenPat > lenTex) {
                return {}; // Return an empty vector if the pattern is longer than the text
            }
            
            long long int patHash = hashfunction(pattern, lenPat);
            long long int h = 1;
            for (int i = 0; i < lenPat - 1; i++) {
                h = (h * 256) % PRIME;
            }
            
            string f = text.substr(0, lenPat);
            long long int currHash = hashfunction(f, lenPat);
            
            vector<int> ans;
            if (currHash == patHash) {
                ans.push_back(1);
            }
            
            for (int i = lenPat; i < lenTex; i++) {
                currHash = (currHash - ((text[i - lenPat] - 'a') * h) % PRIME + PRIME) % PRIME;
                currHash = (currHash * 256 + (text[i] - 'a')) % PRIME;
                if (currHash == patHash) {
                    ans.push_back(i - lenPat + 2);
                }
            }
            
            return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends