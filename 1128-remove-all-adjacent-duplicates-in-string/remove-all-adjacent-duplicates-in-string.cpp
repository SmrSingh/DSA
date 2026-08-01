class Solution {
public:
    string removeDuplicates(string s) {
      stack<char> st;string t="";
      for(int i=0;i<s.length();i++){
        if(!st.empty() && st.top()==s[i]){
            
            st.pop();
        }
        else
        st.push(s[i]);
      }
      while(!st.empty()){
        t+=st.top();
        st.pop();
      }  
      
      reverse(t.begin(),t.end());
      return t;
    }
};