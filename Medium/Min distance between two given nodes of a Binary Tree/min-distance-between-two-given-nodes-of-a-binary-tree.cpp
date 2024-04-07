//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int lca1(Node* root, int a, int b,int &sum){
        if(root==NULL){
            return -1;
        }
        
        else if(root->data == a || root->data == b){
            sum++;
            return root->data;
        }
        else{
            int l = lca1(root->left,a,b,sum);
            int r = lca1(root->right,a,b,sum);
            
            if(l == -1 && r==-1){
                return -1;
            }
            else if(l!=-1 && r == -1){
                sum++;
                return l;
            }
            else{
                sum++;
                return r;
            }
        }
    }
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
       
       if(root ==NULL ){
           return NULL;           //step 1: return NULL
       }
       else if(root->data == n1 || root->data == n2){
           return root;             //step 2: IF REQUIREMENT MEET return root
       }
       
       else{
           Node* ansl = lca(root->left ,n1 ,n2 );
           Node* ansr = lca(root->right ,n1 ,n2 );
           
           if(ansl == NULL && ansr == NULL){
               return NULL;             //step 3: check all the requirements
           }
           else if(ansl != NULL && ansr == NULL){
               return ansl;
           }
           
           else if(ansl == NULL && ansr != NULL){
               return ansr;
           }
           return root;
       }
    }
    int distroot(Node * root, int a,int h){
        if(root == NULL){
            return 0;
        }
        else if(root->data==a){
            
            return h;
        }
        else{
            int l = distroot(root->left,a ,h+1);
            int r = distroot(root->right,a ,h+1);
            
            if(l==0 && r==0){
                return 0;
            }
            else{
                
                
                return max(l,r);
            }
        }
    }
    int findDist(Node* root, int a, int b) {
        // Your code here
        Node* ca = lca(root,a,b);
        // cout<<ca->data<<endl;
        if(ca->data == a){
            return distroot(ca,b,0);
        }
        else if(ca->data == b){
            // cout<<"hii"<<distroot(ca,a,0)<<endl;
            return distroot(ca,a,0);
        }
        else{
            int sum = 0;
            int l = distroot(ca,a,0);
            int r = distroot(ca,b,0);
            return l+r;
        }
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
     
    }
    return 0;
}

// } Driver Code Ends