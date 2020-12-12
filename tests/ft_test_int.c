/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 16:05:06 by tmatis            #+#    #+#             */
/*   Updated: 2020/12/09 17:38:11 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

static	void	ft_test_uint(void)
{
	int			result;
	t_buffer	buffer;

	buffer = ft_buffinit();
	result = ft_printf_no_flush("%u%c", &buffer, 42, '\0');
	ft_assert_strcmp(buffer.content, "42", "Test if %i work");
	ft_assert_cmp(result, 3, "should return 3");
	ft_flush_nowrite(&buffer);
}

void			ft_test_int(void)
{
	int			result;
	t_buffer	buffer;

	buffer = ft_buffinit();
	result = ft_printf_no_flush("%i%c", &buffer, 42, '\0');
	ft_assert_strcmp(buffer.content, "42", "Test if %i work");
	ft_assert_cmp(result, 3, "should return 3");
	ft_flush_nowrite(&buffer);
	result = ft_printf_no_flush("%i%c", &buffer, -42, '\0');
	ft_assert_strcmp(buffer.content, "-42", "Test if %i work");
	ft_assert_cmp(result, 4, "should return 4");
	ft_flush_nowrite(&buffer);
	result = ft_printf_no_flush("%i%c", &buffer, 0, '\0');
	ft_assert_strcmp(buffer.content, "0", "Test if %i work");
	ft_assert_cmp(result, 2, "should return 2");
	ft_flush_nowrite(&buffer);
	result = ft_printf_no_flush("%04i%c", &buffer, -4825, '\0');
	ft_assert_strcmp(buffer.content, "-4825", "Test if %i work");
	ft_assert_cmp(result, 6, "should return 2");
	ft_flush_nowrite(&buffer);
	ft_test_uint();
}
