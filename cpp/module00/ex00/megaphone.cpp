/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:14:48 by lniehues          #+#    #+#             */
/*   Updated: 2022/03/13 21:18:57 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void print_str_upperized(const char *str)
{
    std::string outputStr = str;
    for (size_t i = 0; i < outputStr.length(); i++)
    {
        std::cout << (char)std::toupper(outputStr[i]);
    }

    return;
}

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    else
    {
        for (int i = 1; i < argc; i++)
        {
            print_str_upperized(argv[i]);
        }
        std::cout << std::endl;
    }

    return (0);
}
