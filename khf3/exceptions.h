//
// Created by morak on 2021. 09. 30..
//

#ifndef KHF3_SKELETON_EXCEPTIONS_H
#define KHF3_SKELETON_EXCEPTIONS_H

#include <exception>

//Alulcsordulast jelzo hiba
class UnderFlowException : public std::exception {
public:
    const char *what() const noexcept { return "Underflow!"; }
};

#endif //KHF3_SKELETON_EXCEPTIONS_H
