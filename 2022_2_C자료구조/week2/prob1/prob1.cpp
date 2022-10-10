//comment: test case 모두 통과하였습니다.
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>


int main(void) {
	char c[20];
	char c1[20];

	int len;
	int len1;

	int cnt[26] = { 0 };
	int cnt1[26] = { 0 };
	int i, j;

	scanf("%s", &c);
	scanf("%s", &c1);

	len = strlen(c);
	len1 = strlen(c1);

	for (i = 0; i < len; i++) {
		if ((c[i] >= 'A' && c[i] <= 'Z') || (c[i] >= 'a' && c[i] <= 'z')) {
			if (c[i] <= 'Z')
				cnt[c[i] - 'A']++;
			else
				cnt[c[i] - 'a']++;
		}
	}
	for (i = 0; i < 26; i++) {
		if (cnt[i])
			printf("%c: %d\n", 'A' + i, cnt[i]);
	}

	printf("\n");

	for (j = 0; j < len1; j++) {
		if ((c1[j] >= 'A' && c1[j] <= 'Z') || (c1[j] >= 'a' && c1[j] <= 'z')) {
			if (c1[j] <= 'Z')
				cnt1[c1[j] - 'A']++;
			else
				cnt1[c1[j] - 'a']++;
		}
	}
	for (j = 0; j < 26; j++) {
		if (cnt1[j])
			printf("%c: %d\n", 'A' + j, cnt1[j]);
	}
	int count = 0, count1 = 0;

	for (int k = 0; k < 26; k++) {
		if (cnt[k] && cnt1[k])
			count++;
		if (cnt[k] || cnt1[k])
			count1++;
	}


	if (count == count1)
		printf("yes");
	else
		printf("no");

	return 0;
}
