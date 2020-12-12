/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 14:36:22 by tmatis            #+#    #+#             */
/*   Updated: 2020/12/09 17:36:25 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_doconversion(t_syntax syntax, t_buffer *buffer, va_list va)
{
	int		result;

	result = 0;
	if (syntax.type == -1)
		return (-1);
	if (syntax.length == def)
		result = ft_def_conversion(syntax, buffer, va);
	else if (syntax.length == l)
		result = ft_l_conversion(syntax, buffer, va);
	else if (syntax.length == ll)
		result = ft_ll_conversion(syntax, buffer, va);
	else if (syntax.length == h)
		result = ft_h_conversion(syntax, buffer, va);
	else if (syntax.length == hh)
		result = ft_hh_conversion(syntax, buffer, va);
	return (result);
}

int		ft_printf(const char *format, ...)
{
	t_buffer	buffer;
	va_list		va;
	int			count;

	va_start(va, format);
	count = 0;
	buffer = ft_buffinit(); 
	while (*format)
	{
		if (*format == '%')
			count += ft_doconversion(ft_parsesyntax(&format, va), &buffer, va);
		else
		{
			ft_buffcat(&buffer, format, 1);
			count++;
			format++;
		}
	}
	va_end(va);
	ft_buffflush(&buffer);
	return (count);
}
