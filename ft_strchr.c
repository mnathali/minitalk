/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:55:17 by mnathali          #+#    #+#             */
/*   Updated: 2021/10/25 23:54:15 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*str;

	if (!s)
		return (0);
	str = (char *)s;
	i = 0;
	while (c >= 256)
		c -= 256;
	while (str[i] != c && str[i] != '\0')
		i++;
	if (str[i] != c)
		return (0);
	return (&str[i]);
}
