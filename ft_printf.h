/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:45:15 by ameteori          #+#    #+#             */
/*   Updated: 2021/12/06 15:47:30 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_size(int n);
int		ft_unsigned_size(unsigned int n);
int		ft_hex(unsigned long long num, char *base);
void	ft_putunsnbr_fd(unsigned int n, int fd);
int		ft_ch(va_list pr);
int		ft_str(va_list pr);
int		ft_digit(va_list pr);
int		ft_pointer(va_list pr);
int		ft_percent(void);
int		ft_upperhex(va_list pr);
int		ft_lowerhex(va_list pr);
int		ft_udigit(va_list pr);
int		next_symbol(const char *str, va_list pr, int i);
int		ft_len_str(const char *str, va_list pr);
int		ft_printf(const char *str, ...);

#endif