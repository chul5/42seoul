/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:24:46 by coh               #+#    #+#             */
/*   Updated: 2022/08/07 20:54:03 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

size_t	ft_strlen(const char *s);
int		ft_printf(const char *s, ...);
int		ft_putchar(char c);
int		ft_puthex(va_list ap, char c);
int		ft_putstr(char *s);
int		ft_putnbr(int n, int *cnt);
int		ft_putunbr(size_t n, size_t bn, char *base, int *cnt);
int		ft_putunb(va_list ap);

#endif