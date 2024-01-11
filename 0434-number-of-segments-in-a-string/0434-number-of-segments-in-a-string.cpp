class Solution {
public:
    int countSegments(string s) {
       int n = s.size();
       int ans = 1;
       if(s.size() == 0){
           return 0;
       }
       int cnt = 0;
       for(int i=0;i<s.size();i++){
           if(s[i] == ' '){
               cnt++;
           }
           else{
               break;
           }
       }
       if(cnt == n){
           return 0;
       }
       for(int i=cnt;i<n-1;i++){
           if(s[i] == ' ' && s[i+1]!=' '){
               ans++;
           }
       } 
       return ans;
    }
};