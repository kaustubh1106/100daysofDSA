//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findPivot(int arr[], int n) {
        int l = 0;
        int r = n-1;
        int mid;
        while(l<=r){
            mid=(l+r)/2;
            if(arr[l]>arr[mid]){
               r=mid-1;
            }
            else if(arr[mid]>arr[r]){
                 l=mid+1;
            }
            else{
                return mid;
            }
        }
        return -1;
    }
    int search(int a[], int l, int r, int k) {
        // l: The starting index
        // h: The ending index, you have to search the key in this range

        // complete the function here
        int mid =(l+r)/2;
        while(l<=r){
            mid =(l+r)/2;
            if(a[mid]==k){
                return mid;
            }
            else if(a[l]<=a[mid]){
                if(a[l]<=k && a[mid]>=k){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            else{
                if(a[r]>=k && a[mid]<=k){
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
    return 0;
}
// } Driver Code Ends