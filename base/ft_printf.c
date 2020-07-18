/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaurine <olaurine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 18:28:58 by olaurine          #+#    #+#             */
/*   Updated: 2020/07/18 16:59:03 by olaurine         ###   ########.fr       */
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

int		ft_print_line(char **line)
{
	if (!*line)
		return (0);
	while (*line[len] && *line[len] != '%')
		write(1, *(line) + len++, 1);
	*line += len;
	return (len);
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
