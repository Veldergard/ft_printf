/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaurine <olaurine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 13:47:49 by olaurine          #+#    #+#             */
/*   Updated: 2020/07/21 19:01:23 by olaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pf_char(unsigned char c, t_struct *t_s)
{
	unsigned char	c;
	unsigned int	i;

	i = 1;
	if (t_s->width > 1)
		t_s->length = (unsigned int) t_s->width;
	else
		t_s->length = 1;
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
