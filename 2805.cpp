#include <bits/stdc++.h>

using namespace std;

long long n, m; // n:나무수, m: 집에가져가려는길이
long long tree[1000001];

bool is_possible(long long mid)
{
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (tree[i] > mid)
        {
            sum += tree[i] - mid;
        }
    }
    return sum >= m;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int t = 0; t < n; t++)
    { // 나무의 개수
        cin >> tree[t];
    }
    long long left = 0, right = 1000000000; // 자를수있는 최대대소길이 찾기
    long long ret = 0;
    while (left <= right)
    {
        long long mid = left + (right - left) / 2;
        if (is_possible(mid))
        {
            ret = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << ret;
}