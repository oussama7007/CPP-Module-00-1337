/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-si- <oait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 00:39:54 by oait-si-          #+#    #+#             */
/*   Updated: 2025/10/20 16:03:26 by oait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PhoneBook.h"


/// you need to fix end of file for each time you require 
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
bool    is_empty(std::string &word)
{
        for(size_t i = 0; i < word.length(); ++i)
        {
            unsigned char c = word[i];
            if(!((c >= 9 && c <= 13) || c == 32))
                return false;
        }
    return true;        
}
bool    is_invalid(std::string &word)
{
    if(is_empty(word))
        return true;
    for(size_t i = 0; i < word.length(); ++i)
    {
            unsigned char c = word[i];
            if(c < 32 || c > 126)
                    return true;
    }
    return false;
}
bool    parse_string( std::string word)
{
    if(word.empty() || is_invalid(word))
        return true;
    return false;
}
bool Contact::set_contact()  
{
    std::cout << "Enter first name: ";
    if (!std::getline(std::cin, firstName))
        return false;  
    
    std::cout << "Enter last name: ";
    if (!std::getline(std::cin, lastName))
        return false;
    
    std::cout << "Enter nickname: ";
    if (!std::getline(std::cin, nickname))
        return false;
    
    std::cout << "Enter phone number: ";
    if (!std::getline(std::cin, phoneNumber))
        return false;
    
    std::cout << "Enter darkest secret: ";
    if (!std::getline(std::cin, darkestSecret))
        return false;

    // Validation
    if (parse_string(firstName) || parse_string(lastName) || 
        parse_string(nickname) || parse_string(phoneNumber) || 
        parse_string(darkestSecret)) {
        std::cout << "❌ Contact cannot have invalid char!\n";
        firstName.clear(); lastName.clear(); nickname.clear();
        phoneNumber.clear(); darkestSecret.clear();
        return false;  
    }
    
    return true; 
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
    if(!newcontact.set_contact())
            return;
    if(newcontact.is_empty())
        return ;
    contacts[nextIndex] = newcontact;
    if(count < 8)
        count++;
    nextIndex = (nextIndex + 1 ) % 8;
    std::cout << "✅ Contact added successfully!\n";
}
bool checkEOF() {
    if (std::cin.eof()) {
        std::cout << "\n👋 Goodbye!\n";
        return true;
    }
    return false;
}
int main()
{
    PhoneBook phonebook;
    std::string str;

    while(true)
    {
        if (checkEOF()) break;
        std::cout << "Enter a command > ";
        if (!std::getline(std::cin, str)) {
            std::cout << "👋 Goodbye!\n";
            break;
        }
        if(str == "ADD")
            phonebook.add_infos();
        else if(str == "SEARCH")
            phonebook.get_infos();
        else if(str == "EXIT")
        {
            std::cout << "👋 Goodbye!\n";
            break;
        }
        else 
            std::cout << "❌ Unknown command!\n";
        
    }
    return(0);
}
