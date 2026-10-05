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
        bool changed = true;
        while(changed){
            changed = false;
            for(int x = 0; x+1<s.size();x++){
                if(isMatch(s[x],s[x+1])){
                    s.erase(x,2);
                    changed = true;
                    break;
                }
            }
        }
        return s.empty();
    }
};
