/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 15:10:34 by ynenakho          #+#    #+#             */
/*   Updated: 2017/12/03 17:40:47 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char *ft_get_precision(t_arg *arg)
{
	char *precision;


	if (arg->precision > (int)ft_strlen(arg->str))
	{
		precision = ft_strnew(arg->precision - ft_strlen(arg->str));
		ft_memset(precision, '0', arg->precision - ft_strlen(arg->str));
	}
	else
		precision = ft_strnew(0);
	return (precision);
}

static char	*ft_get_width(t_arg *arg)
{
	char *width;
	int	 x;

	x = (arg->flag.hash) ? 2 : 0 ;
	width = ft_strnew(0);
	if (arg->precision == -1 && (arg->width > (int)ft_strlen(arg->str) + x) && arg->flag.zero && !(arg->flag.left_j))
	{
		width = ft_strnew(arg->width - ft_strlen(arg->str) - x);
		ft_memset(width, '0', arg->width - ft_strlen(arg->str) - x);
	}
	else if (arg->width > arg->precision && arg->precision > (int)ft_strlen(arg->str) + x)
	{
		width = ft_strnew(arg->width - arg->precision);
		ft_memset(width, ' ', arg->width - arg->precision);
	}

	else if (arg->width > ((int)ft_strlen(arg->str) + x))
	{
		width = ft_strnew(arg->width - ft_strlen(arg->str) - x);
		ft_memset(width, ' ', arg->width - ft_strlen(arg->str) - x);
	}
	return (width);
}

static void	ft_xtocapital(t_arg *arg)
{
	char *tmp;
	
		tmp = arg->str;
		while (*tmp)
		{
			if (ft_isalpha(*tmp))
				*tmp = ft_toupper(*tmp);
			tmp++;
		}

}

char	*ft_handle_hex(t_arg *arg, va_list *ap)
{
	char *result;
	char *precision;
	char *width;
	char *hash;

	convert_u(arg, ap);
	hash = ((arg->flag.hash) && arg->val.uintm != 0) ? ft_strdup("0x") : ft_strnew(0);
	arg->str = ((arg->precision == 0) && (arg->val.uintm == 0)) ? ft_strnew(0) : ft_hex(arg->val.uintm);
	precision = ft_get_precision(arg);
	width = ft_get_width(arg);
	if (arg->precision != -1)
		arg->str = ft_strmjoin(3, hash, precision, arg->str);
	else if (*width == '0')
		arg->str = ft_strmjoin(3, hash, width, arg->str); 
	else 
		arg->str = ft_strjoin(hash, arg->str);
	if (arg->sp == 'X')
		ft_xtocapital(arg);
	if (arg->flag.left_j && *width == ' ' && (arg->width > (int)ft_strlen(arg->str)))
		result = ft_strmjoin(2, arg->str, width);
	else if (*width == ' ' && !(arg->flag.left_j) && arg->width > (int)ft_strlen(arg->str))
		result = ft_strmjoin(2, width, arg->str);
	else
		result = arg->str;
	arg->l = ft_strlen(result);
	ft_strdel(&width);
	ft_strdel(&hash);
	ft_strdel(&precision);
	return (result);
}
