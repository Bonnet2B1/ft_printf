/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress_pf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:30:30 by edelarbr          #+#    #+#             */
/*   Updated: 2023/03/06 15:00:24 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putadressfunction_pf(unsigned long long n, int *ret)
{
	if (n < 16)
	{
		if (ft_putchar_pf("0123456789abcdef"[n]) < 0)
			return (-2147483648);
		*ret += 1;
	}
	else
	{
		if (ft_putadressfunction_pf(n / 16, ret) < 0)
			return (-2147483648);
		if (ft_putadressfunction_pf(n % 16, ret) < 0)
			return (-2147483648);
	}
	return (0);
}

int	ft_putadress_pf(unsigned long long n)
{
	int ret;

	ret = 0;
	if (ft_putadressfunction_pf(n, &ret) < 0)
		return (-2147483648);
	return (ret);
}