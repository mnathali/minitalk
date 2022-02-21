#include <signal.h>
#include <unistd.h>
#include <stdio.h>

int	ft_atoi(const char *str)
{
	size_t		i;
	long long	j;
	short		sign;

	i = 0;
	j = 0;
	sign = 1;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		if (j * 10 + (sign * (str[i] - '0')) < j && sign > 0)
			return (-1);
		if (j * 10 + (sign * (str[i] - '0')) > j && sign < 0)
			return (0);
		j = j * 10 + (sign * (str[i] - '0'));
		i++;
	}
	return (j);
}

short	get_binary(short c, int pid, int n)
{
	int j;
//printf("n = %d\n", n);
	if (n > 0)
		j = get_binary(c / 2, pid, n - 1);
	if (j == -1)
		return (-1);
	if (c % 2)
		j = kill(pid, SIGUSR1);
	else
		j = kill(pid, SIGUSR2);
	usleep(50);
	//printf("n = %d\n", c % 2);
	return (j);
}

int main(int argc, char const *argv[])
{
	int	pid;
	int	i;
	short	c;
	short	j;

	i = 0;
	pid = ft_atoi(argv[1]);
	while (argv[2][i] != 0)
	{
		c = (short)argv[2][i];
		j = get_binary(c, pid, 30);
		/*if (j == -1)
		{
			printf("hello world\n");
			break ;
		}*/
		i++;
	}
	return (0);
}