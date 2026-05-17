/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrada <fbarrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 18:38:41 by fbarrada          #+#    #+#             */
/*   Updated: 2026/05/13 18:52:12 by fbarrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int    ft_printchar(char c)
{
        return (write(1, &c, 1));
}

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		ft_printchar(str[i++]);
	return (i);
}

int	ft_printnbr(long n)
{
	int	cont;
	
	cont = 0;
	if (n < 0)
	{
		cont += ft_printchar('-');
		n = -n;
	}
	if (n > 9)
		cont += ft_printnbr(n / 10);
	cont += ft_printchar((n % 10) + 48);
	return (cont);
}

int	ft_printunsnbr(unsigned int n)
{
	int	cont;

	cont = 0;
	if (n > 9)
		cont += ft_printunsnbr(n / 10);
	cont += ft_printchar((n % 10) + 48);
	return (cont);
}

int	ft_printhex(unsigned int n)
{
	int	cont;

	cont = 0;
	if (n > 9)
		cont += ft_printhex(n / 16);
	cont += ft_printchar("0123456789abcdef"[n % 16]);
	return cont;
}

int	ft_printbighex(unsigned int n)
{
	int	cont;

	cont = 0;
	if (n > 9)
		cont += ft_printhex(n / 16);
	cont += ft_printchar("0123456789ABCDEF"[n % 16]);
	return cont;
}