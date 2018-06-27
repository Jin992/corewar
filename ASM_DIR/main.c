/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 13:40:52 by mminenko          #+#    #+#             */
/*   Updated: 2018/04/22 13:40:53 by mminenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void				file_cr(unsigned char *ins, char *av, t_header *a, int len)
{
	unsigned char	ops[8];
	int				fd2;
	char			*path;
	int				size;
	int				plus;

	av[ft_strlen(av) - 1] = '\0';
	path = ft_strjoin(av, "cor");
	fd2 = open(path, O_WRONLY | O_CREAT, 0600);
	plus = 0;
	ft_bzero((void*)ops, 8);
	if ((PROG_NAME_LENGTH + 1) % 4 != 0)
		plus += 4 - (PROG_NAME_LENGTH + 1) % 4;
	if ((COMMENT_LENGTH + 1) % 4 != 0)
		plus += 4 - (COMMENT_LENGTH + 1) % 4;
	size = sizeof(a->magic) + sizeof(a->prog_size) +
		(COMMENT_LENGTH + 1) + (PROG_NAME_LENGTH + 1);
	write(fd2, a, size);
	write(fd2, ops, plus);
	write(fd2, ins, len);
	ft_printf("Writing output program to %s\n", path);
	free(path);
	free(ins);
	close(fd2);
}

void				cont_main(t_header *a, t_valid *valid, int fd1, char *ar)
{
	t_code			*code;
	t_data			*data;
	t_labels		*labels_list;
	unsigned char	*instruction;
	int				len;

	len = 0;
	code = NULL;
	data = create_data(fd1, 1, -1);
	labels_list = NULL;
	ft_build_valid(valid);
	parsing_data(data, valid);
	read_name(data, a);
	read_comment(data, a);
	code = exec_code(data, code, &labels_list, 0);
	instruction = conv_bytes(code, a, labels_list);
	len = conv_ins(code, instruction, labels_list);
	file_cr(instruction, ar, a, len);
	close(fd1);
	ft_struct_free(code);
	ft_data_labels_free(data, labels_list);
}

int					main(int argc, char **argv)
{
	t_header		asmus;
	t_valid			valid;
	int				fd1;

	if (argc < 2)
	{
		ft_printf("Usage: ./asm <sourcefile.s>\n");
		return (0);
	}
	ft_bzero((void*)asmus.prog_name, PROG_NAME_LENGTH + 1);
	ft_bzero((void*)asmus.comment, COMMENT_LENGTH + 1);
	if ((fd1 = open(argv[1], O_RDONLY)) < 0)
	{
		ft_printf("Can't read source file %s\n", argv[1]);
		return (0);
	}
	cont_main(&asmus, &valid, fd1, argv[1]);
	return (0);
}
