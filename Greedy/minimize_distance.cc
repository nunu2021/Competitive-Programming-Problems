#include "bits/stdc++.h"

using namespace std;
 

    void run()
    {
        int n, k;
        cin >> n >> k;
 
        int x[n];
        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
        }
        sort(x, x + n);
        int positive_pos = 0;
        while (positive_pos < n && x[positive_pos] < 0)
            positive_pos++;
 
        long ans = 0;
        int p = n - 1;
        while (p >= positive_pos)
        {
            ans += x[p] + x[p];
 
            p -= k;
        }
        for (int i = 0; i < positive_pos; i += k)
        {
            ans -= x[i] + x[i];
        }
 
        int left = positive_pos > 0 ? -x[0] : 0;
        int right = positive_pos < n ? x[n - 1] : 0;
        ans -= max(left, right);
        cout << ans << endl;
    }
 
int main()
{
    ios_base::sync_with_stdio(false);
 
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        run();
    }
    return 0;
}