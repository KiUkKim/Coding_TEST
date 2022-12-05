#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <string>
#include <set>
using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

int t;

int main()
{
    fastio;

    // 최댓값, 최솟값 삭제 처리
    // 중복허용
    // Empty시 처리

    cin >> t;

    while(t--)
    {
        multiset<int> ms;

        char cmd;
        int num;
        int c;

        cin >> c;

        for(int i = 0; i < c; i++)
        {
            cin >> cmd >> num;

            if(cmd == 'I')
            {
                ms.insert(num);
            }

            else if(cmd == 'D')
            {
                if(ms.empty())
                    continue;
                
                if(num == -1)
                {
                    ms.erase(ms.begin());
                }

                else if(num == 1)
                {
                    auto iter = ms.end();
                    iter--;
                    ms.erase(iter);
                }
            }
        }

        if(ms.empty())
        {
            cout << "EMPTY" << '\n';
        }

        else{
            auto end_iter = ms.end();
            end_iter--;

            cout << *end_iter << ' ' << *ms.begin() << '\n';
        }
    }

    return 0;
}