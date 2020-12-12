/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:24:22 by tmatis            #+#    #+#             */
/*   Updated: 2020/12/09 17:50:32 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_uint_def(t_syntax syntax, t_buffer *buffer, va_list va)
{
	return (ft_uint_conv(syntax, buffer, va_arg(va, unsigned int)));
}

int		ft_uint_hh(t_syntax syntax, t_buffer *buffer, va_list va)
{
	return (ft_uint_conv(syntax, buffer, (char)va_arg(va, int)));
}

int		ft_uint_h(t_syntax syntax, t_buffer *buffer, va_list va)
{
	return (ft_uint_conv(syntax, buffer, (short)va_arg(va, int)));
}

int		ft_uint_l(t_syntax syntax, t_buffer *buffer, va_list va)
{
	return (ft_uint_conv(syntax, buffer, va_arg(va, long)));
}

int		ft_uint_ll(t_syntax syntax, t_buffer *buffer, va_list va)
{
	return (ft_uint_conv(syntax, buffer, va_arg(va, long long)));
}
