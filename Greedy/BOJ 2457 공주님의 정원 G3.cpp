#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <utility>
using namespace std;


vector<vector<pair<int, int>>> day;
vector<pair<int, int>> tmpDate;

bool check;

int n;

// 꽃이 피는 날짜가 앞인 순으로 정렬
bool compare(vector<pair<int, int>> a, vector<pair<int, int>> b)
{
    if(a[0].first == b[0].first)
        return a[0].second < b[0].second;

    return a[0].first < b[0].first;
}

// 피어있는 꽃 기준으로 날짜를 받기 위함
pair<int, int> dayCmp(pair<int, int> start, pair<int ,int> day)
{
    // 만약에 피어있는 꽃 기준 이후에 피는 꽃이라면 넘겨버림
    if(start.first < day.first)
        return day;
    // 피는 월 같으면 일로 따짐 
    // 일이 크다면, 조건 성립 x
    else if(start.first == day.first)
    {
        if(start.second < day.second)
            return day;
    }

    return start;
}

int main()
{
    fastio;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int start_month, start_day, end_month, end_day;

        cin >> start_month >> start_day >> end_month >> end_day;

        tmpDate.push_back({start_month, start_day});
        tmpDate.push_back({end_month, end_day});

        day.push_back(tmpDate);

        tmpDate.clear();
    }

    sort(day.begin(), day.end(), compare);

    int cnt = 0;

    pair<int, int> start = {3, 1};
    pair<int, int> end = {12, 1};
    pair<int, int> tmp = {1, 1};

    for(int i = 0; i < n; i++)
    {
        // 현재 조건을 충족하기 위함
        // 반환이 start와 같다면 현재 피어있는 꽃보다 앞쪽에피거나 같음
        if(dayCmp(start, day[i][0]) == start)
        {
            // 지는 날짜가 가장 긴 애를 넣어준다.
            tmp = dayCmp(tmp, day[i][1]);


            // 11/30이 이후 지는 일 경우 바로 종료
            if(dayCmp(tmp, end) == tmp)
            {
                check = true;
                break;
            }
        }

        // 피는 꽃이 선택된 꽃 이후일 경우
        // 앞쪽에 피어 있는 꽃을 기준으로 해준다.
        else{
            start = tmp;
            cnt++;
            if(dayCmp(start, day[i][0]) == start)
            {
                tmp = day[i][1];

                if(dayCmp(tmp, end) == tmp)
                {
                    check = true;
                    break;
                }
            }

            else{
                break;
            }
        }
    }

    if(!check)
        cout << 0 << '\n';
    else{
        cout << cnt + 1 << '\n';
    }


    return 0;
}