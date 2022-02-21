/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 17:29:43 by mnathali          #+#    #+#             */
/*   Updated: 2021/12/23 20:13:52 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
char	*check_string(char *str);
char	*ft_strchr(const char *s, int c);
char	*read_flags(char *str, va_list *dest);
char	*what_is_flag(char **str, char **btr, long i);
void	next_flag(char **str);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_itoa_pointer(unsigned long int n);
char	*ft_itoa_signed(int n);
char	*ft_itoa_unsigned(unsigned int n, char a);
int		ft_strlen_mod(const char *str, int *j);
size_t	ft_strlen(const char *str);
char	*ft_strdup_mod(char *s1);
char	*ft_strjoin_another(char const *s1, char const *s2);
char	*ft_strjoin_mod(char const *s1, char const *s2);
char	*what_is_after(char *str, long int i, char a);
char	*what_inside_par(char a, long int i);

#endif
