/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrada <fbarrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 18:33:05 by fbarrada          #+#    #+#             */
/*   Updated: 2026/05/18 11:53:44 by fbarrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check(const char *str, int i, int cont, va_list args)
{
	if (str[i + 1] == '%')
		cont += (ft_printchar('%'));
	else if (str[i + 1] == 'c')
		cont += (ft_printchar(va_arg(args, int)));
	else if (str[i + 1] == 's')
		cont += (ft_printstr(va_arg(args, char *)));
	else if (str[i + 1] == 'd' || str[i + 1] == 'i')
		cont += (ft_printnbr(va_arg(args, int)));
	else if (str[i + 1] == 'u')
		cont += (ft_printunsnbr(va_arg(args, unsigned int)));
	else if (str[i + 1] == 'x')
		cont += (ft_printhex('x', va_arg(args, unsigned int)));
	else if (str[i + 1] == 'X')
		cont += (ft_printhex('X', va_arg(args, unsigned int)));
	else if (str[i + 1] == 'p')
		cont += (ft_printptr(va_arg(args, void *)));
	return (cont);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		cont;

	va_start(args, str);
	i = 0;
	cont = 0;
	while (str[i])
	{
		if (str[i] == '%')
			cont += check(str, i++, cont, args);
		else
			cont += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (cont);
}
