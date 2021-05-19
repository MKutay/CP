#include <stdio.h>
#include <stdlib.h>

int n;
int cnt = 0;

int solve(int n);

void invalid() {
	fprintf(stderr, "Invalid Query\n");
	exit(1);
}

int query(int a, int b) {
	if (a < 0 || a >= n)
		invalid();
	if (b < 0 || b >= n)
		invalid();
	printf("? %d %d\n", a, b);
	fflush(stdout);
	int res;
	scanf("%d", &res);
	return res;
}

void answer(int a, int b) {
	printf("Guess: %d %d\n", a, b);
	exit(0);
}

int main() {
	printf("Enter n: ");
	scanf("%d", &n);

	int res = solve(n);
	answer(res / n, res % n);
	printf("Something went wrong\n");
}

