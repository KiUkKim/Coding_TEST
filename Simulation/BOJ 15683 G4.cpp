#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

struct CCTV{
    int type, y, x;
};


int N, M;
int Area[8][8];
int ret;
int cctv_size;
CCTV cctv[8];

int root_size[] = {4, 2, 4, 4, 1};

void map_copy(int newData[8][8], int original[8][8])
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            newData[i][j] = original[i][j];
        }
    }
}

void update(int dir, CCTV cctv)
{
    dir = (dir % 4);

	if (dir == 0) {
		for (int x = cctv.x + 1; x < M; ++x) {
			if (Area[cctv.y][x] == 6)	break;
			Area[cctv.y][x] = -1;
		}
	}
	if (dir == 1) {
		for (int y = cctv.y - 1; y >= 0; --y) {
			if (Area[y][cctv.x] == 6)	break;
			Area[y][cctv.x] = -1;
		}
	}
	if (dir == 2) {
		for (int x = cctv.x - 1; x >= 0; --x) {
			if (Area[cctv.y][x] == 6)	break;
			Area[cctv.y][x] = -1;
		}
	}
	if (dir == 3) {
		for (int y = cctv.y + 1; y < N; ++y) {
			if (Area[y][cctv.x] == 6)	break;
			Area[y][cctv.x] = -1;
		}
	}
    // dir = (dir % 4);
    
    // // 우
    // if(dir == 0)
    // {
    //     for(int x = cctv.x + 1; x < M; ++x)
    //     {
    //         if(Area[cctv.y][x] == 6)
    //             break;
    //         Area[cctv.y][x] = -1;
    //     }
    // }

    // // 상
    // if(dir == 1)
    // {
    //     for(int y = cctv.y - 1; y >= 0; --y)
    //     {
    //         if(Area[y][cctv.x] == 6)
    //             break;
    //         Area[y][cctv.x] = -1;
    //     }
    // }

    // // 하
    // if(dir == 2)
    // {        
    //     for(int x = cctv.x - 1; x >= 0; --x)
    //     {
    //         if(Area[cctv.y][x] == 6)
    //             break;
    //         Area[cctv.y][x] = -1;
    //     }
    // }
    

    // //좌
    // if(dir == 3)
    // {
    //     for(int y = cctv.y + 1; y < M; ++y)
    //     {
    //         if(Area[y][cctv.x] == 6)
    //             break;
    //         Area[y][cctv.x] = -1;
    //     }
    // }
    

}

// DFS로 구현
// dir - 우상좌하
void DFS(int cctv_idx)
{
    if(cctv_idx == cctv_size)
    {
        int candi = 0;
        for(int y = 0; y < N; ++y)
        {
            for(int x = 0; x < M; ++x)
            {
                if(Area[y][x] == 0)
                    ++candi;
            }
        }

        if(ret > candi)
        {
            ret = candi;
        }
        return;
    }

    int backup[8][8];

    int type = cctv[cctv_idx].type;

    for(int dir = 0; dir < root_size[type]; ++dir)
    {
        map_copy(backup, Area);

        if(type == 0)
        {
            update(dir, cctv[cctv_idx]);
        }

        if(type == 1)
        {
            update(dir, cctv[cctv_idx]);
            update(dir +2, cctv[cctv_idx]);
        }

        if(type == 2)
        {
            update(dir, cctv[cctv_idx]);
            update(dir + 1, cctv[cctv_idx]);
        }

        if(type == 3)
        {
            update(dir, cctv[cctv_idx]);
            update(dir+1, cctv[cctv_idx]);
            update(dir+2, cctv[cctv_idx]);
        }

        if(type==4)
        {
            
            update(dir, cctv[cctv_idx]);
            
            update(dir+1, cctv[cctv_idx]);
            
            update(dir+2, cctv[cctv_idx]);
            
            update(dir+3, cctv[cctv_idx]);
        }

        DFS(cctv_idx + 1);
        map_copy(Area, backup);
    }
}

int main()
{
    fastio;

    cin >> N >> M;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> Area[i][j];

            if(Area[i][j] != 0 && Area[i][j] != 6)
            {
                cctv[cctv_size].y = i;
                cctv[cctv_size].x = j;
                cctv[cctv_size].type = Area[i][j] - 1;
                ++cctv_size;
            }

        }
    }

    ret = 100;

    DFS(0);

    cout << ret << '\n';

    return 0;
}