#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void	*func1(void *arg)
{
	for (int i = 0; i < 100; i++)
		fprintf(stderr, "%s\n", (char*)arg);
	return (NULL);
}

void	*func2(void *arg)
{
	for (int i = 0; i < 100; i++)
		fprintf(stderr, "%s\n", (char*)arg);
	return (NULL);
}

int	main(void)
{
	pthread_t	t1;
	pthread_t	t2;

	pthread_create(&t1, NULL, func1, "Hello");
	pthread_create(&t2, NULL, func2, "World!");

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
}
