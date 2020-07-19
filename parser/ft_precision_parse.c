/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_parse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaurine <olaurine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 02:46:59 by olaurine          #+#    #+#             */
/*   Updated: 2020/07/20 01:48:32 by olaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_precision_parse(const char **line, va_list *va, t_struct *t_s)
{
	if (**line != '.')
		return ;
	(*line)++;
	if (**line == '*')
		t_s->precision = va_arg(*va, int);
	else
	{
		t_s->precision = ft_atoi(*line);
		while(**line >= '0' && **line <= '9')
			(*line)++;
	}
}
