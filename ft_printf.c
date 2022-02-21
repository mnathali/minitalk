/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 18:05:12 by mnathali          #+#    #+#             */
/*   Updated: 2021/12/23 20:01:47 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char	g_flags[] = "cspdiuxX%";

char	*check_string(char *str)
{
	if (!str)
		return (0);
	while (ft_strchr(str, '%')
		&& ft_strchr(g_flags, *(ft_strchr(str, '%') + 1)))
		str = (ft_strchr(str, '%') + 2);
	if (ft_strchr(str, '%'))
		return (0);
	return (str);
}

static int	how_much_will_be_printed(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*str && (str[0][i] != '\0' || str[0][i + 1] != '\0'))
	{
		write(1, &str[0][i], 1);
		if (str[0][i] == '\0')
		{
			j++;
			i++;
		}
		i++;
	}
	free(*str);
	return (i - j);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*str;

	str = (char *)format;
	if (!check_string(str))
		return (-1);
	va_start(args, format);
	str = read_flags(str, &args);
	if (!str)
		return (-1);
	va_end(args);
	return (how_much_will_be_printed(&str));
}
