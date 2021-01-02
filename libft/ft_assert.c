/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:18:17 by tmatis            #+#    #+#             */
/*   Updated: 2020/12/29 20:58:04 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_assert(int actual, char *behavior)
{
	ft_putstr_fd("\033[0mTEST:", 1);
	if (actual)
		ft_putstr_fd("\033[1;32m [✓]	", 1);
	else
		ft_putstr_fd("\033[1;31m [⨯]	", 1);
	ft_putstr_fd("\033[0m", 1);
	if (behavior)
		ft_putstr_fd(behavior, 1);
	ft_putstr_fd("\n\n", 1);
	return (actual);
}

int	ft_assert_cmp(int actual, int expected, char *behavior)
{
	ft_putstr_fd("\033[0mTEST:", 1);
	if (actual == expected)
		ft_putstr_fd("\033[1;32m [✓]", 1);
	else
		ft_putstr_fd("\033[1;31m [⨯]", 1);
	ft_putstr_fd("\033[0;33m\033[3m	actual: \033[4m", 1);
	ft_putnbr_fd(actual, 1);
	ft_putstr_fd("\033[0m\033[0;33m\033[3m, expected: \033[4m", 1);
	ft_putnbr_fd(expected, 1);
	ft_putstr_fd("\033[0m\n		", 1);
	if (behavior)
		ft_putstr_fd(behavior, 1);
	ft_putstr_fd("\n\033[0m\n", 1);
	return (actual == expected);
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

int	ft_assert_strcmp(char *actual, char *expected, char *behavior)
{
	size_t	i;

	i = 0;
	ft_putstr_fd("\033[0mTEST:", 1);
	while (actual[i] && actual[i] == expected[i])
		i++;
	if (actual[i] == expected[i])
	{
		ft_putstr_fd("\033[1;32m [✓]	\033[0;33m\033[3m\"", 1);
		ft_putstr_fd(actual, 1);
		ft_putstr_fd("\" == \"", 1);
		ft_putstr_fd(expected, 1);
	}
	else
	{
		ft_putstr_fd("\033[1;31m [⨯]	\033[0;33m\033[3m\"", 1);
		ft_putstrun(actual, i);
		ft_putstr_fd("\" != \"", 1);
		ft_putstrun(expected, i);
	}
	ft_putstr_fd("\"\033[0m\n		", 1);
	if (behavior)
		ft_putstr_fd(behavior, 1);
	ft_putstr_fd("\n\033[0m\n", 1);
	return (actual[i] == expected[i]);
}
