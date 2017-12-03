/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 16:00:06 by ynenakho          #+#    #+#             */
/*   Updated: 2017/12/02 23:43:15 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *fmt, ...)
{
	va_list ap;
	int		result;
	t_arg	*flags;

	result = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			flags = create_struct(&fmt, &ap);
			result += ft_algo(flags, &ap);
		}
		else
		{
			ft_putchar(*fmt);
			result++;
			fmt++;
		}
	}
	va_end(ap);
//	del_structs(arg);
	return (result);
}

t_arg	*create_struct(char **fmt, va_list *ap)
{
	t_arg *arg;

	arg = (t_arg *)malloc(sizeof(t_arg));
	arg->width = 0;
	arg->precision = -1;
	arg->length = ft_strnew(0);
	arg->l = 0;
	ft_parse_flag(fmt, arg);
	ft_parse_width(fmt, arg, ap);
	ft_parse_precision(fmt, arg, ap);
	ft_parse_length(fmt, arg);
	ft_parse_sp(fmt, arg);
	return (arg);
}

void	del_structs(t_arg *arg)
{

	/* if (arg->length) */
	 	ft_strdel(&arg->length); 
//	 if (arg->str) 
//	 	ft_strdel(&arg->str); 
	//	if (arg->sign) 
//	 	ft_strdel(&arg->sign); 
// if (arg->val.str) 
	 //	ft_strdel(&arg->val.str); 
	/* if (arg->val.ptr) */
	/* 	ft_memdel(&arg->val.ptr); */
	ft_memdel((void**)&arg);
}
