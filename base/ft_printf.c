/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaurine <olaurine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 18:28:58 by olaurine          #+#    #+#             */
/*   Updated: 2020/07/20 01:33:34 by olaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
malloc
free
write
va_start
va_arg
va_copy
va_end
*/

#include "ft_printf.h"

int		ft_print_line(const char **line)
{
	int len;

	len = 0;
	if (!*line)
		return (0);
	while (**line && **line != '%')
	{
		write(1, *line, 1);
		*line += 1;
		len++;
	}
	return (len);
}

void t_s_init(t_struct *t_s)
{
	t_s->flags = 0;
	t_s->width = 0;
	t_s->precision = 0;
	t_s->type = 0;
	t_s->length = 0;
}

int		ft_vprintf(const char *format, va_list *va)
{
	int result;
	t_struct *t_s;

	result = 0;
	while (*format)
	{
		result += ft_print_line(&format);
		if (!*format)
			break;
		if (!(t_s = malloc(sizeof(t_struct))))
			return (-1);
		t_s_init(t_s);
		ft_parser(&format, va, t_s);
		free(t_s);
	}
	return (result);
}

int		ft_printf(const char *format, ...)
{
	va_list		va;
	int			result;

	if (!format)
		return (-1);
	va_start(va, format);
	result = ft_vprintf(format, &va);
	va_end(va);
	return (result);
}
