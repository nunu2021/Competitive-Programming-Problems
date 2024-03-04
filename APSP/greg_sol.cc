#include<bits/stdc++.h>
using namespace std;
int dist[1000][1000];
typedef long long int lli;
int  main()
{
 lli n;
   cin>>n;
   for(lli i=0;i<n;i++)
    {
      for(lli j=0;j<n;j++)
       {
           cin>>dist[i][j];
    }
    }
    lli arr[10000];
    for(lli i=0;i<n;i++)
     {
       cin>>arr[i];
       arr[i]--;
  }
  
  vector<lli> v;
  for(lli k=n-1;k>=0;k--)
   {
     for(lli i=0;i<n;i++)
      {
        for(lli j=0;j<n;j++)
         {
           dist[i][j]=min(dist[i][j],dist[i][arr[k]]+dist[arr[k]][j]);
       }
      }
      lli ans=0;
      for(lli i=k;i<n;i++)
        {
          for(lli j=k;j<n;j++)
           {
            ans+=dist[arr[i]][arr[j]];
        }
        }
        v.push_back(ans);
   }
   for(lli i=n-1;i>=0;i--)
       {
         cout<<v[i]<<" ";
    }

}


// #include "../bits/stdc++.h"

// using namespace std;

// const int maxn = 510;
// int n, d[maxn][maxn], a[maxn];

// long long ans[maxn];
// int main(){
//     cin >> n;

//     for(int i = 0; i< n; i++){
//         for(int j = 0; j < n; j++){
//             cin >> d[i][j];
//             printf("%d skjdfajkd\n", d[i][j]);
//         }
//     }

//     for(int i = 0; i < n; i++){
//         cin >> a[n-i];
//     }

//     for(int k = 0; k < n; k++){
//         for(int i = 0; i< n; i++){
//             for(int j =0; j < n; j++){
//                 d[a[i]][a[j]] = min(d[a[i]][a[j]], d[a[i]][a[k]] + d[a[k]][a[j]]);
//             }
//         }
//         for(int i = 0; i <=k; i++){
//             for(int j = 0; j <= k ; j++){
//                 ans[k] += d[a[i]][a[j]];
//                 printf("wtf %d\n", d[a[i]][a[j]]);
//             }
//         }
//     }
//     for(int i = n-1; i >=0; i--){
//         cout << ans[i] << " ";
//     }
// }
