class Solution {
    bool isMatch(char in1,char in2){
        return (
            (in1 == '(' && in2 == ')') ||
            (in1 == '[' && in2 == ']') ||
            (in1 == '{' && in2 == '}')
        );
    }
public:
    bool isValid(string s) {
        stack<char> st;

        for(char c : s){
            if(c == '(' || c == '[' || c == '{'){
                st.push(c);
            }else{
                if(st.empty()) return false;
                char top = st.top();
                st.pop();
                if(!isMatch(top,c)){
                    return false;
                }
            }
        }

        return st.empty();
    }
};
