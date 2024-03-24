// sort the string to make key value
// if strs has same key , it means that the string has same components

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(int i=0;i<strs.size();i++){
            string tmp = strs[i];
            sort(strs[i].begin(),strs[i].end());
            mp[strs[i]].push_back(tmp);
        }
        vector<vector<string>> ans;
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};