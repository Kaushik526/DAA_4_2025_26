class Solution {
public:
    bool isPalindrome(string &s,int l,int r){
        while(l<r){
            if(s[l]==s[r]){
                l++;
                r--;
            }
            else return false;
        }
        return true;
    }
    void solve(int start,string &s,vector<string> &path,vector<vector<string>> &ans){
        if(start==s.size()){
            ans.push_back(path);
            return;
        }
        for(int i=start;i<s.size();i++){
            if(isPalindrome(s,start,i)){
              path.push_back(s.substr(start,i-start+1));
              solve(i+1,s,path,ans);
              path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        solve(0,s,path,ans);
        return ans;
    }
};