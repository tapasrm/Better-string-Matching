#include <stdio.h>
#include <string.h>
#include <time.h>

void match(char T[], char P[], int n, int m) {
	char M[400];
	int i = 0;
	int j = 0;
	int k = 0;
	while(i <= n - m) {
        j=0;
        k=0;
        while(T[i] == P[j]) {
            M[k] = P[j];
            i++;
            j++;
            k++;
            if(k==m) {
          	 printf("\nPattern found at %d position", (i-m)+1);
           	 i--;
        }
        if(j>(m-1) || i>(n-1))
            break;
        }
        i++;
    }
}

int main() {
	clock_t start_t, end_t, total_t;
	char T[] = "DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD";
	char P[] = "DDDD";
	int n = strlen(T);
	int m = strlen(P);
	start_t = clock();
	printf("Starting of the program, start_t = %ld\n", start_t);
	match(T,P,n,m);
	end_t = clock();
	printf("End of the program, end_t = %ld\n", end_t);
	// total_t = ((double)(end_t - start_t));
// 	printf("\n\n\aTime Taken by str_match function %f", total_t);
	return(0);
}

