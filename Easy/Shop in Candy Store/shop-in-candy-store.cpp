//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int arr[], int n, int K)
    {
        // Write Your Code here
        sort(arr,arr+n);
        int count =0;
        int i=0;
        while(i<n){
            count++;
            i=i+1+K;
        }
        int min =0;
        int max =0;
        i=0;
        while(count>0){
            min+=arr[i];
            max+=arr[n-1-i];
            i++;
            count--;
        }
        vector<int> res;
        res.push_back(min);
        res.push_back(max);
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends