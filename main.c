/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaurine <olaurine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 19:56:51 by olaurine          #+#    #+#             */
/*   Updated: 2020/07/21 18:33:45 by olaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main (void)
{
	ft_printf("ft%-24c\n", 'l');
	printf("%-24c\n", 'l');
	fflush(stdout);
	ft_printf("ft%10.2s\n", "lol");
	printf("%10.2s\n", "lol");
	fflush(stdout);
	return (0);
}
