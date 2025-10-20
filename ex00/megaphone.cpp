/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 23:20:35 by oait-si-          #+#    #+#             */
/*   Updated: 2025/10/21 00:21:23 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char *av[])
{
       if(ac >= 2)
        {
            for(int j = 1; j < ac; j++)
            {
                std::string word = av[j];
                for(int i = 0; word[i]; i++)
                {
                    word[i] = std::toupper(word[i]);
                    std::cout << word[i];
                } 
                std::cout << " ";
            }
        }
        else 
            std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
        std::cout << '\n';
}


