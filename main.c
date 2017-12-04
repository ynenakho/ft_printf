/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 22:58:33 by ynenakho          #+#    #+#             */
/*   Updated: 2017/12/03 00:05:48 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main()
{
	printf("%S\n", (wchar_t *)NULL);
	ft_printf("%S\n", (wchar_t *)NULL);
	NEW_LINE;
	printf("%d\n", printf("{% c}\n", 'a'));
	printf("%d\n", ft_printf("{% c}\n", 'a'));
	return (0);
}
