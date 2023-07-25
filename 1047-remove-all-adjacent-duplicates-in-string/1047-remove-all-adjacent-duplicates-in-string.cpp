class Solution {
public:
    string removeDuplicates(string s) {
        stack <char> st;
        int n = s.length();
        for(int i=0; i<n; i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else{
                if(st.top()==s[i])
                    st.pop();
                else st.push(s[i]);
            }  
        }
        string ans="";
        while(st.size()!=0){
            char h=st.top();
            ans+=h;
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
        }
};

