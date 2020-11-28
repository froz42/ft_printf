/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_buffer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 17:42:19 by tmatis            #+#    #+#             */
/*   Updated: 2020/11/26 17:03:15 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

void	ft_test_buffer(void)
{
	t_buffer	buffer;

	buffer = ft_buffinit();
	ft_assert_cmp(buffer.size, 0, "Buffer size should be 0");
	ft_buffcat(&buffer, "hello", 6);
	ft_assert_strcmp(buffer.content, "hello",
			"Content should be equal to hello");
	ft_assert_cmp(buffer.size, 6, "Buffer size should be 6");
	ft_buffcat(&buffer, " world", 7);
	ft_assert_cmp(buffer.size, 13, "Buffer size should be 13");
	ft_assert(ft_memcmp(buffer.content, "hello\0 world", 13) == 0,
			"Check if the buffer content == Hello world");
	ft_putstr_fd("The buffer will be flushed: [", 1);
	ft_buffflush(&buffer);
	ft_putstr_fd("]\n\n", 1);
	ft_assert_cmp(buffer.size, 0, "We check that buffer size = 0");
}
