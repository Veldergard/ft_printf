/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaurine <olaurine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 18:30:51 by olaurine          #+#    #+#             */
/*   Updated: 2020/07/24 01:45:08 by olaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_pf_int_minus(size_t pointer, int len, t_struct *t_s)
{
	if (len < t_s->precision)
	{
		while (len < t_s->precision)
		{
			write(1, "0", 1);
			len++;
		}
	}
	ft_put_uns_nbr_base(pointer, 10, 0, 1);
	while ((unsigned int) len++ < t_s->length)
		write(1, " ", 1);
}

static void	ft_pf_int_zero(size_t pointer, int len, t_struct *t_s)
{
	while ((unsigned int) len++ < t_s->length)
		write(1, "0", 1);
	ft_put_uns_nbr_base(pointer, 10, 0, 1);
}

static void	ft_pf_int_without_flags(size_t pointer, int len, t_struct *t_s)
{
	while (t_s->width > t_s->precision)
	{
		write(1, " ", 1);
		t_s->width--;
	}
	while (len++ < t_s->precision)
		write(1, "0", 1);
	ft_put_uns_nbr_base(pointer, 10, 0, 1);
}

void	ft_pf_pointer(va_list *va, t_struct *t_s)
{
	int		len;
	size_t	pointer;

	pointer = (size_t) va_arg(*va, void*);
	len = uns_num_len_base(pointer, 16);
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
		ft_pf_int_minus(pointer, len, t_s);
	else if (t_s->flags & FLG_ZERO && !t_s->dot)
		ft_pf_int_zero(pointer, len, t_s);
	else
		ft_pf_int_without_flags(pointer, len, t_s);
}
