#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int *compute_prefix_function(char *pattern, int psize)
{
	int k = -1;
	int i = 1;
	int *pi = malloc(sizeof(int)*psize);
	if (!pi)
		return NULL;

	pi[0] = k;
	for (i = 1; i < psize; i++) {
		while (k > -1 && pattern[k+1] != pattern[i])
			k = pi[k];
		if (pattern[i] == pattern[k+1])
			k++;
		pi[i] = k;
	}
	return pi;
}

int kmp(char *target, int tsize, char *pattern, int psize)
{
	int i;
	int *pi = compute_prefix_function(pattern, psize);
	int k = -1;
	if (!pi)
		return -1;
	for (i = 0; i < tsize; i++) {
		while (k > -1 && pattern[k+1] != target[i])
			k = pi[k];
		if (target[i] == pattern[k+1])
			k++;
		if (k == psize - 1) {
			free(pi);
			return i-k;
		}
	}
	free(pi);
	return -1;
}

int main(int argc, const char *argv[])
{
	clock_t start_t, end_t;
	char target[] = "DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD";
	char *ch = target;
	char pattern[] = "DDDD";
	int i;
	start_t = clock();
	printf("Starting of the program, start_t = %ld\n", start_t);
	i = kmp(target, strlen(target), pattern, strlen(pattern));
	end_t = clock();
	if (i >= 0)
		printf("matched @: %s\n", ch + i);
	printf("End of the program, end_t = %ld\n", end_t);
	return 0;
}