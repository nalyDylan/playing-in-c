#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>
#include <limits.h>

#define NUM_POS 2000
struct cache {
	int n;
	unsigned __int128 pn;
	struct cache *next;
};

void positions(unsigned int *n);
unsigned __int128 p(int n);
void addSub(unsigned __int128 *total, int n, bool add);
void print_128(unsigned __int128 res);

unsigned int *ppos = NULL;
struct cache *head = NULL;
struct cache *current;

int main(int argc, char *argv[])
{
	if (argc <= 1)
		return 0;
	int input = atoi(argv[1]);

	ppos = (unsigned int*) malloc(NUM_POS * sizeof(unsigned int));
	*(ppos + 0) = 1;
	positions(ppos);

	unsigned __int128 res = p(input);
	print_128(res);

	free(ppos);
	return 0;
}

void print_128(unsigned __int128 res)
{
	unsigned int var = 0;
	short unsigned int nums[40];
	unsigned int tot = 0;
	unsigned int i = 0;
	while (res > 0 && i < 40) {
		var = res % 10;
		res = res / 10;

		nums[i] = var;
		i++;
		tot += var;
	}
	while (i-- >= 0) {
		printf("%u", nums[i]);
	}
	printf("\n%d\n", tot);
}

void positions(unsigned int *n)
{
	for (int i = 1; i < NUM_POS; i++) {
		if (i % 2 == 1) {
			n[i] = n[i - 1] + (i/2) + 1;
		} else {
			n[i] = n[i - 1] + (2 * (i/2)) + 1;
		}
	}
}

unsigned __int128 cacheSearch(int n)
{
	current = head;
	while (current != NULL) {
		if (current->n == n)
			return current->pn;
		current = current->next;
	}
	return 0;
}

void insertCache(int n, unsigned __int128 pn)
{
	struct cache *new = (struct cache *)malloc(sizeof(struct cache));
		new->n = n;
		new->pn = pn;
		new->next = head;
		head = new;
}

void addSub(unsigned __int128 *total, int n, bool add)
{
	unsigned __int128 tmp;
	tmp = cacheSearch(n);
	if (tmp == 0)	{
		tmp = p(n);
		insertCache(n, tmp);
	}

	if (add)
		*total += tmp;
	else
		*total -= tmp;
	return;
}

unsigned __int128 p(int n)
{
	if (n <= 1)
		return 1;
	unsigned __int128 total = 0;

	for (int j = 0; j < NUM_POS; j++) {
		if (ppos[j] <= n)
			addSub(&total, n - ppos[j], ((j / 2) % 2 == 0));
		else
			break;
	}
	return total;
}