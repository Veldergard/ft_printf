/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaurine <olaurine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 02:46:53 by olaurine          #+#    #+#             */
/*   Updated: 2020/07/18 17:59:38 by olaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flags_parse(const char **format, t_struct *t_s)
{
	t_s->flags = FLG_NONE;
	while (**format)
	{
		if (**format == '-')
			t_s->flags |= FLG_MINUS;
		else if (**format == '+')
			t_s->flags |= FLG_PLUS;
		else if (**format == ' ')
			t_s->flags |= FLG_SPACE;
		else if (**format == '#')
			t_s->flags |= FLG_HASH;
		else if (**format == '0')
			t_s->flags |= FLG_ZERO;
		else
			break;
		(*format)++;
		t_s->length += 1;
	}
}
