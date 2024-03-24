// always ddetect the ] to make sure that we can repeat the correct sequence
// ...c3[abc] => detect ] => string = abc (before[) , and repeat 3 times (when we detect c , then we know the time we need to repeat is 3 )

class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]==']'){
                string check;
                while(st.top()!='['){
                    check += st.top();
                    st.pop();
                }
                reverse(check.begin(),check.end());
                st.pop();
                string count;
                while(!st.empty()&&st.top()-'0'>=0&&st.top()-'0'<=9){
                    count += st.top();
                    st.pop();
                }
                reverse(count.begin(),count.end());
                for(int k=0;k<stoi(count);k++){
                    for(int j=0;j<check.length();j++){
                        st.push(check[j]);
                    }
                }
            }
            else st.push(s[i]);
        }
        string ans;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};