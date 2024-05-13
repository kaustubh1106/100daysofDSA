//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        // code here
        char I,V,X,L,C,D,M;
        int n,sum=0;;
        n=str.size();
        
        for(int i=0;i<n;i++)
        {
            
            if(str[i]=='I')
            {
                if(str[i]=='I' && str[i+1]=='V')
                {
                    sum=sum+4;
                    i++;
                }
                else if(str[i]=='I' && str[i+1]=='X')
                {
                    sum=sum+9;
                    i++;
                }
                else
                {
                    sum=sum+1;
                }
                
            }
            
            
            else if(str[i]=='V')
            {
                sum=sum+5;
            }
            
            
            else if(str[i]=='X')
            {
                if(str[i]=='X' && str[i+1]=='L')
                {
                    sum=sum+40;
                    i++;
                }
                else if(str[i]=='X' && str[i+1]=='C')
                {
                    sum=sum+90;
                    i++;
                }
                else{
                    sum=sum+10;
                }
                
            }
            
            
            else if(str[i]=='L')
            {
                sum=sum+50;
            }
            
            
            else if(str[i]=='C')
            {
                if(str[i]=='C' && str[i+1]=='D')
                {
                    sum=sum+400;
                    i++;
                }
                else if(str[i]=='C' && str[i+1]=='M')
                {
                    sum=sum+900;
                    i++;
                }
                else{
                    sum=sum+100;
                }
                
            }
            
            
            else if(str[i]=='D')
            {
                sum=sum+500;
            }
            
            
            else if(str[i]=='M')
            {
                sum=sum+1000;
            }
            
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends