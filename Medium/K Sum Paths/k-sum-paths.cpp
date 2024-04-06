//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) 
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function template for C++

/*
struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
#define mod (int)(1e9+7)
class Solution{
  public:
    
    void sumK_util(Node *root, int sum, int cur, int &ans, unordered_map<int, int> &mp)
    {
        if(!root)
            return;
        
        //Adding the count of paths with current sum difference in the answer
        ans += mp[cur + root->data - sum];
    
        if(ans >= mod)
            ans %= mod;
        
        //Checking if the current sum is equal to the desired sum, then incrementing answer
        if(cur + root->data == sum)
            ans++;
    
        if(ans >= mod)
            ans %= mod;
        
        //Updating the count of paths with current sum difference
        mp[cur + root->data]++;
    
        if(mp[cur + root->data] >= mod)
            mp[cur + root->data] %= mod;
        
        //Recursive calls for left and right subtree
        sumK_util(root->left, sum, cur+root->data, ans, mp);
        sumK_util(root->right, sum, cur+root->data, ans, mp);
        
        //Backtracking step, decrementing the count of paths with current sum difference
        mp[cur+root->data]--;
    
        if(mp[cur + root->data] <0)
            mp[cur + root->data] += mod;
    }
    
    int sumK(Node *root,int k)
    {
        // code here 
        int ans = 0;
            
        unordered_map<int, int> mp;
            
        sumK_util(root, k, 0, ans, mp);
            
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    string tc;
    getline(cin, tc);
    int t = stoi(tc);
  
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);

        string key;
        getline(cin, key);
        int k=stoi(key);
        Solution ob;
        cout << ob.sumK(root, k) << "\n";
    }
    return 0;
}
// } Driver Code Ends