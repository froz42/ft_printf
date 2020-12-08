/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lengths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:52:43 by tmatis            #+#    #+#             */
/*   Updated: 2020/12/08 23:26:54 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_def_conversion(t_syntax syntax, t_buffer *buffer, va_list va)
{
	int	((*conv[13])(t_syntax syntax, t_buffer *buffer, va_list va));

	conv[0] = &ft_char_def;
	conv[1] = &ft_str_def;
	conv[3] = &ft_int_def;
	conv[4] = &ft_int_def;
	return (conv[syntax.type](syntax, buffer, va));
}

int			ft_l_conversion(t_syntax syntax, t_buffer *buffer, va_list va)
{
	int	((*conv[13])(t_syntax syntax, t_buffer *buffer, va_list va));

	conv[0] = &ft_char_l;
	conv[1] = &ft_str_l;
	conv[3] = &ft_int_l;
	conv[4] = &ft_int_l;

	return (conv[syntax.type](syntax, buffer, va));
}

int			ft_ll_conversion(t_syntax syntax, t_buffer *buffer, va_list va)
{
	int	((*conv[13])(t_syntax syntax, t_buffer *buffer, va_list va));

	conv[0] = &ft_char_l;
	conv[1] = &ft_str_l;
	return (conv[syntax.type](syntax, buffer, va));
}

int			ft_h_conversion(t_syntax syntax, t_buffer *buffer, va_list va)
{
	int	((*conv[13])(t_syntax syntax, t_buffer *buffer, va_list va));

	return (conv[syntax.type](syntax, buffer, va));
}

int			ft_hh_conversion(t_syntax syntax, t_buffer *buffer, va_list va)
{
	int	((*conv[13])(t_syntax syntax, t_buffer *buffer, va_list va));

	conv[3] = &ft_int_hh;
	conv[4] = &ft_int_hh;
	return (conv[syntax.type](syntax, buffer, va));
}
