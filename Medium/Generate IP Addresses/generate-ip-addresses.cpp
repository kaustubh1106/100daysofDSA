//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    void generate(int indx , int dots , string temp , string& s , vector<string>&ans )
    {
        
        if(dots == 0)
        {
            
            if(indx == s.size()){
                temp.pop_back() ; // remove extra . at last 
                ans.push_back(temp) ; 
            }
            
            return ; 
        }
        
        if(s[indx] == '0')
        {
            generate(indx + 1 , dots-1 , temp + "0." , s , ans) ; 
            return ; 
        }
        

       // try to check 3 digits 

       // 111  => 1.  , 11. , 111. 
        for(int i = 1 ;i <= 3 ; i++)
        {
            if(i + indx <= s.size())
            {
                string temp1 = s.substr(indx , i) ; 
           
                int val = stoi(temp1) ; // convert string to int 
                
                if(val >= 256 ) // invalid ip 
                continue ; 
                
                generate(indx + i, dots - 1 , temp + temp1 + "." , s , ans) ; 
            }
        }
    }
    vector<string> genIp(string &s) {
        
        if(s.size() < 4 || s.size() > 12)
        return {} ; 
        
        vector<string>ans ; 
        generate(0 , 4 ,"" ,s ,  ans) ; 
        
        return ans ; 
    }

};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if(str.size()==0)
            cout << -1 << "\n";
        else{
            for (auto &u : str) {
                cout << u << "\n";
            }
        }
    }
}
// } Driver Code Ends