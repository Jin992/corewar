/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 13:13:23 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/05/09 13:13:25 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H
# include "../includes/vm.h"

int		is_int(char *str);
int		parse_dump(t_vm *vm, char **argv, int i);
int		parse_e_flag(t_vm *vm, char **argv, int i);
int		find_empty_slot(t_vm *vm);
int		find_empty_slot_in_number(t_vm *vm, int slot);

#endif
