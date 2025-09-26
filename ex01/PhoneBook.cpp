/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 00:39:54 by oait-si-          #+#    #+#             */
/*   Updated: 2025/09/26 18:41:23 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

// int main()
// {
//     std::string contacts[8];
    
// }



#include <iostream>

class FirstClass
{
    public:
        FirstClass();
        ~FirstClass();
        void    print(std::string txt);
};

class SecondClass
{
    public:
        SecondClass();
        ~SecondClass();
        void    print(void);
};

int main(void)
{
    SecondClass obj1;
    FirstClass obj2;


    obj2.print("hello world");

    return (0);
}