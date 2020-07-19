/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaurine <olaurine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 02:47:01 by olaurine          #+#    #+#             */
/*   Updated: 2020/07/20 01:57:16 by olaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_type_parse(const char **line, t_struct *t_s)
{
	if (!ft_strchr("cspdiuxX%", **line))
		return (-1);
	t_s->type = **line;
	(*line)++;
	return(1);
}
