/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaurine <olaurine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 23:04:19 by olaurine          #+#    #+#             */
/*   Updated: 2020/07/21 18:03:32 by olaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_type_parse(const char **line, t_struct *t_s)
{
	if (!ft_strchr("cspdiuxX%", **line))
		return (0);
	t_s->type = **line;
	(*line)++;
	return(1);
}

static void	ft_precision_parse(const char **line, va_list *va, t_struct *t_s)
{
	if (**line != '.')
		return ;
	(*line)++;
	if (**line == '*')
	{
		t_s->precision = va_arg(*va, int);
	}
	else
	{
		t_s->precision = ft_atoi(*line);
		while(**line >= '0' && **line <= '9')
			(*line)++;
	}
	if (t_s->precision < 0)
		t_s->precision = 0;
}

static void	ft_width_parse(const char **line, va_list *va, t_struct *t_s)
{
	if ((**line < '0' || **line > '9') && **line != '*')
		return ;
	if (**line == '*')
	{
		t_s->width = va_arg(*va, int);
		if (t_s->width < 0)
		{
			t_s->flags = t_s->flags | FLG_MINUS;
			t_s->width *= -1;
			if (t_s->width < 0)
				t_s->width -= 1;
		}
	}
	else
	{
		t_s->width = ft_atoi(*line);
		while(**line >= '0' && **line <= '9')
			(*line)++;
	}
}

static void	ft_flags_parse(const char **line, t_struct *t_s)
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
