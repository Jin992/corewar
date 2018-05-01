//
// Created by Evgen ARTESHCHUK on 4/23/18.
//
#include "../includes/vm.h"

int	usage()
{
	ft_printf("Usage: ./corewar [-d N -s N -v N | -b --stealth |"
					  " -n --stealth] [-a] <champion1.cor> <...>\n");
	ft_printf("\t-a\t\t: Prints output from \"aff\" (Default is to hide it)\n");
	ft_printf("#### TEXT OUTPUT MODE ###########################"
					  "###############################\n");
	ft_printf("\t-d N\t\t: Dumps memory after N cycles then exits\n");
	ft_printf("\t-s N\t\t: Runs N cycles, dumps memory, pauses, then repeats\n");
	ft_printf("\t-v N\t\t: Verbosity levels, can be added together"
					  " to enable several\n");
	ft_printf("\t\t\t  - 1 : Show only essentials\n");
	ft_printf("\t\t\t  - 2 : Show lives\n");
	ft_printf("\t\t\t  - 3 : Show cycles\n");
	ft_printf("\t\t\t  - 4 : Show operations (Params are NOT litteral ...)\n");
	ft_printf("\t\t\t  - 8 : Show deaths\n");
	ft_printf("\t\t\t  - 16 : Show PC movements (Except for jumps)\n");
	ft_printf("#### BINARY OUTPUT MODE ##########################"
					  "##############################\n");
	ft_printf("\t-b\t  : Binary output mode for corewar.42.fr\n");
	ft_printf("\t--stealth : Hides the real contents of the memory\n");
	ft_printf("#### NCURSES OUTPUT MODE ##########################"
					  "#############################\n");
	ft_printf("\t-n\t  : Ncurses output mode\n");
	ft_printf("\t--stealth : Hides the real contents of the memory\n");
	ft_printf("###################################################"
					  "#############################\n");
	exit(1);
	return (0);
}