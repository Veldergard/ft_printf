/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaurine <olaurine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 19:56:51 by olaurine          #+#    #+#             */
/*   Updated: 2020/07/27 15:43:19 by olaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main (void)
{
	int a = 19;
	int b = 14;
	char c = 'a';
	int d = 2147483647;
	int e = -2147483648;
	int f = 42;
	int g = 25;
	int h = 4200;
	int i = 8;
	int j = -12;
	int k = 123456789;
	int l = 0;
	int m = -12345678;
	char *n = "abcdefghijklmnop";
	char *o = "-a";
	char *p = "-12";
	char *q = "0";
	char *r = "%%";
	char *s = "-2147483648";
	char *t = "0x12345678";
	char *u = "-0";

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
	a = 3;
	b = 3;
	ft_printf(" —- Return : %d\n", ft_printf("%*.*i", a, b, i));
	printf(" —- Return : %d\n", printf("%*.*i", a, b, i));
	ft_printf(" —- Return : %d\n", ft_printf("%*.*d", a, b, j));
	printf(" —- Return : %d\n", printf("%*.*d", a, b, j));
	ft_printf(" —- Return : %d\n", ft_printf("%*.*d", a, b, k));
	printf(" —- Return : %d\n", printf("%*.*d", a, b, k));
	ft_printf(" —- Return : %d\n", ft_printf("%*.*d", a, b, l));
	printf(" —- Return : %d\n", printf("%*.*d", a, b, l));
	ft_printf(" —- Return : %d\n", ft_printf("%*.*d", a, b, m));
	printf(" —- Return : %d\n", printf("%*.*d", a, b, m));
	ft_printf(" —- Return : %d\n", ft_printf("%*.*d", a, b, c));
	printf(" —- Return : %d\n", printf("%*.*d", a, b, c));
	ft_printf(" —- Return : %d\n", ft_printf("%*.*d", a, b, e));
	printf(" —- Return : %d\n", printf("%*.*d", a, b, e));
	ft_printf(" —- Return : %d\n", ft_printf("%*.*d", a, b, d));
	printf(" —- Return : %d\n", printf("%*.*d", a, b, d));
	return (0);
}
