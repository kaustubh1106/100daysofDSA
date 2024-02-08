//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool pair(char a, char b){
        if(a=='{' && b=='}' || a=='[' && b==']' || a=='(' && b==')'){
            return true;
        }
        return false;
    }
    bool ispar(string x)
    {
        // Your code here
        //base case
        stack<int> s;
        if(s.size()==1){
            return false;
        }
        else{
            s.push(x[0]);
            for(int i = 1 ;i<x.size();i++){
                if(!s.empty() && pair(s.top(),x[i])){
                    s.pop();
                }
                else{
                    s.push(x[i]);
                }
            }
            if(s.empty()){
                return true;
            }
            else{
                return false;
            }
        }
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends