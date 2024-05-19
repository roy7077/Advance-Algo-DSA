=// Time complexity - O(N+Q)
// Space complexity- O(N+N)
#include<vector>
#include<iostream>
using namespace std;
 
int main()
{
    int n,k,q;
    cin>>n>>k>>q;
    
    int size=200000;
    vector<int> v1(size+2,0);
    vector<int> v2(size+2,0);
    
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        
        v1[x]++;
        v1[y+1]--;
    }
    
    for(int i=0;i<=size;i++)
    {
        v2[i]+=v2[i-1];
        v1[i]+=v1[i-1];
        
        if(v1[i]>=k)
        v2[i]++;
    }
    
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        
        cout<<(v2[y]-v2[x-1])<<endl;
    }
    return 0;
}