/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 20:50:24 by ynenakho          #+#    #+#             */
/*   Updated: 2017/12/02 15:38:14 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int ft_algo(t_arg *arg, va_list *ap)
{
	int ret;
	char *res;

	res = ft_strnew(0);
	ret = 0;
	if (arg->sp == 'c' || arg->sp == '%' || arg->sp == 'C')
		res = ft_handle_char(arg, ap);
	else if (arg->sp == 'o' || arg->sp == 'O')
		res = ft_handle_octal(arg, ap);
	else if (arg->sp == 'S')
		res = ft_handle_wstr(arg, ap);
//	else if (arg->sp == 'C')
//		res = ft_handle_wchar(arg, ap);
	else if (arg->sp == 'X' || arg->sp == 'x')
		res = ft_handle_hex(arg, ap);
	else if (arg->sp == 's')
		res = ft_handle_str(arg, ap);
	else if (arg->sp == 'd' || arg->sp == 'i' || arg->sp == 'D')
		res = ft_handle_int(arg, ap);
	else if (arg->sp == 'u' || arg->sp == 'U')
		res = ft_handle_uint(arg, ap);
	else if (arg->sp == 'p')
		res = ft_handle_addr(arg, ap);
	if (arg->sp == 'c' || arg->sp == 'C')
	{
		write(1, res, arg->l);
		ret += arg->l;
	}
	else
	{
		ret += ft_strlen(res);
		ft_putstr(res);
	}
	ft_strdel(&res);
	del_structs(arg);
	return (ret);
}
