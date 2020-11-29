/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 16:59:31 by tmatis            #+#    #+#             */
/*   Updated: 2020/11/28 17:57:33 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

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
}
