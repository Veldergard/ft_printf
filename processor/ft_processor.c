/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaurine <olaurine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 11:35:40 by olaurine          #+#    #+#             */
/*   Updated: 2020/07/21 18:30:34 by olaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_processor(va_list *va, t_struct *t_s)
{
	if (t_s->type == 'c')
		ft_pf_char(va, t_s);
	else if (t_s->type == 's')
		ft_pf_string(va, t_s);
	else if (t_s->type == 'p')
		ft_pf_pointer(va, t_s);
	// else if (t_s->type == 'd' || t_s->type == 'i')
	// 	ft_pf_int(va, t_s);
	// else if (t_s->type == 'x' || t_s->type == 'X')
	// 	ft_pf_uns_x(va, t_s);
	// else if (t_s->type == 'u')
	// 	ft_pf_uns_int(va, t_s);
}
