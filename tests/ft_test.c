/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:52:58 by tmatis            #+#    #+#             */
/*   Updated: 2020/11/28 16:11:46 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"
#include <stdio.h>

int		main(void)
{
	int		result1;
	int		result2;

	ft_putstr_fd("---   [BEGIN TEST BUFFER]   ---\n\n", 1);
	ft_test_buffer();
	ft_putstr_fd("---   [BEGIN TEST SYNTAX]   ---\n\n", 1);
	ft_test_syntax();
	ft_putstr_fd("---   [BEGIN MANUAL TEST]   ---\n\n", 1);
	result1 = ft_printf("%10.10c\n", 200);
	result2 = printf("%10lc\n", 200);
	printf("%i\n", result1);
	printf("%i\n", result2);
}
