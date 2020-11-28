/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_syntax.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 17:49:54 by tmatis            #+#    #+#             */
/*   Updated: 2020/11/26 19:44:58 by tmatis           ###   ########.fr       */
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
	s = ft_parseflags((const char **)&format, s);
	ft_assert_strcmp((char *)format, "worked",
			"Check that the pointer is going after flag");
	ft_assert(s.hash, "Check that hash is true");
	ft_assert(s.plus, "Check that plus is true");
	ft_assert(s.align_left == 0, "Check that align_left is false");
}

t_syntax	ft_parse_util(const char *format, t_bool assert_end, ...)
{
	t_syntax	syntax;
	va_list		va;

	va_start(va, assert_end);
	syntax = ft_parsesyntax(&format, va);
	va_end(va);
	if (assert_end)
		ft_assert_cmp(*(format), 0, "should reach the \\0");
	return (syntax);
}

void		ft_test_commoncase(void)
{
	t_syntax		syntax;

	syntax = ft_parse_util("%llc", true);
	ft_assert_cmp(syntax.length, ll, "Should be ll");
	ft_assert_cmp(syntax.type, 0, "Should be c so index 0");
	syntax = ft_parse_util("%#+*.*llp", true, 10, 15);
	ft_assert(syntax.hash, "check if hash is detected");
	ft_assert_cmp(syntax.plus, true, "check if plus is detected");
	ft_assert_cmp(syntax.width, 10, "check if width is detected");
	ft_assert_cmp(syntax.precision, 15, "check if precision is detected");
	syntax = ft_parse_util("%15.10lp", false);
	ft_assert_cmp(syntax.width, 15, "check if width is detected");
	ft_assert_cmp(syntax.precision, 10, "check if precision is detected");
	ft_assert_cmp(syntax.length, l, "Should be l");
	ft_assert_cmp(syntax.type, 2, "Should be p");
	syntax = ft_parse_util("%c", false);
	ft_assert_cmp(syntax.type, 0, "Should be c");
	ft_assert(syntax.hash == 0, "Hash false");
	ft_assert_cmp(syntax.precision, -1, "Precision be -1");
	ft_assert_cmp(syntax.width, 0, "Width be 0");
	syntax = ft_parse_util("%.c", false);
	ft_assert_cmp(syntax.precision, 0, "should be zero if no atoi");
}

void		ft_test_parseexep(void)
{
	t_syntax		syntax;

	syntax = ft_parse_util("%", true);
	ft_assert_cmp(syntax.type, -1, "c -1 if null");
	syntax = ft_parse_util("%-55&", false);
	ft_assert_cmp(syntax.type, -1, "c -1 if null");
	ft_assert_cmp(syntax.width, 55, "width should 55");
	ft_assert(syntax.align_left, "Should align left");
	syntax = ft_parse_util("%*.*", false, -50, -50);
	ft_assert_cmp(syntax.width, 50, "width should 50");
	ft_assert_cmp(syntax.precision, -1, "precision should -1");
}

void		ft_test_syntax(void)
{
	ft_test_parseflags();
	ft_test_commoncase();
	ft_putstr_fd("---   [BEGIN TEST SYNTAX ERROR]   ---\n\n", 1);
	ft_test_parseexep();
}
