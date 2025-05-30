#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int a[100001];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        long long left = 0, right = n - 1;
        int answer = 0;
        while (left <= right)
        {
            long long mid = left + (right - left) / 2;
            if (k < a[mid])
            {
                right = mid - 1;
            }
            else if (k > a[mid])
            {
                left = mid + 1;
            }
            else if (k == a[mid])
            {
                answer = 1;
                break;
            }
        }
        cout << answer << '\n';
    }
}