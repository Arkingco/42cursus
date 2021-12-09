/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:15:05 by kipark            #+#    #+#             */
/*   Updated: 2021/12/09 19:14:44 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	get_digit_n(long int n)
{
	int	digit;

	digit = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		digit++;
	}
	while (n > 0)
	{
		n = n / 10;
		digit++;
	}
	return (digit);
}

static void	set_itoa(long int n, char **str, int digit)
{
	char	*istr;

	istr = *str;
	if (n >= 10)
		set_itoa(n / 10, str, digit - 1);
	istr[digit] = (n % 10) + '0';
}

char	*ft_itoa(int n)
{
	char		*str;
	int			digit_n;
	long int	temp;

	str = 0;
	temp = (long int)n;
	digit_n = get_digit_n(temp);
	str = malloc(sizeof(char) * (digit_n + 1));
	if (str == 0)
		return (0);
	if (n < 0)
	{
		str[0] = '-';
		set_itoa(-temp, &str, digit_n - 1);
	}
	else
	{
		set_itoa(temp, &str, digit_n - 1);
	}
	str[digit_n] = '\0';
	return (str);
}
