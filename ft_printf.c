/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:44:45 by ameteori          #+#    #+#             */
/*   Updated: 2021/12/06 15:40:48 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	next_symbol(const char *str, va_list pr, int i)
{
	if (str[i + 1] == 'c')
		return (ft_ch(pr));
	if (str[i + 1] == 's')
		return (ft_str(pr));
	if (str[i + 1] == 'p')
		return (ft_pointer(pr));
	if (str[i + 1] == 'i' || str[i + 1] == 'd')
		return (ft_digit(pr));
	if (str[i + 1] == 'u')
		return (ft_udigit(pr));
	if (str[i + 1] == 'x')
		return (ft_lowerhex(pr));
	if (str[i + 1] == 'X')
		return (ft_upperhex(pr));
	if (str[i + 1] == '%')
		return (ft_percent());
	return (-1);
}

int	ft_len_str(const char *str, va_list pr)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			len += next_symbol(str, pr, i);
			i++;
		}
		else
			ft_putchar_fd(str[i], 1);
		i++;
		len++;
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		res;
	va_list	pr;

	va_start(pr, str);
	res = ft_len_str(str, pr);
	va_end(pr);
	return (res);
}
