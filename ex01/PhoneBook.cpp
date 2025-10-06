/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 00:39:54 by oait-si-          #+#    #+#             */
/*   Updated: 2025/10/06 10:45:47 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PhoneBook.h"

PhoneBook::PhoneBook() : count(0), nextIndex(0) {}

std::string     truncate(std::string &str)
{
    if(str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void    Contact::display_short(int index)
{
    std::cout << "\n|-------------------------------------------|";
        std::cout <<"\n|" <<std::setw(10) << index << "|"
              << std::setw(10) << truncate(firstName) << "|"
              << std::setw(10) << truncate(lastName) << "|"
              << std::setw(10) << truncate(nickname) << "|";
}
void Contact::display_full()
{
    std::cout << "First name: " << firstName << "\n";
    std::cout << "Last name: " << lastName << "\n";
    std::cout << "Nickname: " << nickname << "\n";
    std::cout << "Phone number: " << phoneNumber << "\n";
    std::cout << "Darkest secret: " << darkestSecret << "\n"; 
}
bool    Contact::is_empty()
{
    return firstName.empty();
}
void    Contact::set_contact()
{
    std::cout << "Enter first name: ";
    std::getline(std::cin, firstName);
    std::cout << "Enter last name: ";
    std::getline(std::cin, lastName);
    std::cout << "Enter nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Enter phone number: ";
    std::getline(std::cin, phoneNumber);
    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, darkestSecret);

    if(firstName.empty() || lastName.empty() || nickname.empty() 
        || phoneNumber.empty() || darkestSecret.empty())
    {
            std::cout << "❌ Contact cannot have empty fields!\n";
        // Reset if invalid
        firstName.clear(); lastName.clear(); nickname.clear();
        phoneNumber.clear(); darkestSecret.clear();        
    }
}
void    PhoneBook::get_infos()
{
    if(count == 0)
    {
        std::cout << "📭 Phonebook is empty!\n";
        return ;
    }
    std::cout << "_____________________________________________\n";
    std::cout <<"|" <<std::setw(10) << "Index" << "|"
                << std::setw(10) << "First Name" << "|"
                << std::setw(10) << "laste Name" << "|"
                << std::setw(10) << "Nickname"<<"|";
    for(int i = 0; i < count ; i++)
    {
        contacts[i].display_short(i);
    }
    std::cout << "\n|___________________________________________|\n";
    std::cout << "\nEnter index to view details:";
    int index; 
    if(!(std::cin >> index))
    {
        std::cout << "❌ Invalid input!\n";
        std::cin.clear();
    }
    else if(index < 0 || index >= count)
        std::cout << "❌ Invalid index!\n";
    else 
        contacts[index].display_full();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

}
void    PhoneBook::add_infos()
{
    Contact newcontact;
    newcontact.set_contact();
    if(newcontact.is_empty())
        return ;
    contacts[nextIndex] = newcontact;
    if(count < 8)
        count++;
    nextIndex = (nextIndex + 1 ) % 8;
    std::cout << "✅ Contact added successfully!\n";
}
int main()
{
    PhoneBook phonebook;
    std::string str;

    while(true)
    {
        std::cout << "Enter a command > " ;
        std::getline(std::cin, str);
        if(str == "ADD")
            phonebook.add_infos();
        else if(str == "SEARCH")
            phonebook.get_infos();
        else if(str == "EXIT" || std::cin.eof())
        {
            std::cout << "👋 Goodbye!\n";
            break;
        }
        else 
            std::cout << "❌ Unknown command!\n";
        
    }
    return(0);
}
