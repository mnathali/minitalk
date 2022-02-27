/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:24:46 by mnathali          #+#    #+#             */
/*   Updated: 2021/10/20 17:07:31 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	a;

	if (n < 0)
		write(fd, "-", sizeof(char));
	while (n / 10 != 0)
	{
		if (n > 0)
			n = -n;
		ft_putnbr_fd((-1) * (n / 10), fd);
		n = (-1) * n % 10;
	}
	if (n < 0)
		n = -n;
	a = n + '0';
	write(fd, &a, sizeof(char));
}
