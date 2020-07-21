/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaurine <olaurine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 02:46:53 by olaurine          #+#    #+#             */
/*   Updated: 2020/07/21 13:11:03 by olaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flags_parse(const char **line, t_struct *t_s)
{
	t_s->flags = FLG_NONE;
	while (**line)
	{
		if (**line == '-')
			t_s->flags |= FLG_MINUS;
		else if (**line == '+')
			t_s->flags |= FLG_PLUS;
		else if (**line == ' ')
			t_s->flags |= FLG_SPACE;
		else if (**line == '#')
			t_s->flags |= FLG_HASH;
		else if (**line == '0')
			t_s->flags |= FLG_ZERO;
		else
			break;
		(*line)++;
	}
}
