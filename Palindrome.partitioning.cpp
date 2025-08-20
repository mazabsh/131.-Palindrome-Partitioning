#include<iostream> 
#include<vector> 

using namespace std; 

class Solution{
public: 
    bool isPolindrome(string& s , int l, int r){
      while(l<r){
        if(s[l]!=s[r]) return false; 
        else {
          ++l; 
          --r;
        }
      }
      return true; 
    } 
    void backtrack(string& s, vector<vector<string>>& res, vector<string>& curr, int start){
      if(start ==s.size()){
          res.push_back(curr); 
           return; 
      }
      for(int i=start; i< s.size(); ++i){
          if(isPolindrome(s, start, i)) {
              curr.push_back(s.substr(start, i-start+1)); 
              backtrack(s, res, curr, i+1); 
              curr.pop_back();
          }
      }
    }
    vector<vector<string>> partition(string s) {
      vector<vector<string>> res; 
      vector<string> curr; 
      backtrack(s, res, curr, 0); 
      return res; 
    }
};
int main(){
  string s = "aab";
  Solution sol; 
  vector<vector<string>> res = sol.partition(s); 
  for(auto vec:res){
    cout << "[" ; 
    for(string v:vec){
      cout << v << ", " ; 
    }
    cout << "]"; 
    cout <<endl; 
  }
  return 0;
  
}
