/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:53:33 by tmatis            #+#    #+#             */
/*   Updated: 2021/01/08 14:30:32 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assert.h"

t_tests	ft_init_tester(char name[256], int log_level)
{
	t_tests	tester;

	ft_strcpy(tester.name, name);
	tester.tests_success = 0;
	tester.tests_failed = 0;
	tester.log_level = log_level;
	return (tester);
}

void	ft_tests_header(t_tests *tests)
{
	ft_putstr_fd("\033[0m", 1);
	ft_putstr_fd("╔╦╦═╦╦══╦══╗╔══╦═╦══╦══╗\n", 1);
	ft_putstr_fd("║║║║║╠║║╩╗╔╝╚╗╔╣╦╣══╬╗╔╝\n", 1);
	ft_putstr_fd("║║║║║╠║║╗║║  ║║║╩╬══║║║ \n", 1);
	ft_putstr_fd("╚═╩╩═╩══╝╚╝  ╚╝╚═╩══╝╚╝ \n", 1);
	ft_putstr_fd("\n Name: ", 1);
	ft_putstr_fd(tests->name, 1);
	ft_putstr_fd("\n Log level: ", 1);
	ft_putnbr_fd(tests->log_level, 1);
	ft_putstr_fd("\033[0m\n\n", 1);
}

void	ft_tests_result(t_tests *tests)
{
	ft_putstr_fd("---- [RESULTS] ----\n\n", 1);
	if (tests->tests_failed > 0)
		ft_putstr_fd("\033[1;31m", 1);
	else
		ft_putstr_fd("\033[1;32m", 1);
	ft_putnbr_fd(tests->tests_success, 1);
	ft_putstr_fd("/", 1);
	ft_putnbr_fd(tests->tests_success + tests->tests_failed, 1);
	ft_putstr_fd("\033[0m\n", 1);
}
