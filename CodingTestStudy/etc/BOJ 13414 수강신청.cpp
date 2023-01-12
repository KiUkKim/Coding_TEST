#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <limits.h>
#include <unordered_map>
using namespace std;

int maxS, num;
unordered_map<string, int> m;

bool compare(pair<string, int> a, pair<string, int> b)
{
    return a.second < b.second;
}

int main()
{
    fastio;

    cin >> maxS >> num;

    for(int i = 0; i < num; i++)
    {
        string student;

        cin >> student;

        if(m.count(student))
        {
            m[student] = i;
            continue;
        }

        m.insert({student, i});
    }

    vector<pair<string,int>> vc(m.begin(), m.end());

    sort(vc.begin(), vc.end(), compare);

    for(int i = 0; i < maxS; i++)
    {
        // 예외 조건 처리해주어야함
        // 수강 신청 이내에 처리가 완료될 수 있ㅇ므
        if(i == vc.size())
        {
            break;
        }
        cout << vc[i].first << '\n';
    }

    return 0;
}