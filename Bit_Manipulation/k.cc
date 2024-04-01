#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include "../bits/stdc++.h"
using namespace std;
int read()
{
	int t;
    cin >> t;
    return t;
}

void solve()
{
	int ans = 1;
	for (int n = read(); n > 1; n >>= 1, ans <<= 1);
	printf("%d\n", ans - 1);
}

int main()
{
	for (int T = read(); T--; solve());
	return 0;
}