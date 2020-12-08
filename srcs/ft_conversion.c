/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 23:46:31 by tmatis            #+#    #+#             */
/*   Updated: 2020/12/08 23:46:49 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_int_conv(t_syntax syntax, t_buffer *buffer, long long i)
{
	char			buff[BUFFER_SIZE];
	int				numlen;
	const	char	pretends[2] = " 0";
	int				index;

	index = 0;
	numlen = ft_buffnbr_signed(i, "0123456789", syntax, buff);
	if (!syntax.align_left && syntax.zero && syntax.precision == -1 && ft_issign(buff[0]))
	{
		ft_buff_fill(buffer, buff[0], 1);
		index = 1;
	}
	if (!syntax.align_left && syntax.width)
		ft_buff_fill(buffer, pretends[syntax.zero && syntax.precision == -1], syntax.width-numlen);
	ft_buffcat(buffer, &buff[index], numlen-index);
	if (syntax.align_left && syntax.width)
		ft_buff_fill(buffer, ' ', syntax.width-numlen);
	if (syntax.width > numlen)
		return (syntax.width);
	else
		return (numlen);
}

