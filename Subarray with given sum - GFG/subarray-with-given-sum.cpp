//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        long long sum=0;
        int i=0,j,k=0;
        vector<int>ans;
        
        for(j=k; j< n; j++ )
        {
           sum+=arr[j];
           if(sum>=s)
           {
               if(sum==s)
               {
                   ans.push_back(i+1);
                   ans.push_back(j+1);
                   return ans;
               }
               else
               {
                   sum-=arr[i];
                   i++;
                   if(sum==s && s!=0)
                   {
                   ans.push_back(i+1);
                   ans.push_back(j+1);
                   return ans;
                    }
                   k=j+1;
               }
               while(sum>s)
               {
                  sum-=arr[i];
                   i++;
                   if(sum==s)
                   {
                   ans.push_back(i+1);
                   ans.push_back(j+1);
                   return ans;
                    }
                   k=j+1; 
               }
           }
        }
        ans.push_back(-1);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends