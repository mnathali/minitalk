#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include "ft_printf.h"

static const int g_num;

void handler(int n, siginfo_t *inf, void *context)
{
	static int c;
	static int i;
	int pid;

	pid = (int)inf->si_pid;
	if (n == SIGUSR1)
		c = 2 * c + 1;
	else
		c = 2 * c;
	i++;
	if (i == 31)
	{
		kill(pid, SIGUSR2);
		ft_printf("%c", c);
		i = 0;
		c = 0;
	}
	else
		kill(pid, SIGUSR1);
}


int	main(int argc, char **argv)
{
	int c;
	struct sigaction sa = {0};

	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sa.sa_sigaction = handler;

	ft_printf("PID: %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}