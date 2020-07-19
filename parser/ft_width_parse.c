/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaurine <olaurine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 02:47:04 by olaurine          #+#    #+#             */
/*   Updated: 2020/07/19 03:41:01 by olaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_width_parse(const char **line, va_list *va, t_struct *t_s)
{
	if ((**line < '0' || **line > '9') && **line != '*')
		return ;
	if (**line == '*')
	{
		t_s->width = va_arg(*va, int);
		return ;
	}
	t_s->width = ft_atoi(*line);
	while(**line >= '0' && **line <= '9')
		(*line)++;
}
