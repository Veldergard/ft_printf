/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaurine <olaurine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 18:57:46 by olaurine          #+#    #+#             */
/*   Updated: 2020/07/22 19:12:44 by olaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_pf_int_minus(long long int num, int len, t_struct *t_s)
{
	if (len < t_s->precision)
	{
		while (len < t_s->precision)
		{
			write(1, "0", 1);
			len++;
		}
	}
	ft_putnbr_fd(num, 1);
	while ((unsigned int) len++ < t_s->length)
		write(1, " ", 1);
}

static void	ft_pf_int_zero(long long int num, int len, t_struct *t_s)
{
	if (num < 0)
	{
		num *= -1;
		ft_putchar_fd('-', 1);
	}
	while ((unsigned int) len++ < t_s->length)
		write(1, "0", 1);
	ft_putnbr_fd(num, 1);
}

static void	ft_pf_int_without_flags(long long int num, int len, t_struct *t_s)
{
	while (t_s->width > t_s->precision)
	{
		write(1, " ", 1);
		t_s->width--;
	}
	while (len++ < t_s->precision)
		write(1, "0", 1);
	ft_putnbr_fd(num, 1);
}

void		ft_pf_int(va_list *va, t_struct *t_s)
{
	long long int	num;
	int				len;

	num = (long long int) va_arg(*va, int);
	len = num_len(num);
	if (t_s->dot == 0)
		t_s->precision = 1;
	if (len > t_s->precision)
		t_s->precision = len;
	if (t_s->width >= len && t_s->width >= t_s->precision)
		t_s->length = (unsigned int) t_s->width;
	else if (t_s->precision >= t_s->width && t_s->precision >= len)
		t_s->length = (unsigned int) t_s->precision;
	else
		t_s->length = len;
	if (t_s->flags & FLG_MINUS)
		ft_pf_int_minus(num, len, t_s);
	else if (t_s->flags & FLG_ZERO && !t_s->dot)
		ft_pf_int_zero(num, len, t_s);
	else
		ft_pf_int_without_flags(num, len, t_s);
}

void		ft_pf_uns_int(va_list *va, t_struct *t_s)
{
	long long int	num;
	int				len;

	num = (long long int) va_arg(*va, unsigned int);
	len = num_len(num);
	if (t_s->dot == 0)
		t_s->precision = 1;
	if (len > t_s->precision)
		t_s->precision = len;
	if (t_s->width >= len && t_s->width >= t_s->precision)
		t_s->length = (unsigned int) t_s->width;
	else if (t_s->precision >= t_s->width && t_s->precision >= len)
		t_s->length = (unsigned int) t_s->precision;
	else
		t_s->length = len;
	if (t_s->flags & FLG_MINUS)
		ft_pf_int_minus(num, len, t_s);
	else if (t_s->flags & FLG_ZERO && !t_s->dot)
		ft_pf_int_zero(num, len, t_s);
	else
		ft_pf_int_without_flags(num, len, t_s);
}
