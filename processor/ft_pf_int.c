/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaurine <olaurine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 18:57:46 by olaurine          #+#    #+#             */
/*   Updated: 2020/07/21 22:09:23 by olaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	num_len(int n)
{
	size_t			len;
	long long int	nb;

	if (n == 0)
		return (1);
	nb = ft_abs_l(n);
	len = 0;
	if (n < 0)
		len++;
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static void	ft_pf_int_minus(int num, int len, t_struct *t_s)
{
	if (len < t_s->precision)
	{
		while (len < t_s->precision)
		{
			write(1, "0", 1);
		}
	}
	ft_putnbr_fd(num, 1);
	while (len++ < t_s->length)
		write(1, " ", 1);
}

static void	ft_pf_int_zero(int num, int len, t_struct *t_s)
{
	while (len++ < t_s->length)
		write(1, "0", 1);
	ft_putnbr_fd(num, 1);
}

static void	ft_pf_int_without_flags(int num, int len, t_struct *t_s)
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
	int				num;
	int				len;

	num = va_arg(*va, int);
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
		ft_pf_int_min(num, len, t_s);
	else if (t_s->flags & FLG_ZERO)
		ft_pf_int_zero(num, len, t_s);
	else
		ft_pf_int_without_flags(num, len, t_s);
}
