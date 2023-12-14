class Solution {
public:
    string addBinary(string a, string b) {
        string s;
        std::string::iterator itr1=a.end()-1,itr2=b.end()-1;
        bool carry=0;
        while(itr1>=a.begin()&&itr2>=b.begin())
        {
            if(*itr1=='1'&&*itr2=='1')
            {
                if(carry==1)
                {
                    s='1'+s;
                }
                else
                {
                    s='0'+s;
                    carry=1;
                }
            }
            else if((*itr1=='1'&&*itr2=='0')||(*itr1=='0'&&*itr2=='1'))
            {
                if(carry==1)
                {
                    s='0'+s;
                }
                else
                {
                    s='1'+s;
                }
            }
            else
            {
                if(carry==1)
                {
                    s='1'+s;
                    carry=0;
                }
                else
                {
                    s='0'+s;
                }
            }
            itr1--;itr2--;
        }
        for(;itr1>=a.begin();itr1--)
        {
            if(*itr1=='1')
            {
                if(carry==1)
                {
                    s='0'+s;
                }
                else
                {
                    s='1'+s;
                }
            }
            else
            {
                if(carry==1)
                {
                    s='1'+s;
                    carry=0;
                }
                else
                {
                    s='0'+s;
                }
            }}
            for(;itr2>=b.begin();itr2--)
        {
            if(*itr2=='1')
            {
                if(carry==1)
                {
                    s='0'+s;
                }
                else
                {
                    s='1'+s;
                }
            }
            else
            {
                if(carry==1)
                {
                    s='1'+s;
                    carry=0;
                }
                else
                {
                    s='0'+s;
                }
            }
        }
        if(carry==1)
        {
            s='1'+s;
        }
        return s;
    }
};