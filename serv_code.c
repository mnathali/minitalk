#include "minitalk.h"

static void make_zero(short *i, unsigned char *c)
{
	*i = 0;
	*c = 0;
}

void handler(int n, siginfo_t *inf, void *context)
{
	static unsigned char c;
	static short i;
	static int pid;

	(void)context;
	if (pid != (int)inf->si_pid && i != 0)
	{
		write(1, "\ninterrupted\n", 13);
		sleep(5);
		make_zero(&i, &c);
		return ;
	}
	pid = (int)inf->si_pid;
	if (n == SIGUSR1)
		c = 2 * (unsigned short)c + 1;
	else
		c = 2 * (unsigned short)c;
	i++;
	if (i == SZ + 1)
	{
		write(1, &c, 1);
		make_zero(&i, &c);
	}
	if (kill(pid, SIGUSR1) == -1)
		make_zero(&i, &c);
}

int	main(void)
{
	struct sigaction sa = {0};
	sigset_t set_mask;

	sigemptyset(&set_mask);
	sigaddset(&set_mask, SIGUSR1);
	sigaddset(&set_mask, SIGUSR2);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sa.sa_mask = set_mask;

	write(1, "PID: ", 5);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
