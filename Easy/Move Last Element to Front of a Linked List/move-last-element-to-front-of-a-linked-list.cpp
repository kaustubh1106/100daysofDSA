//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class ListNode{
public:
    int val;
    ListNode *next;
    ListNode(int x){
        val=x;
        next=NULL;
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    ListNode *moveToFront(ListNode *head){
        if(head->next == NULL || head == NULL){
            return head;
        }
        ListNode* temp1 = head;
        ListNode* temp2 = temp1->next;
        while(temp2->next!=NULL){
            temp1 = temp1->next;
            temp2= temp2->next;
        }
        temp2->next=head;
        temp1->next=NULL;
        head=temp2;
        return head;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ListNode*> a(n);
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            a[i]=new ListNode(x);
            if(i!=0){
                a[i-1]->next=a[i];
            }
        }
        ListNode *head=a[0];
        Solution ob;
        head=ob.moveToFront(head);
        while(head!=NULL){
            cout<<head->val;
            if(head->next!=NULL){
                cout<<" ";
            }
            head=head->next;
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends