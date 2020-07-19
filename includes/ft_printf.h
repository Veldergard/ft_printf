/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaurine <olaurine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 15:44:57 by olaurine          #+#    #+#             */
/*   Updated: 2020/07/19 03:39:10 by olaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# define FLG_NONE  0b00000000
# define FLG_MINUS 0b00000001
# define FLG_PLUS  0b00000010
# define FLG_SPACE 0b00000100
# define FLG_HASH  0b00001000
# define FLG_ZERO  0b00010000

typedef struct		s_struct
{
	unsigned char	flags;
	int				width;
	char			precision;
	unsigned char	type;
	unsigned int	length;
}					t_struct;

int		ft_printf(const char *format, ...);
void	ft_flags_parse(const char **format, t_struct *t_s);
int		ft_parser(const char **format, va_list *va, t_struct *t_s);

#endif
