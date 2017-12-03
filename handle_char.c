/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 16:04:59 by ynenakho          #+#    #+#             */
/*   Updated: 2017/12/02 21:50:43 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_get_width(t_arg *arg)
{
	char *width;

	if (arg->width > 1)
	{
		width = ft_strnew(arg->width - 1);
		ft_memset(width, ' ', arg->width - 1);
	}
	else
		width = ft_strnew(0);
	return (width);
}

char		*ft_handle_char(t_arg *arg, va_list *ap)
{
	char *result;
	char *width;

	if (arg->sp == '%')
		arg->val.chr = '%';
	else
		arg->val.chr = (unsigned char)va_arg(*ap, int);
	width = ft_get_width(arg);
	if (arg->flag.left_j)
		result = ft_strmjoin(2, &arg->val.chr, width);
	else
		result = ft_strmjoin(2, width, &arg->val.chr);
	if (arg->val.chr == '\0')
		arg->l = ft_strlen(result) + 1;
	else
		arg->l = ft_strlen(result);
	ft_strdel(&width);
	return (result);
}
