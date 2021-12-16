#include <stdio.h>

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	printf("argc: %i\n", argc);
	while (argv[i])
	{
		printf("argv[%i]: %s\n", i, argv[i]);
		i++;
	}
	return (0);
}