/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrada <fbarrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 18:33:05 by fbarrada          #+#    #+#             */
/*   Updated: 2026/05/13 18:53:18 by fbarrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

int    ft_printf(const char *str, ...)
{
        va_list args;
        va_start(args, str);

	int     i;
        int     cont;

        i = 0;
        cont = 0;
        while (str[i])
        {
                if (str[i] == '%')
                {
                        if (str[i + 1] == '%')
                                cont += ft_printchar('%');
                        else if (str[i + 1] == 'c')
                                cont += ft_printchar(va_arg(args, int));
                        else if (str[i + 1] == 's')
                                cont += ft_printstr(va_arg(args, char *));
                        else if (str[i + 1] == 'd')
                                cont += ft_printnbr(va_arg(args, int));
                        else if (str[i + 1] == 'i')
                                cont += ft_printnbr(va_arg(args, int));
                        else if (str[i + 1] == 'u')
                                cont += ft_printunsnbr(va_arg(args, unsigned int));
                        else if (str[i + 1] == 'x')
                                cont += ft_printhex(va_arg(args, unsigned int));
                        else if (str[i + 1] == 'X')
                                cont += ft_printbighex(va_arg(args, unsigned int));
                        i++;
                        i++;
                }
                else
                {
                        cont += ft_printchar(str[i]);
                        i++;
                }
        }
        va_end(args);
        return (cont);
}

int     main()
{
        ft_printf("Nome: %x", 125);
        return (0);
}