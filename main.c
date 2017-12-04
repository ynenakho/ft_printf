/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 22:58:33 by ynenakho          #+#    #+#             */
/*   Updated: 2017/12/03 19:13:15 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main()
{
	printf("%S\n", (wchar_t *)NULL);
	ft_printf("%S\n", (wchar_t *)NULL);
	NEW_LINE;
	printf("%d\n",printf("{%-15Z}", 123));
	printf("%d\n",ft_printf("{%-15Z}", 123));
	return (0);
}
