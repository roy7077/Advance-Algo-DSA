// Time complexity - O(NlogN)
// Space complexity- O(N)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
 
int main() {
	int n,q;
	cin>>n>>q;
	
	vector<int> v(n+1);
	for(int i=1;i<=n;i++)
	cin>>v[i];
	
	vector<int> temp(n+1);
	while(q--)
	{
	    int i,j;
	    cin>>i>>j;
	    
	    temp[i]++;
	    if((j+1)<=n)
	    temp[j+1]--;
	}
	
	for(int i=1;i<=n;i++)
	temp[i]+=temp[i-1];
	
	sort(temp.begin(),temp.end(),greater<int>());
	sort(v.begin(),v.end(),greater<int>());
	
    ll sum=0;
	for(int i=0;i<n;i++)
	sum+=((ll)temp[i]*v[i]);
	
	cout<<sum<<endl;
	return 0;
}