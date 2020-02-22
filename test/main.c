/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 17:08:02 by fjessi            #+#    #+#             */
/*   Updated: 2020/02/22 13:43:21 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include "float.h"

int		main(void)
{
	ft_printf("%-6d\n",5);
	ft_printf("%-6d\n",15);
	ft_printf("%-6d\n",125);
	ft_printf("%s\n","sveta");
	ft_printf("%c\n",'c');
	ft_printf("%o\n",23);
	ft_printf("%#X\n",77);
	
	ft_printf("%S\n", "hello world");
	ft_printf("{red}%s\n","hello world");
	ft_printf("%b\n", 10);
	ft_printf("%k\n",20200217);
    ft_printf("{red}%s{yellow}%s{green}%s{aquamarine}%s{blue}%s{purple}%s\n","You ", "are ", "well ", "done, ", "125/125 ", "!!!");
	ft_printf("{red}%s{yellow}%s{green}%s{aquamarine}%s{blue}%s{purple}%s\n","You ", "are ", "well ", "done, ", "125/125 ", "!!!");
	ft_printf("{red}%s{yellow}%s{green}%s{aquamarine}%s{blue}%s{purple}%s\n","You ", "are ", "well ", "done, ", "125/125 ", "!!!");
	ft_printf("{red}%s{yellow}%s{green}%s{aquamarine}%s{blue}%s{purple}%s\n","You ", "are ", "well ", "done, ", "125/125 ", "!!!");
	ft_printf("{red}%s{yellow}%s{green}%s{aquamarine}%s{blue}%s{purple}%s\n","You ", "are ", "well ", "done, ", "125/125 ", "!!!");
	ft_printf("{red}%s{yellow}%s{green}%s{aquamarine}%s{blue}%s{purple}%s\n","You ", "are ", "well ", "done, ", "125/125 ", "!!!");
	ft_printf("{red}%s{yellow}%s{green}%s{aquamarine}%s{blue}%s{purple}%s\n","You ", "are ", "well ", "done, ", "125/125 ", "!!!");
	ft_printf("{red}%s{yellow}%s{green}%s{aquamarine}%s{blue}%s{purple}%s\n","You ", "are ", "well ", "done, ", "125/125 ", "!!!");
	ft_printf("{red}%s{yellow}%s{green}%s{aquamarine}%s{blue}%s{purple}%s\n","You ", "are ", "well ", "done, ", "125/125 ", "!!!");
	ft_printf("{red}%s{yellow}%s{green}%s{aquamarine}%s{blue}%s{purple}%s\n","You ", "are ", "well ", "done, ", "125/125 ", "!!!");
	ft_printf("{red}%s{yellow}%s{green}%s{aquamarine}%s{blue}%s{purple}%s\n","You ", "are ", "well ", "done, ", "125/125 ", "!!!");
	return (0);
}
