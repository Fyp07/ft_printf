#ifndef HELPERS_H
# define HELPERS_H

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int	ft_printchar(char c);
int	ft_printstr(char *str);
int	ft_printnbr(long n);
int	ft_printunsnbr(unsigned int n);
int	ft_printhex(unsigned int n);
int	ft_printbighex(unsigned int n);

#endif