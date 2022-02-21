/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_signed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:00:09 by mnathali          #+#    #+#             */
/*   Updated: 2021/12/23 19:00:10 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static short	ft_lenght_signed(int n)
{
	short	j;

	j = 0;
	if (n < 0 || n == 0)
		j = j + 1;
	while (n != 0)
	{
		j++;
		n = n / 10;
	}
	return (j);
}

char	*ft_itoa_signed(int n)
{
	char	*str;
	short	j;

	j = ft_lenght_signed(n);
	str = malloc(sizeof(char) * (j + 2));
	if (!str)
		return (0);
	str[j] = '\0';
	str[j + 1] = '\0';
	if (n < 0)
		str[0] = '-';
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		j--;
		if (n % 10 < 0)
			str[j] = ((-1) * (n % 10)) + '0';
		else
			str[j] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
