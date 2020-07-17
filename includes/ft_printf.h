/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaurine <olaurine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 15:44:57 by olaurine          #+#    #+#             */
/*   Updated: 2020/07/16 19:52:19 by olaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_struct
{
	unsigned char	flags;
	int				width;
	char			precision;
	unsigned char	type;
	unsigned int	length;
}					t_struct;

int		ft_printf(const char *format, ...);

#endif
