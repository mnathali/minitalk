/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_what_inside_par.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:09:53 by mnathali          #+#    #+#             */
/*   Updated: 2021/12/23 19:09:55 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*only_par_char(unsigned char s2)
{
	int		i;
	char	*str;

	i = 1;
	if (s2 == '\0')
		i = 2;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (0);
	str[0] = s2;
	str[1] = '\0';
	str[2] = '\0';
	if (s2 == 0)
	{
		str[1] = 'c';
		str[2] = '\0';
		str[3] = '\0';
	}
	return (str);
}

static char	*only_par_str(char *s1)
{
	int		i;
	char	*str;

	if (!s1)
		return (ft_strdup_mod("(null)"));
	i = 0;
	while (s1[i] != 0)
		i++;
	str = malloc(i + 2);
	if (!str)
		return (0);
	str[i] = 0;
	str[i + 1] = 0;
	while (i != 0)
	{
		i--;
		str[i] = s1[i];
	}
	return (str);
}

char	*what_inside_par(char a, long int i)
{
	char	*fre_p;

	if (a == 'd' || a == 'i')
		fre_p = ft_itoa_signed(i);
	if (a == 'u' || a == 'x' || a == 'X')
		fre_p = ft_itoa_unsigned(i, a);
	if (a == 'p')
		fre_p = ft_itoa_pointer(i);
	if (a == 's')
		fre_p = only_par_str((char *)i);
	if (a == '%')
		i = 37;
	if (a == 'c' || a == '%')
		fre_p = only_par_char(i);
	return (fre_p);
}
