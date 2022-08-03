#include <bits/stdc++.h>
using namespace std;

#define N 2000010

int stmax[N][22], stmin[N][22], mn[N];

int n, q, a[N];//有n个数，共有q次询问，这n个数都存在a[]里

void init(){//预处理
    mn[0] = -1;
    for (int i = 1; i <= n; i++){
    	if((i & (i - 1)) == 0){//当i是2的整数次幂时
    		mn[i] = mn[i - 1] + 1;
		} else {
			mn[i] = mn[i - 1];
		}
        stmax[i][0] = stmin[i][0] = a[i];
        //cout << mn[i] << " ";
    }
    for (int j = 1; j <= mn[n]; j++){//从1到小于等于n的最大的2的整数次幂
    	for (int i = 1; i + (1 << j/*->2的j次方*/) - 1 <= n; i++){
    		//状态转移方程：f(i, j) = max(f(i, j - 1), f(i + 2的j-1次方, j - 1))
    		//区间    i ~ i + (2的j-1次方) - 1   和   i + (2的j-1次方) ~ (2的j次方-1)
            stmax[i][j] = max(stmax[i][j - 1], stmax[i + (1 << (j - 1))][j - 1]);
            stmin[i][j] = min(stmin[i][j - 1], stmin[i + (1 << (j - 1))][j - 1]);/**/
        }
	}
        
}

inline int rmq_max(int L, int R){//求最大值
    int k = mn[R - L + 1];
    return max(stmax[L][k], stmax[R - (1 << k) + 1][k]);
}

inline int rmq_min(int L, int R){//求最小值
    int k = mn[R - L + 1];
    return min(stmin[L][k], stmin[R - (1 << k) + 1][k]);
}

signed main(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
    init();
    while(q--){
        int l, r; cin >> l >> r;
        cout << rmq_max(l, r) << " " << rmq_min(l, r) << endl;
    }
    return 0;
}

