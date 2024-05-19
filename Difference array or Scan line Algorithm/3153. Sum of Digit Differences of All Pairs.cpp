#define ll long long
class Solution {
    public:
    long long sumDigitDifferences(vector<int>& nums) {
        ll ans=0;
        int size=0;
        int num=nums[0];
        while(num)
        {
            size++;
            num/=10;
        }
        
        for(int i=0;i<size;i++)
        {
            unordered_map<ll,ll> mp;
            for(int j=0;j<nums.size();j++)
            {
                mp[nums[j]%10]++;
                nums[j]/=10;
            }
            
            ll tempCnt=0;
            ll sum=0;
            for(auto& it:mp)
            {
               tempCnt+=(sum*it.second);
               sum+=it.second;
            }
            //cout<<tempCnt<<endl;
            
            if(mp.size()>=2)
            ans+=tempCnt;
        }
        return ans;
    }
};