/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaurine <olaurine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 18:28:58 by olaurine          #+#    #+#             */
/*   Updated: 2020/07/24 14:54:52 by olaurine         ###   ########.fr       */
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

static int	ft_print_line(const char **line)
{
	int len;

	len = 0;
	while (**line && **line != '%')
	{
		write(1, *line, 1);
		*line += 1;
		len++;
	}
	return (len);
}

static int	ft_vprintf(const char *format, va_list *va)
{
	int			cur;
	int			result;
	t_struct	*t_s;

	result = 0;
	if (!(t_s = malloc(sizeof(t_struct))) || !(format))
		return (-1);
	while (*format)
	{
		result += ft_print_line(&format);
		if (!*format)
			break;
		ft_bzero(t_s, sizeof(t_struct));
		cur = 1;
		if (!ft_parser(&format, va, t_s, &cur))
		{
			free(t_s);
			return (-1);
		}
		if (cur == 0)
		{
			result += 1;
			continue;
		}
		format += cur;
		ft_processor(va, t_s);
		result += t_s->length;
	}
	free(t_s);
	return (result);
}

int			ft_printf(const char *format, ...)
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
