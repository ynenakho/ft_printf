/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:38:30 by ynenakho          #+#    #+#             */
/*   Updated: 2017/12/02 19:44:53 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main()
{
	char *p;

	/* p =ft_strdup("ppp"); */
	/* printf("%O\n", -9223372036854775808); */
	/* ft_printf("%O\n", -9223372036854775808); */
	/* printf("%.5p\n", 0); */
	/* ft_printf("%.5p\n", 0); */
	printf("%S\n", L"@@");
	ft_printf("%S\n", L"@@");
	/* printf("{%*d}\n", -5, 42); */
	/* ft_printf("{%*d}\n", -5, 42); */
	/* printf("{%10R}\n"); */
	/* ft_printf("{%10R}\n"); */
	/* printf("Octal = %o\n", 3456); */
	/* printf("Octal = %O\n", 345634563456); */
	/* printf("Octal = %lo\n", 345634563456); */
	/* printf("Octal = %lO\n", 345634563456); */
	/* printf("%-*.2s Chto za %c  huynya? = %0.01i\n", 12, "str", 'd', -2); */
	/* ft_printf("%-*.2s Chto za %c  huynya? = %0.01i\n", 12, "str", 'd', -2); */

//	ft_putnbr(printf("%6.*s Chto za %c  huynya? = %016i\n", 12, "str", 'd', -2));
//	ft_putchar('\n');
//	ft_putnbr(ft_printf("%6.*s Chto za %c  huynya? = %016i\n", 12, "str", 'd', -2));
//	ft_putchar('\n');

//	printf("%D\n", 3477);
//	ft_printf("%D\n", 3477);




	/* printf("Num of char = |%i|\n", ft_printf("This is int max = |%i| ", INT_MAX)); */
	/* printf("Num of char = |%i|\n", printf("This is int max = |%i| ", INT_MAX)); */
	/* printf("Num of char = |%i|\n", ft_printf("This long max = |%li| ", LONG_MAX)); */
	/* printf("Num of char = |%i|\n", printf("This long max = |%li| ", LONG_MAX)); */



	/* printf("Num of char = |%i|\n", ft_printf("This precision test = |%-020p| ", p)); */
	/* printf("Num of char = |%i|\n", printf("This precision test = |%-020p| ", p)); */
	/* printf("Num of char = |%i|\n", ft_printf("This precision test = |%-20p| ", p)); */
	/* printf("Num of char = |%i|\n", printf("This precision test = |%-20p| ", p)); */

	/* printf("Num of char = |%i|\n", ft_printf("This precision test = |%-10.5i| ", 450)); */
	/* printf("Num of char = |%i|\n", printf("This precision test = |%-10.5i| ", 450)); */
	

	/* printf("Num of char = |%i|\n", ft_printf("This long max = |%li| ", LONG_MAX)); */
	/* printf("Num of char = |%i|\n", printf("This long max = |%li| ", LONG_MAX)); */
	/* printf("%d\n", ft_printf("Hex = %#015ld\n", 678978786789)); */
	/* printf("%d\n", printf("Hex = %#015D\n", 678978786789)); */
	/* NEW_LINE; */
	/* printf("%d\n", ft_printf("Hex = %15.20lo\n", 678978786789)); */
	/* printf("%d\n", printf("Hex = %15.20lo\n", 678978786789)); */
	/* NEW_LINE; */
	/* printf("%d\n", ft_printf("Hex = %#015llO\n", 18446744073709551614)); */
	/* printf("%d\n", printf("Hex = %#015llO\n", 18446744073709551614)); */
	/* NEW_LINE; */
	/* printf("%d\n", ft_printf("Hex = %-#15O\n", 67897878)); */
	/* printf("%d\n", printf("Hex = %-#15O\n", 67897878)); */
	/* NEW_LINE; */
	/* printf("%d\n", ft_printf("Hex = %-15.10O\n", 67897878)); */
	/* printf("%d\n", printf("Hex = %-15.10O\n", 67897878)); */
	/* NEW_LINE; */
	/* printf("%d\n", ft_printf("Hex = %-.15O\n", 67897878)); */
	/* printf("%d\n", printf("Hex = %-.15O\n", 67897878)); */
	/* NEW_LINE; */
	/* printf("%d\n", ft_printf("Char = %-10c\n", 'F')); */
	/* printf("%d\n", printf("Char = %-10c\n", 'F')); */
	/* NEW_LINE; */
	/* printf("%d\n", ft_printf("Char = %10c\n", '$')); */
	/* printf("%d\n", printf("Char = %10c\n", '$')); */

	return (0);
}
