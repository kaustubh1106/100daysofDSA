//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* reverse(Node* head, Node* prev){
       
        Node* curr =head;
        Node* forward;
        if(curr->next==NULL){
            curr->next=prev;
            return curr;
        }
        else{
            forward = curr ->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            forward = curr->next;
            reverse(curr,prev);
        }
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        int ind = -1;
        Node* revhead = reverse(head,NULL);
        // cout<<"hii"<<revhead->data<<"hii";
        Node* temp = revhead;
        Node* end ;
        
        while(temp!=NULL){
            if(temp->next==NULL){
                // cout<<"hii";
                end=temp;
            }
            if(temp->data==9){
                temp->data=0;
                temp=temp->next;
            }
            else{
                temp->data++;
                ind++;
                break;
            }
            
        }
        // cout<<"hii"<<ind<<"hii";
        if(ind==-1){
            Node* p = new Node(1);
            end->next = p;
            // return reverse(revhead,NULL);
        }
        return reverse(revhead,NULL);
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends