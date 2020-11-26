/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_syntax.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 17:49:54 by tmatis            #+#    #+#             */
/*   Updated: 2020/11/26 10:11:17 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"
#include <stdarg.h>

void		ft_test_parseflags(void)
{
	t_syntax		s;
	const	char	*format = "#+worked";

	s = ft_syntaxinit();
	ft_assert_cmp(s.precision, -1, "We check that the precision is set to -1");
	s = ft_parseflags((char **)&format, s);
	ft_assert_strcmp((char *)format, "worked", 
			"Check that the pointer is going after flag");
	ft_assert_cmp(s.hash, true, "Check that hash is true");
	ft_assert_cmp(s.plus, true, "Check that plus is true");
	ft_assert_cmp(s.align_left, false, "Check that align_left is false");
}

t_syntax	ft_parse_util(char *format, ...)
{
	t_syntax	syntax;

	va_list		va;
	va_start(va, format);
	syntax = ft_parsesyntax(&format, va);
	va_end(va);
	ft_assert_cmp(*(format), 0, "should reach the \\0");
	return (syntax);
}

void	ft_test_parsesyntax(void)
{
	t_syntax		syntax;
	
	syntax = ft_parse_util("%");
	ft_assert_cmp(syntax.type, -1, "Should be -1 if null");
	syntax = ft_parse_util("%llc");
	ft_assert_cmp(syntax.length, ll, "Should be ll");
	ft_assert_cmp(syntax.type, 0, "Should be c so index 0");
	syntax = ft_parse_util("%#+*.*llp", 10, 15);
	ft_assert_cmp(syntax.hash, true, "check if hash is detected");
	ft_assert_cmp(syntax.plus, true, "check if plus is detected");
	ft_assert_cmp(syntax.width, 10, "check if width is detected");
	ft_assert_cmp(syntax.precision, 15, "check if precision is detected");
	syntax = ft_parse_util("%15.10lp");
	ft_assert_cmp(syntax.width, 15, "check if width is detected");
	ft_assert_cmp(syntax.precision, 10, "check if precision is detected");
	ft_assert_cmp(syntax.length, l, "Should be l");
	ft_assert_cmp(syntax.type, 2, "Should be p");
}

void	ft_test_syntax(void)
{
	ft_test_parseflags();
	ft_test_parsesyntax();
}
