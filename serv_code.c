/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serv_code.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:52:06 by mnathali          #+#    #+#             */
/*   Updated: 2022/03/02 16:52:08 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	if (n == 0)
		return (0);
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (str1[i] == str2[i] && i < n && (str1[i] != '\0' || str2[i] != '\0'))
	{
		i++;
		if (i == n)
		{
			i--;
			break ;
		}
	}
	return (str1[i] - str2[i]);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*str;

	str = b;
	i = 0;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	return (b);
}

static void	make_zero(short *i, unsigned char *c, void *context, int p)
{
	static char		str[9];
	static short	k;
	static int		pid;

	(void)context;
	if (pid != p)
	{
		ft_memset(&str[0], 0, 9);
		k = 0;
	}
	pid = p;
	if (k != 8)
	{
		str[k] = *c;
		k++;
	}
	if (ft_strncmp(&str[0], "turn_off", 8) == 0)
	{
		kill(pid, SIGUSR1);
		exit(0);
	}
	*i = 0;
	*c = 0;
}

void	handler(int n, siginfo_t *inf, void *context)
{
	static unsigned char	c;
	static short			i;
	static unsigned int		pid;

	if (pid != (unsigned int)inf->si_pid && i != 0 && (int)inf->si_pid != 0)
	{
		write(1, "\ninterrupted\n", 13);
		sleep(5);
		make_zero(&i, &c, context, pid);
		return ;
	}
	if ((int)inf->si_pid != 0)
		pid = (int)inf->si_pid;
	if (n == SIGUSR1)
		c = 2 * (unsigned short)c + 1;
	else
		c = 2 * (unsigned short)c;
	i++;
	if (i == SZ + 1)
	{
		write(1, &c, 1);
		make_zero(&i, &c, context, pid);
	}
	if (kill(pid, SIGUSR1) == -1)
		make_zero(&i, &c, context, pid);
}

int	main(void)
{
	struct sigaction	sa;
	sigset_t			set_mask;

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
