long long fpow(int a, int b) {
	long long ans = 1;
	while (b) {
		if (b & 1) {
			ans *= a;
		}
		a *= a;
		b >>= 1;
	}
	return ans;
}
