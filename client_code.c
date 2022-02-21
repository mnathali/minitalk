#include <signal.h>
#include <unistd.h>
#include <stdio.h>

static int g_flag;

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

short	get_binary(int c, int pid, int n)
{
	int j;
	
	j = 0;
	if (n > 0)
		j = get_binary(c / 2, pid, n - 1);
	if (j == -1)
		return (j);
	if (c % 2)
		j = kill(pid, SIGUSR1);
	else
		j = kill(pid, SIGUSR2);
	if (j == -1)
		return (j);
	pause();
	return (j);
}

void handler(int n)
{
	if (n == SIGUSR2)
		g_flag = 0;
	else
		g_flag = -1;
}

int main(int argc, char const *argv[])
{
	int	pid;
	int	i;
	int	c;
	struct sigaction sa = {0};

	sa.sa_handler = handler;

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	i = 0;
	pid = ft_atoi(argv[1]);
	while (argv[2][i] != 0)
	{
		c = (short)argv[2][i];
		get_binary(c, pid, 30);
		if (g_flag == -1);
		{
			write(1,"Not sended\n", 11);
			break ;
		}
		i++;
	}
	return (0);
}