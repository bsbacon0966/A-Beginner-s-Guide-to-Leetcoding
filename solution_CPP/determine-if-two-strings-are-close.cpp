// to calculate the frequency of the element and making hashTable for these frequencies

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length()!=word2.length()) return false;
        vector<int> m1(26,0);
        vector<int> m2(26,0);
        for(int i=0;i<word1.size();i++){
            m1[word1[i]-'a']++ ;
            m2[word2[i]-'a']++ ;
        }
        for(int i=0;i<26;i++){
            if(bool(m1[i])!=bool(m2[i])) return false;
        }
        vector<int> c1;
        vector<int> c2;
        for(auto i:m1){
            if(i!=0) c1.push_back(i);
        }
        for(auto i:m2){
            if(i!=0) c2.push_back(i);
        }
        sort(c1.begin(),c1.end());
        sort(c2.begin(),c2.end());
        return c1==c2;
    }
};