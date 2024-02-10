//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool pair(char a,char b){
        if(b==')'||b==']'||b=='}'){
            return true;
        }
        return false;
    }
    int checkRedundancy(string s) {
        // code here
        stack <char> st;
        for(int i =0 ; i<s.size();i++){
            char ch = s[i];
            if(ch == '(' || ch == '+' ||ch == '-' ||ch == '*' ||ch == '/'){
                st.push(ch);
            }
            else{
                if(ch == ')'){
                    bool isred = true;
                    while(st.top() !='('){
                        char top = st.top();
                        if(top == '+' ||top == '-' ||top == '*' ||top == '/'){
                            isred = false;
                        }
                        st.pop();
                    }
                    if(isred==true)
                        return 1;
                    st.pop();
                    
                }
                
            }
            
        }
        return 0;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
    
        string s; 
        cin>>s;
        
        Solution obj;
        int res = obj.checkRedundancy(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends