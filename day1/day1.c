#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bigger(const void* a, const void* b) {
	return *(int *)a - *(int *)b;
}

#define LEN 1000
int
main(void) {
	FILE *f = NULL;
	f = fopen("input", "r");
	char line[16] = {0};
	char num[6] = {0};
	int left[LEN + 1] = {0};
	int right[LEN + 1] = {0};
	int index = 0;
	int sum = 0;
	while (fgets(line, 15, f) != NULL) {
		int i = 0;
		printf("%lu\n", strlen(line));
		for (; line[i] != ' '; i++);
		memcpy(num, line, i);
		left[index] = atoi(num);
		memset(num, 0, 6);

		for (; line[i] == ' '; i++);
		int j = i;
		for (; line[i] <= '9' && line[i] >= '0'; i++);
		memcpy(num, line + j, i - j);
		right[index] = atoi(num);
		memset(num, 0, 6);

		index++;
	}

	qsort(left, LEN, sizeof(int), bigger);
	qsort(right, LEN, sizeof(int), bigger);

	for(int i = 0; i < index; i++) {
		printf("%d %d\n", left[i], right[i]);
		sum += abs(left[i] - right[i]);
	}
	fclose(f);
	printf("%d\n", sum);
	return 0;
}
