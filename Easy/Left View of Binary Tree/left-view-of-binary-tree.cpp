//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

vector<int> leftView(struct Node *root);

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


int main() {
    int t;
    scanf("%d ",&t);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        vector<int> vec = leftView(root);
        for(int x : vec)
        cout<<x<<" ";
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends


/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.\

int height(Node* root){
    if(root==NULL){
        return 0;
    }
    else{
        int hol = height(root->left);
        int hor = height(root->right);
        
        int ans = max(hol,hor)+1;
        return ans;
    }
}


void lefttraversal(Node* root,vector<int> &ans){
    if(root == NULL){
        return ;
    }
    else if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
        return ;
    }
    else{
        
        ans.push_back(root->data);
        if(root->left){
            lefttraversal(root->left,ans);
        }
        else{
            lefttraversal(root->right,ans);
        }
        
    }
}
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> ans;
   if(root==NULL) return ans;
   
   int hol = height(root->left);
   int hor = height(root->right);
   
   if(hol>=hor){
       lefttraversal(root,ans);
   }
   else{
       ans.push_back(root->data);
       vector<int>ans2;
       lefttraversal(root,ans2);
       lefttraversal(root->right,ans);
       for(int i =0 ;i<ans2.size();i++){
           ans[i]=ans2[i];
       }
   }
   return ans;
}
