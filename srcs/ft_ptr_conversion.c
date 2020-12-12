/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 17:01:22 by tmatis            #+#    #+#             */
/*   Updated: 2020/12/12 13:31:01 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_ptr_def(t_syntax syntax, t_buffer *buffer, va_list va)
{
	syntax.hash = true;
	syntax.type = 6;
	return (ft_uhex_conv(syntax, buffer, va_arg(va, unsigned long), false));
}
