//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    unordered_map<char,int> mp;
		    queue<char>stream;
		    string B="";
		    for(int i = 0;i<A.size();i++){
		        //increase count
		        mp[A[i]]++;
		        
		        //queue me push karo
		        stream.push(A[i]);
		        
		        while(!stream.empty()){
		            if(mp[stream.front()]>1){
		                //repeating character
		                stream.pop();
		            }
		            else{
		                B.push_back(stream.front());
		                break;
		            }
		        }
		        if(stream.empty()){
		            B.push_back('#');
		        }
		    }
		    
		    return B;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends