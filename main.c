/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 18:42:41 by kazuki            #+#    #+#             */
/*   Updated: 2022/12/28 11:55:21 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

void shell_loop()
{
	char	*command_line;
	char	**tok_seq;
	int		delim_num;
	int		tok_pos;
	
	delim_num = 0;
	while(1)
    {
		tok_pos = 0;
        command_line = readline("--> ");
        tok_seq = tokenizer(command_line);
		//printf("tok seq is like ... %s\n", tok_seq[0]);
		//printf("tok seq is like ... %s\n", tok_seq[1]);
		while (tok_seq[delim_num] != NULL)
			delim_num++;
		//printf("delim num is ... %d\n", delim_num);
		while (tok_seq[tok_pos] != NULL)
		{
			execute(tok_seq, &tok_pos, delim_num);
		}
    }
}

int main()
{
	shell_loop();
    return (0);
}
