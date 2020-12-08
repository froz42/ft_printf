/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 16:22:56 by tmatis            #+#    #+#             */
/*   Updated: 2020/12/08 21:27:23 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static	int						ft_numlen_base(int i, int base, int precision)
{
	int		len;

	len = 0;
	while (i)
	{
		len++;
		i /= base;
	}
	if (len == 0 && precision != 0)
		len++;
	return (len);
}

int								ft_buffnbr_unsigned(unsigned long long i,
		char *base, int pre, char *buff)
{
	const	int		base_len = ft_strlen(base);
	const	int		num_len = ft_numlen_base(i, base_len, pre);

	if (num_len > pre)
		pre = num_len;
	buff[pre--] = '\0';
	while (pre)
	{
		buff[pre--] = base[i % base_len];
		i /= base_len;
	}
	return (ft_strlen(buff));
}

static unsigned	long	long	ft_signhandle(long long si, char **buff,
		t_syntax s)
{
	if (si < 0)
	{
		*(*buff)++ = '-';
		return (-si);
	}
	else if (s.plus)
		*(*buff)++ = '+';
	else if (s.space)
		*(*buff)++ = ' ';
	return (si);
}

t_bool							ft_issign(char c)
{
	return (c == '+' || c == ' ' || c == '-');
}

int								ft_buffnbr_signed(long long si, char *base,
		t_syntax s, char *buff)
{
	const	int			base_len = ft_strlen(base);
	int					num_len;
	char				*temp;
	unsigned long long	i;

	temp = buff;
	i = ft_signhandle(si, &buff, s);
	num_len = ft_numlen_base(i, base_len, s.precision);
	if (num_len > s.precision)
		s.precision = num_len;
	buff[s.precision] = '\0';
	while (s.precision--)
	{
		buff[s.precision] = base[i % base_len];
		i /= base_len;
	}
	return (ft_strlen(temp));
}
