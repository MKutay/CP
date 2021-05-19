#include <stdio.h>
using namespace std;

int createNew(int n, int a, int b);
int restoreOld(int n, int c, int d);

int main(int argc, char **argv){
    int n;
    scanf("%d", &n);

    int num1, num2;
    scanf("%d%d", &num1, &num2);

    int val = createNew(n, num1, num2);
    int ret1 = val/n;
    int ret2 = val%n;
    printf("Generated key: %d %d\n", ret1,ret2);

	if(num1 == ret1 || num1 == ret2 || num2 == ret1 || num2 == ret2){
        printf("First player should not return numbers from the original key");
        return 0;
	}

	if(ret1 < 0 || ret1 >= n || ret2 < 0 || ret2 >= n || ret1 >= ret2){
        printf("First player returned invalid numbers.");
        return 0;
	}

    val = restoreOld(n, ret1, ret2);
    printf("Restored key: %d %d\n", val/n,val%n);

    if(val/n == num1 && val%n == num2) printf("Correct.");
    else printf("Incorrect.");
    printf("\n");
}
