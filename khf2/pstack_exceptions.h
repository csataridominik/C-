//
// Created by balin on 9/22/2021.
//

#ifndef INC_03_HAZI_REF_PSTACK_EXCEPTIONS_H
#define INC_03_HAZI_REF_PSTACK_EXCEPTIONS_H

class UnderFlowException : public std::exception {
public:
    const char* what() const noexcept { return "Alulcsordulas!"; }
};

class OverFlowException : public std::exception {
public:
    const char* what() const noexcept { return "Tulcsordulas!"; }
};


#endif //INC_03_HAZI_REF_PSTACK_EXCEPTIONS_H
