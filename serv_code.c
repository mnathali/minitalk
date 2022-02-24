#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include "ft_printf.h"
#define SZ 6 //30

static const int g_num;

typedef struct s_list
{
	int pid;
	int i;
	int c;
	struct s_list *next;
} m_list;

m_list *tsl_new(int process_id)
{
	m_list *new;

	new = malloc(sizeof(new));
	new->pid = process_id;
	new->i = 0;
	new->c = 0;
	new->next = 0;
	return (new);
}

m_list *get_client_pid(int process_id, m_list *lst)
{
	m_list *tsl;

	tsl = lst;
	while (tsl && tsl->pid != process_id)
		tsl = tsl->next;
	if (!tsl)
	{
		tsl = lst;
		while (tsl->next != 0)
			tsl = tsl->next;
		tsl->next = tsl_new(process_id);
		tsl = tsl->next;
	}
	return (tsl);
}

void handler(int n, siginfo_t *inf, void *context)
{
	static m_list *lst;
	int process_id;
	m_list *tsl;

	process_id = (int)inf->si_pid;
	if (!lst)
		lst = tsl_new(process_id);
	tsl = get_client_pid(process_id, lst);
	if (n == SIGUSR1)
		tsl->c = 2 * tsl->c + 1;
	else
		tsl->c = 2 * tsl->c;
	(tsl->i) += 1;
	if (tsl->i == SZ + 1)
	{
		ft_printf("%c", tsl->c);
		tsl->i = 0;
		tsl->c = 0;
		kill(tsl->pid, SIGUSR2);
	}
	else
		if (kill(tsl->pid, SIGUSR1) == -1)
		{
			tsl->i = 0;
			tsl->c = 0;
		}
}

/*void handler(int n, siginfo_t *inf, void *context)
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
	if (i == SZ + 1)
	{
		ft_printf("%c", c);
		i = 0;
		c = 0;
		kill(pid, SIGUSR2);
	}
	else
		kill(pid, SIGUSR1);
}*/

int	main(int argc, char **argv)
{
	int c;
	struct sigaction sa = {0};
	sigset_t set_mask;

//	sigemptyset(&set_mask);
//	sigaddset(&set_mask, SIGUSR1);
//	sigaddset(&set_mask, SIGUSR2);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
//	sa.sa_mask = set_mask;

	ft_printf("PID: %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}