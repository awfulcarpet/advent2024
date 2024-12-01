#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bigger(const void* a, const void* b) {
	return *(int *)a - *(int *)b;
}

/*#define LEN 6*/
#define LEN 1000

int part1(FILE *f) {
	char line[16] = {0};
	char num[6] = {0};
	int left[LEN + 1] = {0};
	int right[LEN + 1] = {0};
	int index = 0;
	int sum = 0;

	while (fgets(line, 15, f) != NULL) {
		int i = 0;
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
		sum += abs(left[i] - right[i]);
	}
	return sum;
}

int part2(FILE *f) {
	char line[16] = {0};
	char num[6] = {0};
	int left[LEN + 1] = {0};
	int right[LEN + 1] = {0};
	int index = 0;
	int sim = 0;

	while (fgets(line, 15, f) != NULL) {
		int i = 0;
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
	for (int i = 0; i < index; i++) {
		int count = 0;
		for (int j = 0; j < index; j++) {
			if (right[j] == left[i])
				count++;
		}
		sim += count * left[i];
	}
	return sim;
}

int
main(void) {
	FILE *f = NULL;
	f = fopen("input", "r");

	/*printf("%d\n", part1(f));*/
	printf("%d\n", part2(f));
	fclose(f);
	return 0;
}
