/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 13:16:03 by tmatis            #+#    #+#             */
/*   Updated: 2020/12/03 19:42:11 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_str_def(t_syntax syntax, t_buffer *buffer, va_list va)
{
	const	char	pretends[2] = " 0";
	const	char	*nullstr	= "(null)";
	char			*str;
	int				strlen;

	str = va_arg(va, char *);
	if (!str)
		str = (char *)nullstr;
	if (syntax.precision != -1)
		strlen = ft_strnlen(str, syntax.precision);
	else
		strlen = ft_strlen(str);
	if (!syntax.align_left && syntax.width)
		ft_buff_fill(buffer, pretends[syntax.zero], syntax.width-strlen);
	ft_buffcat(buffer, str, strlen);
	if (syntax.align_left && syntax.width)
		ft_buff_fill(buffer, ' ', syntax.width-strlen);
	if (syntax.width && syntax.width > strlen)
		return (syntax.width);
	else
		return (strlen);
}
