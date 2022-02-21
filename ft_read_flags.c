/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 18:48:16 by mnathali          #+#    #+#             */
/*   Updated: 2021/12/23 18:48:18 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char	g_flags[] = "cspdiuxX%";

void	next_flag(char **str)
{
	char	*btr;

	btr = *str;
	while (*btr != '%')
		btr++;
	btr++;
	while (!ft_strchr(g_flags, *btr))
		btr++;
	*str = btr + 1;
	return ;
}

char	*what_is_flag(char **str, char **btr, long i)
{
	char	*mtr;
	char	*new;
	char	a;

	a = *(ft_strchr(*str, '%') + 1);
	if (ft_strchr(g_flags, a))
		mtr = what_is_after(*str, i, *(ft_strchr(*str, '%') + 1));
	next_flag(str);
	if (!(*btr))
		return (mtr);
	new = ft_strjoin_another(*btr, mtr);
	free(*btr);
	free(mtr);
	return (new);
}

char	*read_flags(char *str, va_list *dest)
{
	char	*btr;
	char	*mtr;

	btr = 0;
	if (!ft_strchr(str, '%'))
		return (ft_strdup_mod(str));
	while (ft_strchr(str, '%'))
	{
		if ((ft_strchr(str, '%')) == ft_strnstr(str, "%%", ft_strlen(str)))
			btr = what_is_flag(&str, &btr, '%');
		else
			btr = what_is_flag(&str, &btr, va_arg(*dest, long));
		if (!btr)
			return (0);
	}
	mtr = ft_strdup_mod(str);
	str = ft_strjoin_another(btr, mtr);
	free(mtr);
	free (btr);
	return (str);
}
