/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaurine <olaurine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 14:56:39 by olaurine          #+#    #+#             */
/*   Updated: 2020/07/27 21:35:52 by olaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(long long int n, char base,
			char is_up_case, char print_sign)
{
	char	*alpha;

	if (base < 2 || base > 16)
		return ;
	alpha = is_up_case ? "0123456789ABCDEF" : "0123456789abcdef";
	if (n < 0 && print_sign)
		ft_putchar_fd('-', 1);
	n = ft_abs_l(n);
	if (n == 0)
		ft_putchar_fd('0', 1);
	else if (n / base == 0)
		ft_putchar_fd(alpha[n % base], 1);
	else
	{
		ft_putnbr_base(n / base, base, is_up_case, print_sign);
		ft_putchar_fd(alpha[n % base], 1);
	}
}

int		num_len_base(long long int n, char base, int *sign)
{
	int		len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
	{
		n *= -1;
		(*sign)++;
		if (n < 0)
			n -= 1;
	}
	while (n > 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

void	ft_put_uns_nbr_base(size_t n, char base,
			char is_up_case, char print_sign)
{
	char *alpha;

	if (base < 2 || base > 16)
		return ;
	alpha = is_up_case ? "0123456789ABCDEF" : "0123456789abcdef";
	if (n == 0)
		ft_putchar_fd('0', 1);
	else if (n / base == 0)
		ft_putchar_fd(alpha[n % base], 1);
	else
	{
		ft_putnbr_base(n / base, base, is_up_case, print_sign);
		ft_putchar_fd(alpha[n % base], 1);
	}
}

int		uns_num_len_base(size_t n, char base)
{
	int		len;

	if (n == 0)
		return (1);
	len = 0;
	while (n > 0)
	{
		n /= base;
		len++;
	}
	return (len);
}
