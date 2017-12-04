/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 20:50:24 by ynenakho          #+#    #+#             */
/*   Updated: 2017/12/03 20:53:52 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int ft_algo(t_arg *arg, va_list *ap)
{
	char	*value;
	t_func	f;
	int		res;

	f = get_func(arg->sp);
	if (f)
		value = f(arg, ap);
	else if (arg->width != 0)
	{
		arg->l = arg->width;
		value = ft_strnew(arg->width);
		ft_memset(value, ' ', arg->width);
		if (arg->flag.left_j)
			ft_memset(value, arg->sp, 1);
		else
			ft_memset(value + arg->width - 1, arg->sp, 1);
	}
	/* else if (arg->sp == '\0') */
	/* { */
	/* 	arg->l = 0; */
	/* 	value = ft_strnew(0); */
	/* } */
	else
	{
		arg->l = 1;
		value = ft_strnew(1);
		ft_memset(value, arg->sp, 1);
	}
	res = write(1, value, arg->l);
	ft_memdel((void **)&value);
	del_structs(arg);
	return (res);

	/* int ret; */
	/* char *res; */

	/* res = ft_strnew(0); */
	/* ret = 0; */
	/* if (arg->sp == 'c' || arg->sp == '%' || arg->sp == 'C') */
	/* 	res = ft_handle_char(arg, ap); */
	/* else if (arg->sp == 'o' || arg->sp == 'O') */
	/* 	res = ft_handle_octal(arg, ap); */
	/* else if (arg->sp == 'S') */
	/* 	res = ft_handle_wstr(arg, ap); */
	/* //	else if (arg->sp == 'C') */
	/* //		res = ft_handle_wchar(arg, ap); */
	/* else if (arg->sp == 'X' || arg->sp == 'x') */
	/* 	res = ft_handle_hex(arg, ap); */
	/* else if (arg->sp == 's') */
	/* 	res = ft_handle_str(arg, ap); */
	/* else if (arg->sp == 'd' || arg->sp == 'i' || arg->sp == 'D') */
	/* 	res = ft_handle_int(arg, ap); */
	/* else if (arg->sp == 'u' || arg->sp == 'U') */
	/* 	res = ft_handle_uint(arg, ap); */
	/* else if (arg->sp == 'p') */
	/* 	res = ft_handle_addr(arg, ap); */
	/* if (arg->sp == 'c' || arg->sp == 'C' || arg->sp == 'S') */
	/* { */
	/* 	write(1, res, arg->l); */
	/* 	ret += arg->l; */
	/* } */
	/* else */
	/* { */
	/* 	ret += ft_strlen(res); */
	/* 	ft_putstr(res); */
	/* } */
	/* ft_strdel(&res); */
	/* del_structs(arg); */
	/* return (ret); */
}

static void	init_funcs(t_func *funcs)
{
	funcs['x'] = &ft_handle_hex;
	funcs['X'] = &ft_handle_hex;
	funcs['s'] = &ft_handle_str;
	funcs['S'] = &ft_handle_wstr;
	funcs['i'] = &ft_handle_int;
	funcs['d'] = &ft_handle_int;
	funcs['D'] = &ft_handle_int;
	funcs['o'] = &ft_handle_octal;
	funcs['O'] = &ft_handle_octal;
	funcs['%'] = &ft_handle_char;
	funcs['c'] = &ft_handle_char;
	funcs['C'] = &ft_handle_wchar;
	funcs['p'] = &ft_handle_addr;
	//	funcs['b'] = &ft_handle_mybinary;
	funcs['U'] = &ft_handle_uint;
	funcs['u'] = &ft_handle_uint;
}

t_func	get_func(char c)
{
	static t_func	*funcs;

	if (!funcs)
	{
		funcs = ft_memalloc(sizeof(*funcs) * 256);
		if (funcs)
			init_funcs(funcs);
	}
	return (funcs[(int)c]);
}
