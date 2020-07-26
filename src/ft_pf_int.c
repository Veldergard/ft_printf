/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaurine <olaurine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 18:57:46 by olaurine          #+#    #+#             */
/*   Updated: 2020/07/26 23:39:04 by olaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_pf_int_minus(long long int num, int len, t_struct *t_s, int sign)
{
	if (num < 0)
	{
		num = -num;
		ft_putchar_fd('-', 1);
	}
	while (len < t_s->precision)
	{
		write(1, "0", 1);
		len++;
	}
	if (t_s->precision != 0 || num != 0)
		ft_putnbr_base(num, 10, 0, 1);
	while ((unsigned int) len + sign < t_s->length)
	{
		write(1, " ", 1);
		len++;
	}
}

static void	ft_pf_int_zero(long long int num, int len, t_struct *t_s, int sign)
{
	if (num < 0)
	{
		num = -num;
		ft_putchar_fd('-', 1);
	}
	while ((unsigned int) len + sign < t_s->length)
	{
		write(1, "0", 1);
		len++;
	}
	if (t_s->precision != 0 || num != 0)
		ft_putnbr_base(num, 10, 0, 1);
}

static void	ft_pf_int_without_flags(long long int num, int len, t_struct *t_s, int sign)
{
	while (t_s->width > t_s->precision + sign)
	{
		write(1, " ", 1);
		t_s->width--;
	}
	if (num < 0)
	{
		num *= -1;
		ft_putchar_fd('-', 1);
	}
	while (len < t_s->precision)
	{
		write(1, "0", 1);
		len++;
	}
	if (t_s->precision != 0 || num != 0)
		ft_putnbr_base(num, 10, 0, 1);
}

void		ft_pf_int(va_list *va, t_struct *t_s)
{
	long long int	num;
	int				len;
	int				sign;

	sign = 0;
	num = (long long int) va_arg(*va, int);
	len = num_len_base(num, 10, &sign);
	if (len > t_s->precision && num)
		t_s->precision = len;
	if (!t_s->precision && !num)
		len = 0;
	if (t_s->width >= len + sign && t_s->width >= t_s->precision)
		t_s->length = (unsigned int) t_s->width;
	else if (t_s->precision >= t_s->width && t_s->precision >= len)
		t_s->length = (unsigned int) t_s->precision + sign;
	else
		t_s->length = len + sign;
	if (t_s->flags & FLG_MINUS)
		ft_pf_int_minus(num, len, t_s, sign);
	else if (t_s->flags & FLG_ZERO && !t_s->dot)
		ft_pf_int_zero(num, len, t_s, sign);
	else
		ft_pf_int_without_flags(num, len, t_s, sign);
}

void		ft_pf_uns_int(va_list *va, t_struct *t_s)
{
	long long int	num;
	int				len;

	num = (long long int) va_arg(*va, unsigned int);
	len = num_len_base(num, 10, NULL);
	if (len > t_s->precision && num)
		t_s->precision = len;
	if (!t_s->precision && !num)
		len = 0;
	if (t_s->width >= len && t_s->width >= t_s->precision)
		t_s->length = (unsigned int) t_s->width;
	else if (t_s->precision >= t_s->width && t_s->precision >= len)
		t_s->length = (unsigned int) t_s->precision;
	else
		t_s->length = len;
	if (t_s->flags & FLG_MINUS)
		ft_pf_int_minus(num, len, t_s, 0);
	else if (t_s->flags & FLG_ZERO && !t_s->dot)
		ft_pf_int_zero(num, len, t_s, 0);
	else
		ft_pf_int_without_flags(num, len, t_s, 0);
}
