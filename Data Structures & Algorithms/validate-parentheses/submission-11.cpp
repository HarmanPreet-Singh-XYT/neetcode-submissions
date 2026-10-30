class Solution {
    bool isMatch(char s1,char s2){
        if(s1=='(' && s2==')') return true;
        if(s1=='[' && s2==']') return true;
        if(s1=='{' && s2=='}') return true;
        return false;
    }
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c : s){
            if(c=='[' || c=='{' || c == '('){
                st.push(c);
            }else{
                if(st.empty()) return false;
                if(!isMatch(st.top(),c)) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
