/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 13:50:52 by earteshc          #+#    #+#             */
/*   Updated: 2018/05/12 13:50:53 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/operations.h"

int		check_c_octal_sti(u_int8_t val)
{
	int sum;

	sum = 0;
	if (IS_REG_S(val))
		sum++;
	if (IS_REG_M(val) || IS_DIR_M(val) || IS_IND_M(val))
		sum++;
	if (IS_REG_E(val) || IS_DIR_E(val))
		sum++;
	if (sum != 3)
		return (0);
	return (1);
}

int		check_c_octal_or(u_int8_t val)
{
	int sum;

	sum = 0;
	if (IS_REG_S(val) || IS_DIR_S(val) || IS_IND_S(val))
		sum++;
	if (IS_REG_M(val) || IS_DIR_M(val) || IS_IND_M(val))
		sum++;
	if (IS_REG_E(val))
		sum++;
	if (sum != 3)
		return (0);
	return (1);
}

int		check_c_octal_ldi(u_int8_t val)
{
	int sum;

	sum = 0;
	if (IS_REG_S(val) || IS_DIR_S(val) || IS_IND_S(val))
		sum++;
	if (IS_REG_M(val) || IS_DIR_M(val))
		sum++;
	if (IS_REG_E(val))
		sum++;
	if (sum != 3)
		return (0);
	return (1);
}
