//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


int minFlips (string s)
{
    // your code here
    int count1=0;
    int count2=0;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(i%2==0){
            if(s[i]=='0'){
                count1++;
            }
            else{
                count2++;
            }
        }
        
        if(i%2!=0){
            if(s[i]=='0'){
                count2++;
            }
            else{
                count1++;
            }
        }
        
    }
      return min(count1,count2);
    
}