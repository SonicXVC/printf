/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:45:05 by ameteori          #+#    #+#             */
/*   Updated: 2021/12/06 15:43:38 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_upperhex(va_list pr)
{
	unsigned int	h;

	h = va_arg(pr, unsigned int);
	return (ft_hex(h, "0123456789ABCDEF") - 1);
}

int	ft_lowerhex(va_list pr)
{
	unsigned int	h;

	h = va_arg(pr, unsigned int);
	return (ft_hex(h, "0123456789abcdef") - 1);
}

int	ft_udigit(va_list pr)
{
	unsigned int	i;

	i = va_arg(pr, unsigned int);
	ft_putunsnbr_fd(i, 1);
	return (ft_unsigned_size(i) - 1);
}
