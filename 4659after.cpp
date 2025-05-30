#include <bits/stdc++.h>
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;

list<char> vowels = {'a', 'e', 'i', 'o', 'u'};

bool hasVowel(const string &s) // 조건1: 모음을 가지고있는지 확인
{
    for (char c : s) // 문자열 순회
    {
        if (find(vowels.begin(), vowels.end(), c) != vowels.end()) // 모음을 찾았다면
        {
            return true;
        }
    }
    return false;
}

bool hasTwice(const string &s) // 조건 3: 같은글자 연속 2번확인
{
    for (int i = 0; i+1 < s.length(); i++) // 연속된 2개 찾기
    {
        if (s[i] == s[i+1]) // 연속된 두개를 찾았다
        {
            if (s[i] == 'e' || s[i] == 'o') // 하지만 예외로 이 둘은 오케이
            {
                continue;
            }
            return false;
        }
    }
    return true;
}

bool hastriple(const string &s) // 조건 2: 자음 또는 모음 연속3개 확인
{
    int v_constant = 0; // 모음 연속확인인
    int c_constant = 0; // 자음 연속확인인
    for (char c : s)    // 문자열 순회 시작
    {
        if (find(vowels.begin(), vowels.end(), c) != vowels.end()) // 모음을 찾았다면
        {
            v_constant += 1;
            c_constant = 0;
        }
        else
        {
            c_constant += 1;
            v_constant = 0;
        }
        if (v_constant == 3 || c_constant == 3) // 자음 또는 모음 연속 3개
        {
            return false;
        }
    }
    return true;
}

int main(void)
{
    string str;
    while (1)
    {
        cin >> str;
        if (str == "end")
            return 0;
        if(hasVowel(str)&&hastriple(str)&&hasTwice(str)){
            cout << "<" << str << ">" << " is acceptable.\n";
        }
        else{
            cout << "<" << str << ">" << " is not acceptable.\n";
        }

        
    }
}