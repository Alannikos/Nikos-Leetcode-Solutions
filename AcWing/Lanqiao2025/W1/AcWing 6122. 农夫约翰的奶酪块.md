### Code

```
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int N = 1010;

vector xy(N, vector<int>(N, 0));
vector yz(N, vector<int>(N, 0));
vector xz(N, vector<int>(N, 0));

int main()
{
    int n = 0, q = 0;
    scanf("%d%d", &n, &q);
    int res = 0;

    while (q --)
    {
        int x = 0, y = 0, z = 0;
        scanf("%d %d %d", &x, &y, &z);
        
        xy[x][y] ++;
        yz[y][z] ++;
        xz[x][z] ++;
        
        if (xy[x][y] == n)
        {
            res ++;
        }
        if (yz[y][z] == n)
        {
            res ++;
        }
        if (xz[x][z] == n)
        {
            res ++;
        }
        
        printf("%d\n", res);
    }
    
    return 0;
}
```

### 变量解释

- xy: 代表xy平面上与z轴平行的长条，坐标为(x, y, ...)的列被挖掉的方块数量。
- yz: 代表yz平面上与x轴平行的长条，坐标为(..., y, z)的列被挖掉的方块数量。
- xz: 代表xz平面上与y轴平行的长条，坐标为(x, ..., z)的列被挖掉的方块数量。

### 一些解释

- res: 注意这个结果是累加的。也就是说，对于每一次的操作，新增了哪些可行的方案，然后加到所有的方案中，形成答案(最开始因为这个WA了一次)
- 更新`xy`, `yz`, `xz`数组: 加入需要进行一次位置在(a, b, c)的操作，那么在xy数组中[a][b]位置的方块就被挖掉一个，所以加1；其余数组更新同理。

### Reference

- `https://www.acwing.com/solution/content/262711/`