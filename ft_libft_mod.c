/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_mod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:04:56 by mnathali          #+#    #+#             */
/*   Updated: 2021/12/23 19:04:58 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen_mod(const char *str, int *j)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0' || str[i + 1] != '\0')
	{
		if (str[i] == 0)
		{
			if (*j < 0)
				*j = *j - 1;
			else if (*j > 0)
				*j = *j + 1;
		}
		i++;
	}
	return (i);
}

char	*ft_strdup_mod(char *s1)
{
	char	*str;
	size_t	i;

	if (!s1)
		return (0);
	i = 0;
	while (s1[i] != '\0')
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

char	*ft_strjoin_another(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1 || !s2)
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != '\0' || s1[i + 1] != '\0')
		i++;
	while (s2[j] != '\0' || s2[j + 1] != '\0')
		j++;
	str = malloc(sizeof(char) * (i + j + 2));
	if (!str)
		return (0);
	while (*s1 != '\0' || *(s1 + 1) != '\0')
		*str++ = *s1++;
	while (*s2 != '\0' || *(s2 + 1) != '\0')
		*str++ = *s2++;
	*str++ = '\0';
	*str++ = '\0';
	return (str - (i + j + 2) * sizeof(char));
}

char	*ft_strjoin_mod(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (s1 && s1[i] != '%')
		i++;
	while (s2 && (s2[j] != '\0' || s2[j + 1] != '\0'))
		j++;
	str = malloc(sizeof(char) * (i + j + 2));
	if (!str)
		return (0);
	while (s1 && *s1 != '%')
		*str++ = *s1++;
	while (s2 && (*s2 != '\0' || *(s2 + 1) != '\0'))
		*str++ = *s2++;
	*str++ = '\0';
	*str++ = '\0';
	return (str - (i + j + 2) * sizeof(char));
}
