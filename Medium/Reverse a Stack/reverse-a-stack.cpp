//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void mix(stack<int> &St,int NUM,int window){
        if(window==0){
            St.push(NUM);
            return ;
        }
        else{
            int num = St.top();
            St.pop();
            mix(St,NUM,window-1);
            St.push(num);
        }
    }
    void Reverse(stack<int> &St){
        for(int i =St.size()-1;i>=0;i--){
            int NUM = St.top();
            St.pop();
            mix(St,NUM,i);
        }
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends