//일부기능만 구현하였습니다.
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double prob(int N, int k);

int main(void) {
	srand((unsigned int)time(NULL));

	

}

double prob(int N, int k) {
	float ans = 1;
	float ans2 = 1;
	for (int i = 0; i < N; i++) {
		int r = (rand() % 6)+1;

		if (r == 1) {
			ans2 = ans2* (1 / 6);
		}

	}
}