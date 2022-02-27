#ifndef MINITALK_H
#define MINITALK_H
#include <signal.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#define SZ 7

void	handler(int n, siginfo_t *inf, void *context);
void	ft_putnbr_fd(int n, int fd);

#endif