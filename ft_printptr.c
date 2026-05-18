/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrada <fbarrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 11:52:17 by fbarrada          #+#    #+#             */
/*   Updated: 2026/05/18 11:52:42 by fbarrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printptr(void *ptr)
{
	int	cont;

	cont = 2;
	if (!ptr)
		return (ft_printstr("(nil)"));
	write(1, "0x", 2);
	cont += ft_printhex('x', (uintptr_t)ptr);
	return (cont);
}
