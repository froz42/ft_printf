/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 16:59:31 by tmatis            #+#    #+#             */
/*   Updated: 2020/12/02 23:37:20 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"
#include <unistd.h>
#include <stdio.h>

void	ft_test_char(void)
{
	int			result;
	t_buffer	buffer;

	buffer = ft_buffinit();
	result = ft_printf_no_flush("%cello%-5c%5c%c", &buffer, 'h', 100, 'h','\0');
	ft_assert_strcmp(buffer.content, "hellod        h",
			"Test if char insert work");
	ft_assert_cmp(result, 16, "should return 16");
	ft_flush_nowrite(&buffer);
	ft_printf_no_flush("%lc%c", &buffer, 233, 0);
	ft_flush_nowrite(&buffer);
	ft_assert_strcmp(buffer.content, "é", "should be 233");
	ft_printf_no_flush("%lc%lc", &buffer, 0x1F378, 0);
	ft_assert_strcmp(buffer.content, "🍸", "should be drink");
	ft_flush_nowrite(&buffer);
}
