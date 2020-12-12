/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:52:58 by tmatis            #+#    #+#             */
/*   Updated: 2020/12/12 14:37:55 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"
#include <stdio.h>

int		ft_printf_no_flush(const char *format, t_buffer *buffer, ...)
{
	va_list		va;
	int			count;

	va_start(va, buffer);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			count += ft_doconversion(ft_parsesyntax(&format, va), buffer, va);
		else
		{
			ft_buffcat(buffer, format, 1);
			count++;
			format++;
		}
	}
	va_end(va);
	return (count);
}

void		ft_flush_nowrite(t_buffer *buffer)
{
	buffer->size = 0;
}

void		ft_testprintf_basic(void)
{
	t_buffer	buffer;
	int			result;

	buffer = ft_buffinit();
	result = ft_printf_no_flush("", &buffer);
	ft_assert_cmp(result, 0, "Empty string should return 0");
}

int		main(void)
{
	ft_putstr_fd("---   [BEGIN TEST BUFFER]   ---\n\n", 1);
	ft_test_buffer();
	ft_putstr_fd("---   [BEGIN TEST SYNTAX]   ---\n\n", 1);
	ft_test_syntax();
	ft_putstr_fd("---   [BEGIN BASICS TESTS]   ---\n\n", 1);
	ft_testprintf_basic();
	ft_putstr_fd("---   [BEGIN CHARS TESTS]   ---\n\n", 1);
	ft_test_char();
	ft_putstr_fd("---   [BEGIN  STRS TESTS]   ---\n\n", 1);
	ft_test_str();
	ft_putstr_fd("---   [BEGIN  INTS TESTS]   ---\n\n", 1);
	ft_test_int();
	ft_printf("--- MANUAL TEST ---\n");
	ft_printf("|%0*.*p|\n", 15, -6, 0);
}
