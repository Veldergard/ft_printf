/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaurine <olaurine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 23:04:19 by olaurine          #+#    #+#             */
/*   Updated: 2020/07/21 13:13:33 by olaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parser(const char **format, va_list *va, t_struct *t_s)
{
	if (!*format)
		return (0);
	(*format)++;
	ft_flags_parse(format, t_s);
	ft_width_parse(format, va, t_s);
	ft_precision_parse(format, va, t_s);
	return (ft_type_parse(format, t_s));
}
