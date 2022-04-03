/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parser_split.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:41:52 by kipark            #+#    #+#             */
/*   Updated: 2022/04/03 15:36:49 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void str_free(char **str, int index)
{
	int i;

	i = 0;
	while (i < index)
	{
		free(str[i]);
		++i;
	}
	free(str);
}

static int get_delimiter_s_length(char const *s, char c)
{
	int i;
	int s_length;

	i = 0;
	s_length = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (s_length);
		else
		{
			++s_length;
			++i;
		}
	}
	return (s_length);
}

static int get_delimiter_size(char const *s, char c)
{
	int i;
	int s_length;
	int delimiter_size;

	i = 0;
	s_length = 0;
	delimiter_size = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			if (s_length != 0)
				++delimiter_size;
			s_length = 0;
			++i;
		}
		else
		{
			++s_length;
			++i;
		}
	}
	if (s_length != 0)
		++delimiter_size;
	return (delimiter_size);
}

static void set_str_charter(char const *s, char *str, int s_length)
{
	int i;

	i = 0;
	while (i < s_length)
	{
		str[i] = s[i];
		++i;
	}
	str[i] = '\0';
}

char **push_swap_parser_split(char const *s, char c)
{
	char **str;
	int i;
	int dmt_size;

	i = 0;
	dmt_size = get_delimiter_size(s, c);
	str = malloc(sizeof(char *) * (dmt_size + 1));
	if (str == 0)
		return (0);
	while (i < dmt_size)
	{
		while (*s == c)
			++s;
		str[i] = malloc(sizeof(char) * (get_delimiter_s_length(s, c) + 1));
		if (str[i] == 0)
			str_free(str, i - 1);
		if (str[i] == 0)
			return (0);
		set_str_charter(s, str[i], get_delimiter_s_length(s, c));
		s = s + get_delimiter_s_length(s, c) + 1;
		++i;
	}
	str[dmt_size] = NULL;
	return (str);
}