/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 00:02:37 by ynenakho          #+#    #+#             */
/*   Updated: 2017/12/02 23:08:59 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_width_str(t_arg *arg)
{
	int		num;
	char	*str;

	if (arg->precision != -1 && arg->precision < arg->l)
		num = arg->width - arg->precision;
	else if (arg->precision == -1)
		num = arg->width;
	else
		num = arg->width - arg->l;
	num = (num < 0) ? 0 : num;
	str = ft_strnew(num);
	ft_memset(str, ' ', num);
	return (str);
}

char	*get_precision_str(t_arg *arg)
{
	char	*str;

	if (arg->precision != -1 && arg->precision < arg->l)
		str = ft_strsub(arg->val.str, 0, arg->precision);
	else if (arg->precision == 0)
		str = ft_strdup("");
	else
		str = ft_strsub(arg->val.str, 0, arg->l);
	return (str);
}

char	*ft_handle_str(t_arg *arg, va_list *ap)
{
	char	*result;
	char	*width;
//	char	*tmp;

	arg->str = va_arg(*ap, char*);
	if (arg->str == NULL)
		arg->str = ft_strdup("(null)");
	arg->l = ft_strlen(arg->str);
	if (arg->precision < arg->l && arg->precision != -1)
	{
	//	tmp = arg->str;
		arg->str = ft_strsub(arg->str, 0, arg->precision);
		arg->l = ft_strlen(arg->str);
	//	ft_strdel(&tmp);
	}
		if (arg->width > arg->l)
	{
		width = ft_strnew(arg->width - arg->l);
		ft_memset(width, ' ', arg->width - arg->l);
	}
		else
			width = ft_strnew(0);
	if (arg->flag.left_j)
		result = ft_strjoin(arg->str, width);
	else
		result = ft_strjoin(width, arg->str);
//	ft_strdel(&arg->str);
	ft_strdel(&width);
	return(result);
}
