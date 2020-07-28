/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaurine <olaurine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 23:04:19 by olaurine          #+#    #+#             */
/*   Updated: 2020/07/27 21:25:57 by olaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_type_parse(const char **line, t_struct *t_s, int *cur)
{
	if (!ft_strchr("cspdiuxX%", (*line)[*cur]))
		return (0);
	t_s->type = (*line)[*cur];
	(*cur)++;
	return (1);
}

static void	ft_precision_parse(const char **line, va_list *va,
				t_struct *t_s, int *cur)
{
	if ((*line)[*cur] != '.')
	{
		t_s->precision = 1;
		return ;
	}
	(*cur)++;
	if ((*line)[*cur] == '*')
	{
		(*cur)++;
		t_s->precision = va_arg(*va, int);
	}
	else
	{
		t_s->precision = ft_atoi((*line) + *cur);
		while ((*line)[*cur] >= '0' && (*line)[*cur] <= '9')
			(*cur)++;
	}
	t_s->dot = 1;
	if (t_s->precision < 0)
	{
		t_s->dot = 0;
		t_s->precision = 1;
	}
}

static void	ft_width_parse(const char **line, va_list *va,
				t_struct *t_s, int *cur)
{
	if (((*line)[*cur] < '0' || (*line)[*cur] > '9') && (*line)[*cur] != '*')
		return ;
	if ((*line)[*cur] == '*')
	{
		(*cur)++;
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
		t_s->width = ft_atoi((*line) + *cur);
		while ((*line)[*cur] >= '0' && (*line)[*cur] <= '9')
			(*cur)++;
	}
}

static void	ft_flags_parse(const char **line, t_struct *t_s, int *cur)
{
	while ((*line)[*cur])
	{
		if ((*line)[*cur] == '-')
			t_s->flags |= FLG_MINUS;
		else if ((*line)[*cur] == '+')
			t_s->flags |= FLG_PLUS;
		else if ((*line)[*cur] == ' ')
			t_s->flags |= FLG_SPACE;
		else if ((*line)[*cur] == '#')
			t_s->flags |= FLG_HASH;
		else if ((*line)[*cur] == '0')
			t_s->flags |= FLG_ZERO;
		else
			break ;
		(*cur)++;
	}
}

int			ft_parser(const char **format, va_list *va, t_struct *t_s, int *cur)
{
	if (!*format)
		return (0);
	ft_flags_parse(format, t_s, cur);
	ft_width_parse(format, va, t_s, cur);
	ft_precision_parse(format, va, t_s, cur);
	if (!(*format)[*cur])
	{
		write(1, *format, 1);
		*cur = 0;
		(*format)++;
		return (1);
	}
	return (ft_type_parse(format, t_s, cur));
}
