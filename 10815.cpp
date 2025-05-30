#include <bits/stdc++.h>
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;
using ll = long long;

int main()
{
    FastIO;
    int n;
    cin >> n;
    vector<ll> card;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        card.push_back(temp);
    }

    sort(card.begin(), card.end());

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int target;
        cin >> target;

        ll start = 0;
        ll last = card.size() - 1;

        bool ok = 0;//숫자를 찾았는지 확인

        while (start <= last)
        {
            ll mid = start + (last - start) / 2;
            if (card[mid] == target)
            {
                cout << 1 << " ";
                ok = 1;
                break;
            }
            else if (card[mid] < target)
            {
                start = mid + 1;
            }
            else
            {
                last = mid - 1;
            }
        }
        if (ok)
        {
            continue;
        }
        cout << 0 << " ";
    }
}