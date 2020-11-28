/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 14:36:22 by tmatis            #+#    #+#             */
/*   Updated: 2020/11/28 15:58:54 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_doconversion(t_syntax syntax, t_buffer *buffer, va_list va)
{
	int		result;
	
	result = 0;
	if (syntax.length == def)
		result = ft_def_conversion(syntax, buffer, va);
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
