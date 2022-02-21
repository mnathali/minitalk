#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include "ft_printf.h"

char *letter;

int what_is_letter(char *str)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (str[i])
	{
		if (str[i] == '0')
			c = 2 * c;
		else
			c = 2 * c + 1;
		i++;
	}
	return (c);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(count * size);
	if (!str)
		return (0);
	while (count * size - i != 0)
	{
		str[i] = 0;
		i++;
	}
	return ((void *)str);
}

void handler(int n)
{
	int i;

	i = 0;
	while (letter[i])
		i++;
	if (n == SIGUSR1)
		letter[i] = '1';
	else
		letter[i] = '0';
	//ft_printf("c1 = %s\n", letter);
}


int	main(int argc, char **argv)
{
	int c;
	struct sigaction sa = {0};

	sa.sa_handler = handler;

	letter = ft_calloc(32, 1);
	ft_printf("PID: %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		if (letter)
		{
			c = 0;
			while (letter[c] != '\0')
				c++;
			if (c == 31)
			{
				c = what_is_letter(letter);
				ft_printf("%c", c);
				c = 0;
				while (letter[c] != '\0')
				{
					letter[c] = 0;
					c++;
				}
			}
		}
	}
	return (0);
}