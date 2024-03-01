class Solution {
public:
    unordered_map<int, int> count;
    vector<pair<int, int> > V;
    int ans = 0;

    void tryMerge(int l, int r) {
        if(l>=r) {
            return;
        }
        if(r>=V.size()) return;
        int mid = (l+r)/2;
        tryMerge(l, mid);
        tryMerge(mid+1, r);
        vector<pair<int, int> > leftV;
        vector<pair<int,int> > rightV;
        vector<int> temp;
        for(int i=mid+1;i<=r;i++) {
            temp.push_back(V[i].first);
            rightV.push_back({V[i].first, V[i].second});
        }

        for(int i=l;i<=mid;i++) {
            auto fnd = lower_bound(temp.begin(), temp.end(), V[i].first);
            int index = V[i].second;
            count [index] += (fnd-temp.begin());
            leftV.push_back(V[i]);
        }

        int fArr = 0, sArr = 0;
        int mainArrIn = l;
        while(fArr<leftV.size() && sArr<rightV.size()) {
            if(leftV[fArr].first<=rightV[sArr].first) {
                V[mainArrIn] = leftV[fArr];
                fArr++;
            } else { 
                V[mainArrIn] = rightV[sArr];
                sArr++;
            }
            mainArrIn++;
        }

        while(fArr<leftV.size()) {
            V[mainArrIn] = leftV[fArr];
            fArr++;
            mainArrIn++;
        }

        while(sArr<rightV.size()) {
            V[mainArrIn] = rightV[sArr];
            sArr++;
            mainArrIn++;
        }
        
    }

    vector<int> countSmaller(vector<int>& nums) {
        for(int i=0;i<nums.size();i++) {
            V.push_back(make_pair(nums[i], i));
        }

        tryMerge(0, nums.size()-1);

        vector<int> ans;
        for(int i=0;i<nums.size();i++) {
            ans.push_back(count[i]);
        }
        return ans;
    }
};