/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:01:38 by mnathali          #+#    #+#             */
/*   Updated: 2021/12/23 19:01:39 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

short	ft_lenght_of_pointer(unsigned long int n)
{
	short	j;

	j = 2;
	if (n == 0)
		j = j + 3;
	while (n != 0)
	{
		j++;
		n = n / 16;
	}
	return (j);
}

char	*ft_itoa_pointer(unsigned long int n)
{
	char	*str;
	short	j;

	if (n == 0)
		return (ft_strdup_mod("0x0"));
	j = ft_lenght_of_pointer(n);
	str = malloc(sizeof(char) * (j + 2));
	if (!str)
		return (0);
	str[0] = '0';
	str[1] = 'x';
	str[j] = '\0';
	str[j + 1] = '\0';
	while (n != 0)
	{
		j--;
		if (n % 16 < 10)
			str[j] = (n % 16) + '0';
		else
			str[j] = ((n % 16) - 10) + 'a';
		n = n / 16;
	}
	return (str);
}
