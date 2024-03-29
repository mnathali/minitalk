/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_code.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:50:28 by mnathali          #+#    #+#             */
/*   Updated: 2022/03/02 16:50:30 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static sig_atomic_t	g_flag;

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
	int				j;
	volatile int	k;

	j = 0;
	k = 0;
	if (n > 0)
		j = get_binary(c / 2, pid, n - 1);
	if (j == -1)
		return (j);
	if (c % 2)
		j = kill(pid, SIGUSR1);
	else
		j = kill(pid, SIGUSR2);
	while (g_flag == 0 && k != INT_MAX)
		k++;
	if (g_flag == 0)
		j = -1;
	g_flag = 0;
	return (j);
}

void	handler_client(int n)
{
	(void)n;
	g_flag = 1;
}

int	main(int argc, char const *argv[])
{
	int			pid;
	int			i;
	unsigned char		c;
	struct sigaction	sa;

	if (argc < 2)
		return (0);
	sa.sa_flags = 0;
	sa.sa_mask = 0;
	sa.sa_handler = handler_client;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	i = 0;
	pid = ft_atoi(argv[1]);
	while (argc == 3 && argv[2][i] != 0)
	{
		c = (unsigned char)argv[2][i];
		g_flag = 0;
		if (get_binary(c, pid, SZ) == -1)
		{
			write(1, "Not sended\n", 11);
			break ;
		}
		i++;
	}
	return (0);
}
