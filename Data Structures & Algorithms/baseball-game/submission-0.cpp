class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int sum = 0;
        for(const string c:operations){
            if(c == "C"){
                sum -= (st.top());
                st.pop();
                continue;
            }else if(c == "D"){
                int lastDouble = (st.top())*2;
                st.push(lastDouble);
                sum += lastDouble;
                continue;
            }
            else if(c == "+"){
                int lastVal = st.top();
                int val = lastVal;
                st.pop();
                val += st.top();
                st.push(lastVal);
                st.push(val);
                sum+=val;
                continue;
            }
            int conVal = stoi(c);
            sum += conVal;
            st.push(conVal);
        }
        return sum;
    }
};