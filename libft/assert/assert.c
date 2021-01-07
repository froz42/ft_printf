/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:18:17 by tmatis            #+#    #+#             */
/*   Updated: 2021/01/07 21:30:15 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assert.h"

void	ft_assert(int actual, char *behavior, t_tests *tests)
{
	ft_putstr_fd("\033[0mTEST:", 1);
	if (actual && tests->tests_success++ && tests->log_level >= 2)
		ft_putstr_fd("\033[1;32m [OK]	", 1);
	else if (tests->tests_failed++ && tests->log_level >= 1)
		ft_putstr_fd("\033[1;31m [KO]	", 1);
	ft_putstr_fd("\033[0m", 1);
	if (behavior && (tests->log_level >= 2
			|| (!actual && tests->log_level >= 1)))
		ft_putstr_fd(behavior, 1);
	ft_putstr_fd("\n\n", 1);
}

void	ft_assert_cmp(int actual, int expected, char *behavior, t_tests *tests)
{
	ft_putstr_fd("\033[0mTEST:", 1);
	if (actual == expected && tests->tests_success++ && tests->log_level >= 2)
		ft_putstr_fd("\033[1;32m [OK]", 1);
	else if (tests->tests_failed++ && tests->log_level >= 1)
		ft_putstr_fd("\033[1;31m [KO]", 1);
	if ((tests->log_level >= 4) || (tests->log_level >= 3
				&& actual != expected))
	{
		ft_putstr_fd("\033[0;33m\033[3m	actual: \033[4m", 1);
		ft_putnbr_fd(actual, 1);
		ft_putstr_fd("\033[0m\033[0;33m\033[3m, expected: \033[4m", 1);
		ft_putnbr_fd(expected, 1);
		ft_putstr_fd("\033[0m\n		", 1);
	}
	if (behavior && (tests->log_level >= 2 || ((actual != expected)
				&& tests->log_level >= 1)))
		ft_putstr_fd(behavior, 1);
	ft_putstr_fd("\n\033[0m\n", 1);
}

static	void	ft_putstrun(char *str, int pos)
{
	while (*str)
	{
		if (!pos--)
		{
			ft_putstr_fd("\033[0;31m\033[4m", 1);
			ft_putchar_fd(*str++, 1);
			ft_putstr_fd("\033[0m\033[0;33m\033[3m", 1);
		}
		else
			ft_putchar_fd(*str++, 1);
	}
}

static	void	ft_putdiff(char *actual, char *expected, int indexdiff)
{
	ft_putstrun(actual, indexdiff);
	ft_putstr_fd("\" != \"", 1);
	ft_putstrun(expected, indexdiff);
}

void	ft_assert_strcmp(char *act, char *exp, char *behavior, t_tests *tests)
{
	size_t	i;

	i = 0;
	while (act[i] && act[i] == exp[i])
		i++;
	if (act[i] == exp[i] && tests->tests_success++)
		ft_putstr_fd("\033[0mTEST:\033[1;32m [OK]	\033[0;33m\033[3m\"", 1);
	else if (tests->tests_failed++)
		ft_putstr_fd("\033[0mTEST:\033[1;31m [KO]	\033[0;33m\033[3m\"", 1);
	if (act[i] == exp[i] && tests->log_level >= 4)
	{
		ft_putstr_fd(act, 1);
		ft_putstr_fd("\" == \"", 1);
		ft_putstr_fd(exp, 1);
	}
	else
		ft_putdiff(act, exp, i);
	ft_putstr_fd("\"\033[0m\n		", 1);
	if (behavior)
		ft_putstr_fd(behavior, 1);
	ft_putstr_fd("\n\033[0m\n", 1);
}
