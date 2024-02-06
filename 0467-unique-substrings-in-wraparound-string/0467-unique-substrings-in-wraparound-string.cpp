class Solution {
public:
    int findSubstringInWraproundString(string s) {

unordered_map<char,int>mp; // to store position 

mp[s[0]] = 1; //giving first element position = 1.
     int pos = 1;
 for(int i = 1 ; i < s.size() ; i++){
     
     if((s[i]-'0') - (s[i-1]-'0') == 1 or (s[i]=='a' and s[i-1]=='z')){
         pos++; // if element at right place position is : (previous element position + 1).
     }else pos = 1; // else position = 1

    if(pos>mp[s[i]])mp[s[i]] = pos; // updation maximum position possible  
 }

int ans = 0;

// adding their contribution
for(auto m : mp){
  
    ans += m.second;}


return ans;
    }
};