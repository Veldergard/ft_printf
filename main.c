/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaurine <olaurine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 19:56:51 by olaurine          #+#    #+#             */
/*   Updated: 2020/07/26 16:29:49 by olaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main (void)
{
	ft_printf("%-24c\n", 'l');
	printf("%-24c\n", 'l');
	fflush(stdout);
	ft_printf("%10.2s\n", "lol");
	printf("%10.2s\n", "lol");
	fflush(stdout);
	ft_printf("%0d\n", 15);
	printf("%0d\n", 15);
	fflush(stdout);
	ft_printf("%0.5d\n", 245);
	printf("%0.5d\n", 245);
	fflush(stdout);
	ft_printf("%-0.5d\n", 254);
	printf("%-0.5d\n", 254);
	fflush(stdout);
	ft_printf("%010.5d\n", 12);
	printf("%010.5d\n", 12);
	fflush(stdout);
	ft_printf("%010.5d\n", 17812);
	printf("%010.5d\n", 17812);
	fflush(stdout);
	ft_printf("%010.5d\n", 1241234124);
	printf("%010.5d\n", 1241234124);
	fflush(stdout);
	ft_printf("%05\n");
	printf("%05\n");
	fflush(stdout);
	printf("%5.0p\n", NULL);
	printf("%5.1p\n", NULL);
	printf("%5.2p\n", NULL);
	printf("%0.1p\n", NULL);
	printf("%1.2p\n", NULL);
	printf("%2.p\n", NULL);
	return (0);
}
