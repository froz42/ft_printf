/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 15:06:57 by tmatis            #+#    #+#             */
/*   Updated: 2020/11/28 15:53:25 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_char_def(t_syntax syntax, t_buffer *buffer, va_list va)
{
	const	char pretends[2] = " 0";

	if (!syntax.align_left && syntax.width)
		ft_buff_fill(buffer, pretends[syntax.zero], syntax.width-1);
	ft_buff_fill(buffer, va_arg(va, int), 1);
	if (syntax.align_left && syntax.width)
		ft_buff_fill(buffer, pretends[syntax.zero], syntax.width-1);
	if (syntax.width)
		return (syntax.width);
	else
		return (1);
}
