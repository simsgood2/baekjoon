#include <bits/stdc++.h>

using namespace std;

int val[21][21];
bool pick[21]; // 뽑았는지 확인
int n;
int mini = 987654321;
void summ()
{
    int ret1 = 0, ret2 = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (pick[i] && pick[j])
            {
                ret1 += val[i][j];
            }
            else if ((!pick[i]) && (!pick[j]))
            {
                ret2 += val[i][j];
            }
        }
    }
    mini = min(mini, abs(ret2 - ret1));
}

void makeTeam(int m, int index)
{ // 몇명뽑았는지, 위치
    
    if (m == n / 2)
    {   
        summ();
        return;
    }
    for (int i = index; i <= n; i++)
    {
        pick[i] = 1;
        makeTeam(m + 1, i + 1);
        pick[i] = 0;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> val[i][j];
        }
    }

    makeTeam(0, 1);
    cout << mini << "\n";
    return 0;
}