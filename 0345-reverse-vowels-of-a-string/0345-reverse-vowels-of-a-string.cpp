class Solution {
public:
    bool check(char c){
        c=tolower(c);
        return (c=='a'|| c=='e'|| c=='i'|| c=='o'|| c=='u');
    }
    string reverseVowels(string s) {
        int n=s.size();
        int i=0,j=n-1;        
        while(i<j){
            if(check(s[i]) && check(s[j]))
            {
                swap(s[i],s[j]);
                i++;
                j--;
            }
            else if(check(s[i])==false)
                i++;
            else if(check(s[j])==false)
                j--;
        }
        return s;
    }
};