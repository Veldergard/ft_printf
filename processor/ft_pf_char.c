/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaurine <olaurine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 13:47:49 by olaurine          #+#    #+#             */
/*   Updated: 2020/07/21 18:23:22 by olaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pf_char(va_list *va, t_struct *t_s)
{
	unsigned char	c;
	unsigned int	i;

	i = 1;
	if (t_s->width > 1)
		t_s->length = (unsigned int) t_s->width;
	else
		t_s->length = 1;
	c = (unsigned char)va_arg(*va, int);
	if (t_s->flags & FLG_MINUS)
	{
		write(1, &c, 1);
		while (i++ < t_s->length)
			write(1, " ", 1);
	}
	else
	{
		while (i++ < t_s->length)
			write(1, " ", 1);
		write(1, &c, 1);
	}
}
