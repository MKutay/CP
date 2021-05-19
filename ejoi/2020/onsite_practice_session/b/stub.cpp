#include <stdio.h>
#include <stdlib.h>


int solve(int n, int h);

void invalid()
{
    fprintf(stderr, "invalid query\n");
    exit(1);
}

int n, h;

int drop(int floor)
{
    if (floor <= 0 || floor > h)
        invalid();
        
    printf("? %d\n", floor);
    fflush(stdout);
    
    int res;
    scanf("%d", &res);
    return res;
}

void answer(int floor)
{
    if (floor <= 0 || floor > h)
        invalid();
    printf("Your program answered: %d\n", floor);
    exit(0);
}

int main()
{
	printf("Please input number of eggs and number of floors\n");
    scanf("%d%d", &n, &h);
    answer(solve(n, h));
}
