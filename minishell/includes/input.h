/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 16:03:50 by lniehues          #+#    #+#             */
/*   Updated: 2021/10/17 16:58:46 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "minishell.h"

char	*create_prompt(void);
void	read_input_and_save_history(char **input);
void	read_input(char *prompt, char **input);

#endif
