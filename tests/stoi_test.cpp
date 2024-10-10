/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stoi_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:30:50 by akuburas          #+#    #+#             */
/*   Updated: 2024/10/10 13:43:42 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <limits>
#include <cmath>
#include <cstdlib>



#include <iostream>
#include <string>
#include <cstdlib>

int main() {
    std::string str1 = "10.1";
    std::string str2 = "42";
    char *end;

    // Test with str1
    try {
        int stoiResult = std::stoi(str1);
        std::cout << "std::stoi result for str1: " << stoiResult << std::endl;
    } catch (const std::invalid_argument &e) {
        std::cout << "std::stoi error for str1: " << e.what() << std::endl;
    } catch (const std::out_of_range &e) {
        std::cout << "std::stoi out of range error for str1: " << e.what() << std::endl;
    }

    long strtolResult = std::strtol(str1.c_str(), &end, 10);
    if (*end == '\0') {
        std::cout << "std::strtol result for str1: " << strtolResult << std::endl;
    } else {
        std::cout << "std::strtol partial conversion for str1: " << strtolResult << " (stopped at '" << *end << "')" << std::endl;
    }

    // Test with str2
    try {
        int stoiResult2 = std::stoi(str2);
        std::cout << "std::stoi result for str2: " << stoiResult2 << std::endl;
    } catch (const std::invalid_argument &e) {
        std::cout << "std::stoi error for str2: " << e.what() << std::endl;
    } catch (const std::out_of_range &e) {
        std::cout << "std::stoi out of range error for str2: " << e.what() << std::endl;
    }

    long strtolResult2 = std::strtol(str2.c_str(), &end, 10);
    if (*end == '\0') {
        std::cout << "std::strtol result for str2: " << strtolResult2 << std::endl;
    } else {
        std::cout << "std::strtol partial conversion for str2: " << strtolResult2 << " (stopped at '" << *end << "')" << std::endl;
    }

    return 0;
}