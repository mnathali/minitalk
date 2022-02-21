/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:03:37 by mnathali          #+#    #+#             */
/*   Updated: 2021/12/23 19:03:39 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static short	ft_lenght_unsigned(unsigned int n, char a, short *k)
{
	short	j;

	if (a == 'u')
		*k = 10;
	else
		*k = 16;
	j = 0;
	if (n == 0)
		j = j + 1;
	while (n != 0)
	{
		j++;
		n = n / *k;
	}
	return (j);
}

char	*ft_itoa_unsigned(unsigned int n, char a)
{
	char	*str;
	short	j;
	short	k;

	j = ft_lenght_unsigned(n, a, &k);
	str = malloc(sizeof(char) * (j + 2));
	if (!str)
		return (0);
	str[j] = '\0';
	str[j + 1] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		j--;
		if (a == 'u' || (k == 16 && n % k < 10))
			str[j] = (n % k) + '0';
		else if (a == 'x')
			str[j] = ((n % k) - 10) + 'a';
		else
			str[j] = ((n % k) - 10) + 'A';
		n = n / k;
	}
	return (str);
}
