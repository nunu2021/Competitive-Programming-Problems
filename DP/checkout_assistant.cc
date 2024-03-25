#include "bits/stdc++.h"

using namespace std;
const long long int MAX=(long long int)1<<62;
long long int dp[2005];
long long int a[2005][2];
int n;
int main()
{
   scanf("%d",&n);
   for(int i=1;i<=n;i++)
      scanf("%lld%lld",&a[i][0],&a[i][1]),a[i][0]++;
   for(int i=0;i<=n;i++)
	   dp[i]=MAX;
   dp[0]=0;
   for(int i=1;i<=n;i++)
   {
	   for(int j=n;j>=0;j--)
	   {
		   if(j>=a[i][0])
		   {
			   dp[j]=min(dp[j],dp[j-a[i][0]]+a[i][1]);
		   }
		   else
			   dp[j]=min(dp[j],a[i][1]);
	   }
   }
   printf("%lld\n",dp[n]);
   return 0;
}
