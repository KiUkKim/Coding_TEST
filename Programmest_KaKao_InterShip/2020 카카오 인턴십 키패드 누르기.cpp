#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <stdlib.h>
using namespace std;

pair<int, int> leftIdx, rightIdx;

int keypad[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 0, 11}};

string solution(vector<int> numbers, string hand) {
    string answer = "";

    leftIdx = make_pair(3,0);
    rightIdx = make_pair(3,2);
    int idx = 0;
    
    for(int i = 0; i < 4; i++)
    {
        if(idx == numbers.size())
        {
            break;
        }
        cout << "i : " << i << '\n';
        for(int j = 0; j < 3; j++)
        {
            if(numbers[idx] == 4 || numbers[idx] == 1 || numbers[idx] == 7)
            {
                leftIdx = make_pair(i, j);
                answer += 'L';
                cout << "leftIdx : " << leftIdx.first << ' ' << leftIdx.second << " idx : " << idx << '\n';
                i = -1;
                idx++;
                break;
            }
            
            else if(numbers[idx] == 3 || numbers[idx]== 6 || numbers[idx] == 9)
            {
                rightIdx = make_pair(i,j);
                cout << "rightIdx : " << rightIdx.first << ' ' << rightIdx.second << '\n';
                answer += 'R';
                i = -1;
                idx++;
                break;
            }
            
            else if (numbers[idx] == 2 || numbers[idx] == 5
                    || numbers[idx] == 8 || numbers[idx] == 0){
                if( abs( (i - leftIdx.first) + (j - leftIdx.second) ) < 
                    abs( (i - rightIdx.first) + (j - rightIdx.second) ) )
                {
                    leftIdx = make_pair(i,j);
                    answer += 'L';
                    i = -1;
                    idx++;
                    cout << "leftIdx : " << leftIdx.first << ' ' << leftIdx.second  << '\n';
                    break;
                }
                
                else if(abs( (i - leftIdx.first) + (j - leftIdx.second) )  > 
                    abs( (i - rightIdx.first) + (j - rightIdx.second) ) )
                {
                    rightIdx = make_pair(i,j);
                    answer += 'R';
                    i = -1;
                    idx++;
                    cout << "rightIdx : " << rightIdx.first << ' ' << rightIdx.second << '\n';
                    break;
                }
                
                else if(abs( (i - leftIdx.first) + (j - leftIdx.second) )  == 
                    abs( (i - rightIdx.first) + (j - rightIdx.second) ) )
                {
                    if(hand == "right")
                    {
                        rightIdx = make_pair(i,j);
                        answer += 'R';
                        i = -1;
                        idx++;
                        break;
                    }
                    else{
                        leftIdx = make_pair(i,j);
                        answer += 'L';
                        i = -1;
                        idx++;
                        break;
                    }
                }
            }
        }
    }
    
    
    return answer;
}


int main()
{
    fastio;

    vector<int> numbers;

    for(int i = 0; i < 5; i++)
    {
        int tmp;
        cin >> tmp;

        numbers.push_back(tmp);
    }

    string result = solution(numbers, "right");


    cout << result << '\n';

    return 0;
}