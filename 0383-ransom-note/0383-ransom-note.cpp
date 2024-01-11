class Solution {
public:
bool canConstruct(string ransomNote, string magazine) {
map<char,int>mp,mp1;
for(int i=0;i<ransomNote.size();i++)
{
mp[ransomNote[i]]++;
}
for(int j=0;j<magazine.size();j++)
{
mp1[magazine[j]]++;
}
for(auto it : mp){
if(mp1[it.first]<mp[it.first])
return false;
}

    return true;
    
}
};