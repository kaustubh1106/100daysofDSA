//{ Driver Code Starts
// C++ implementation to convert a
// sentence into its equivalent
// mobile numeric keypad sequence
#include <bits/stdc++.h>
using namespace std;
string printSequence(string input);
// Driver function
int main()
{
	int t;
	cin>>t;
	cin.ignore();
	while(t--)
    {
        string s;
        getline(cin,s);
        cout<<printSequence(s)<<endl;
    }
	return 0;
}

// } Driver Code Ends


string printSequence(string S)
{
    //code here.
    string str;
    for(int i =0 ; i<S.size();i++ ){
        if(S[i]==' '){
        str.push_back('0');
        }
        else if(S[i]=='S'){
            str.append("7777");
        }
        else if(S[i]=='Z'){
            str.append("9999");
        }
        else if(S[i]>'S'){
            int key = (S[i]-'T')/3 + 8;
            int times = (S[i]-'T')%3+1;
            char k = char(key + '0');
            while(times>0){
                str.push_back(k);
                times--;
            }
            
        }
        else{
            int key = (S[i]-'A')/3 + 2;
            int times = (S[i]-'A')%3+1;
            char k = char(key + '0');
            while(times>0){
                str.push_back(k);
                times--;
            }
        }
    }
    return str;
    
    //if(yes){(s[i]-'T')/3 + 8 && (S[i]-'T')%3+1}
    //((S[i]-'A')/3)+2 = konsi key press karni h
    //(S[i]-'A')%3+1 kitni baar press karni h
    
}