//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    // void reverse(queue<int> q, int k,queue <int> &res){
    //     //base case
    //     if(q.empty()){
    //         return ;
    //     }
    //     else{
            
           
    //         reverse(q,k,res);
    //     }
    // }
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        // add code here.
            stack <int> s;
            
            int i =0;
            while(i<k && !q.empty()){
                int element = q.front();
                q.pop();
                s.push(element);
                i++;
            }
            while(!s.empty()){
                int element = s.top();
                s.pop();
                q.push(element);
            }
            // int p=0;
            // while(p!=ele-k){
            //     // int element = q.front();
            //     // q.pop();
            //     // q.push(element);
            //     p++;
            // }
            for(int i = k;i<q.size();i++){
                int element = q.front();
                q.pop();
                q.push(element);
            }
        return q;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        queue<int> ans = ob.modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends