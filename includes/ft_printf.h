/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaurine <olaurine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 15:44:57 by olaurine          #+#    #+#             */
/*   Updated: 2020/07/27 20:01:31 by olaurine         ###   ########.fr       */
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
	char			dot;
	int				precision;
	unsigned char	type;
	unsigned int	length;
}					t_struct;

int		ft_printf(const char *format, ...);
int		ft_parser(const char **format, va_list *va, t_struct *t_s, int *cur);
void	ft_putnbr_base(long long int n, char base,
						char is_up_case, char print_sign);
int		num_len_base(long long int n, char base, int *sign);
void	ft_put_uns_nbr_base(size_t n, char base,
						char is_up_case, char print_sign);
int		uns_num_len_base(size_t n, char base);
void	ft_processor(va_list *va, t_struct *t_s);
void	ft_pf_char(unsigned char c, t_struct *t_s);
void	ft_pf_string(va_list *va, t_struct *t_s);
void	ft_pf_int(va_list *va, t_struct *t_s);
void	ft_pf_uns_int(va_list *va, t_struct *t_s);
void	ft_pf_x(va_list *va, t_struct *t_s);
void	ft_pf_pointer(va_list *va, t_struct *t_s);

#endif
