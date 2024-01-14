/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhmimchi <rhmimchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:43:40 by rhmimchi          #+#    #+#             */
/*   Updated: 2024/01/12 15:57:09 by rhmimchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static long	int	ft_at(const char *str, long int i, long int num, long int num2)
{
	long int	nega;

	nega = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			nega *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num2 = (num * 10) + (int)(str[i] - 48);
		if ((num > num2) && nega == 1)
			return (-1);
		if ((num > num2) && nega == -1)
			return (0);
		num = num2;
		i++;
	}
	num *= nega;
	return (num);
}

int	ft_atoi(const char *str)
{
	long int	i;
	long int	num;
	long int	num2;

	i = 0;
	num2 = 0;
	num = 0;
	return ((int)ft_at(str, i, num, num2));
}
