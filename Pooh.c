#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <string.h>
#include <stdlib.h> 
#include <time.h> 
#include <stdbool.h>

#define FOUND      1
#define NOTFOUND   0

#define  Ko     10
#define  R      10


int arr[Ko][R], masLocPos[2][R];
void fillArr();
int findNext(int _R, int K);

void main()
{
	int  K, result, r;

	fillArr();

	do{
		printf("K: ");
		scanf("%d", &K);
		result = findNext(0, K);
	} while (result!=FOUND);

	printf("\nToday I will eat Honey\n\n");
	printf("Kordinati na stupalata:\n\n");
	for (r = R-1; r >=0 ; r--) {
		printf("Step%d - Column:%d Row:%d\n",r+1, masLocPos[0][r], masLocPos[1][r]);
		printf("\n");
	}
	
}

void fillArr() {
	int lower = 1, upper = 500, k, r;
	for (k = 0; k < 2; k++) {
		for (r = 0; r < R; r++) {
			masLocPos[k][r] = 0;
		}
	}

	srand(time(0)); 
	for (k = 0; k < Ko; k++) {
		//printf("Column: %d\n", k);
		for (r = 0; r < R; r++) {
			int num = (rand() % (upper + 1 - lower)) + lower;
			if (r == 0) {
				arr[k][r] = 0;
			} else {
				arr[k][r] = num;
			}
			//printf("%d\n",  arr[k][r]);
		}
		//printf("\n");
	}

}

int findNext(int _R, int K) {
	int ret, kD;
	ret = NOTFOUND;
	for (kD = 0; kD < Ko; kD++) {
		if ((arr[kD][_R + 1] - _R) <= K) {
			if ((_R + 1) == R-1) {
				ret = FOUND;
				masLocPos[0][_R + 1] = kD;
				masLocPos[1][_R + 1] = _R + 1;
				return ret;
			} else {
				ret = findNext((_R + 1), K);
				if (ret == FOUND) {
						masLocPos[0][_R + 1] = kD;
						masLocPos[1][_R + 1] = _R + 1;
				}					
				return ret;
			}
		}
	}
    return ret;
}
