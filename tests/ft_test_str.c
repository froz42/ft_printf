/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 21:06:33 by tmatis            #+#    #+#             */
/*   Updated: 2020/12/04 16:08:06 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

void	ft_test_str(void)
{
	int			result;
	t_buffer	buffer;

	buffer = ft_buffinit();
	result = ft_printf_no_flush("%-8.5s%c", &buffer, "hello you", 0);
	ft_assert_strcmp(buffer.content, "hello   ",
			"Test if str insert work");
	ft_assert_cmp(result, 9, "should return 8");
	ft_flush_nowrite(&buffer);
	result = ft_printf_no_flush("|%ls|%c", &buffer, L"🥺🥺🥺🥺🥺", 0);
	ft_assert_strcmp(buffer.content, "|🥺🥺🥺🥺🥺|",
			"Test if wstr insert work");
	ft_assert_cmp(result, 23, "should return 23");
	ft_flush_nowrite(&buffer);
	result = ft_printf_no_flush("|%21.13ls|%c", &buffer, L"🥺🥺🥺🥺🥺", 0);
	ft_assert_strcmp(buffer.content, "|         🥺🥺🥺|",
			"Test if wstr insert work");
	ft_assert_cmp(result, 24, "should return 24");
}
