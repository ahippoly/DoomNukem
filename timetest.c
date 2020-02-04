#include <time.h>
#include <stdio.h>

int main()
{
	time_t c;
	int i;
	printf("Beginning test");
	c = time(NULL);
	while (c - time(NULL) != 10)
	{

	}
	printf("Time reached !");
	return (0);
}