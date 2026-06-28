class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int i= 0;

        while(i<s.length()){
            char c= s[i];

            if(c=='{' || c=='(' || c=='['){
                st.push(c);
            }
            else{
                if(st.empty()){
                    return false;
                }

                if(c=='}' && st.top()!= '{'){
                    return false;
                }
                if(c==')' && st.top()!= '('){
                    return false;
                }
                if(c==']' && st.top()!= '['){
                    return false;
                }

                st.pop();
            }
            i++;
        }
        return st.empty();
    }

};