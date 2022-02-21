/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_what_is_after.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:07:26 by mnathali          #+#    #+#             */
/*   Updated: 2021/12/23 19:07:40 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*what_is_after(char *str, long int i, char a)
{
	char	*mtr;
	char	*fre_p;

	fre_p = what_inside_par(a, i);
	mtr = ft_strjoin_mod(str, fre_p);
	free(fre_p);
	return (mtr);
}
