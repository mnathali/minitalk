/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:52:40 by mnathali          #+#    #+#             */
/*   Updated: 2022/03/02 16:52:41 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# define SZ 7

void	handler(int n, siginfo_t *inf, void *context);
void	ft_putnbr_fd(int n, int fd);

#endif
