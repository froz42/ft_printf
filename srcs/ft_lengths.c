/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lengths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:52:43 by tmatis            #+#    #+#             */
/*   Updated: 2020/12/03 22:49:24 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_def_conversion(t_syntax syntax, t_buffer *buffer, va_list va)
{
	int	((*conv[13])(t_syntax syntax, t_buffer *buffer, va_list va));

	conv[0] = &ft_char_def;
	conv[1] = &ft_str_def; 
	return (conv[syntax.type](syntax, buffer, va));
}

int			ft_l_conversion(t_syntax syntax, t_buffer *buffer, va_list va)
{
	int	((*conv[13])(t_syntax syntax, t_buffer *buffer, va_list va));

	conv[0] = &ft_char_l;
	conv[1] = &ft_str_l;
	return (conv[syntax.type](syntax, buffer, va));
}
