/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaurine <olaurine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 22:02:31 by olaurine          #+#    #+#             */
/*   Updated: 2020/07/27 21:36:34 by olaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_pf_x_minus(long long int num, int len, t_struct *t_s)
{
	while (len < t_s->precision)
	{
		write(1, "0", 1);
		len++;
	}
	if (t_s->precision != 0 || num != 0)
		ft_putnbr_base(num, 16, t_s->type == 'x' ? 0 : 1, 0);
	while ((unsigned int)len < t_s->length)
	{
		write(1, " ", 1);
		len++;
	}
}

static void	ft_pf_x_zero(long long int num, int len, t_struct *t_s)
{
	while ((unsigned int)len < t_s->length)
	{
		write(1, "0", 1);
		len++;
	}
	if (t_s->precision != 0 || num != 0)
		ft_putnbr_base(num, 16, t_s->type == 'x' ? 0 : 1, 0);
}

static void	ft_pf_x_without_flags(long long int num, int len, t_struct *t_s)
{
	while (t_s->width > t_s->precision)
	{
		write(1, " ", 1);
		t_s->width--;
	}
	while (len < t_s->precision)
	{
		write(1, "0", 1);
		len++;
	}
	if (t_s->precision != 0 || num != 0)
		ft_putnbr_base(num, 16, t_s->type == 'x' ? 0 : 1, 0);
}

void		ft_pf_x(va_list *va, t_struct *t_s)
{
	long long int	num;
	int				len;

	num = (long long int)va_arg(*va, unsigned int);
	len = num_len_base(num, 16, NULL);
	if (len > t_s->precision && num)
		t_s->precision = len;
	if (!t_s->precision && !num)
		len = 0;
	if (t_s->width >= len && t_s->width >= t_s->precision)
		t_s->length = (unsigned int)t_s->width;
	else if (t_s->precision >= t_s->width && t_s->precision >= len)
		t_s->length = (unsigned int)t_s->precision;
	else
		t_s->length = len;
	if (t_s->flags & FLG_MINUS)
		ft_pf_x_minus(num, len, t_s);
	else if (t_s->flags & FLG_ZERO && !t_s->dot)
		ft_pf_x_zero(num, len, t_s);
	else
		ft_pf_x_without_flags(num, len, t_s);
}
