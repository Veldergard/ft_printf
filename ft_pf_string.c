/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaurine <olaurine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 16:28:33 by olaurine          #+#    #+#             */
/*   Updated: 2020/07/27 21:34:59 by olaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_str(char *s, unsigned int len, t_struct *t_s)
{
	unsigned int i;

	i = len;
	if (t_s->flags & FLG_MINUS)
	{
		write(1, s, len);
		while (i++ < t_s->length)
			write(1, " ", 1);
	}
	else
	{
		while (i++ < t_s->length)
			write(1, " ", 1);
		write(1, s, len);
	}
}

void		ft_pf_string(va_list *va, t_struct *t_s)
{
	char			*s;
	unsigned int	len;

	if (!(s = va_arg(*va, char*)))
		s = "(null)";
	len = ft_strlen(s);
	if ((unsigned int)t_s->precision < len && t_s->dot)
		len = (unsigned int)t_s->precision;
	if ((unsigned int)t_s->width > len)
		t_s->length = (unsigned int)t_s->width;
	else
		t_s->length = len;
	ft_print_str(s, len, t_s);
}
