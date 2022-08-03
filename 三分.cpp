#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N;
double l, r;
double a[20];
double L, R, k, mid1, mid2;

double f(double x){
	double sum = 0;
	ll y = 0;
	for(int i = N; i >= 0; i--){
		sum += pow(x, i) * a[y];
		y++;
	}
	//cout << "x = " << x << "\t" << "sum = " << sum << "\n";
	return sum;
}
int main(){
	cin >> N >> l >> r;
	for(int i = 0; i <= N; i++){
		cin >> a[i];
		//cout << a[i];
	}
	while(r - l >= 1e-5){
		k = (r - l) / 3.0;
		mid1 = l + k, mid2 = r - k;
		//cout << "mid1 = " << mid1 << "\t" << "mid2 = " << mid2 << "\n";
		if(f(mid1) > f(mid2)){
			r = mid2;
			//cout << "r = " << r << " " << k << " " << mid1 << " " << mid2 << "******\n";
		} else {
			l = mid1;
			//cout << "l = " << l << " " << k << " " << mid1 << " " << mid2 << "------\n";
		}
	}
	cout << mid2;
	return 0;
}


