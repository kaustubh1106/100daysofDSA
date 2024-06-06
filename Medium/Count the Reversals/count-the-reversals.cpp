//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s)
{
    // your code here
    int size = s.size();
    if(size%2!=0){
        return -1;
    }
    else{
        stack<char> brks;
        brks.push('0');
        for(int i = 0 ;i < size ;i++){
            char top_char = brks.top();
            if(top_char!='0' && top_char=='{' && s[i]!=top_char){
                brks.pop();
            }
            else{
                brks.push(s[i]);
            }
        }
        char top = brks.top();
        if(top=='0'){
            return 0;
        }
        else{
            int stk_size = brks.size();
            unordered_map <char,int> mp;
            
            while(top!='0'){
                top = brks.top();
                mp[top]++;
                brks.pop();
            }
            float f = mp['{']/2.0;
            float s = mp['}']/2.0;
            
            return ceil(f)+ceil(s);
        }
    }
}