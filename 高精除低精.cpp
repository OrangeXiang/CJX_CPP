/*#include <iostream>
#include <string>
using namespace std;
long long num[5050];
int main(){
    ios::sync_with_stdio(false);
    string s;
    int a;
    long long yu;
    cin >> s >> a;
    int len = s.length();
    for(int i = 0; i < len; i++){
        num[i] = s[i] - '0';
    }
    for(int i = 0; i < len; i++){
        yu = num[i] % a;
        num[i] = num[i] / a;
        num[i + 1] = num[i + 1] + yu * 10;
    }
    bool f = false;
    for(int i = 0; i < len; i++){
        if(num[i] != 0) f = true;
        if(f) cout << num[i];
    }
    return 0;
}*/
#include <iostream>
#include <string>

using namespace std;
string s;
int b;
int a[1005], ans[1005];
int main(){
	cin >> s >> b;

	int l1 = s.length();
	for(int i = 0; i < l1; i++){
		a[i] = s[i] - '0';
	}

	int r = 0, num = 0;
	for(int i = 0; i < l1; i++){
		num = r * 10 + a[i];
		ans[i] = num / b;
		r = num % b;
	}

	//输出商
	bool flag = false;
	for(int i = 0; i < l1; i++){
		if(ans[i] != 0 || i == l1 - 1) flag = true;
		if(flag) cout << ans[i];
	}

	//输出余数
	cout << "······" << r;

	return 0;
}
