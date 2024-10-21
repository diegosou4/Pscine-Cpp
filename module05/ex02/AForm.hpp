#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include <ostream>
#include <exception>

class Bureaucrat;

class AForm{
    private:
        const std::string  _name;
        bool _signed;
        const int _gradeToSign;
        const int _gradeToExecute;
    public:
        AForm();
        ~AForm();
        AForm(std::string name, int gradeToSign, int gradeToExecute);
        AForm(AForm const &other);
        AForm &operator=(AForm const &other);
        void beSigned(Bureaucrat &bureaucrat);
        int getGradeToSign() const;
        int getGradeToExecute() const;
        const std::string getName() const;
        bool getSigned() const;
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        virtual void executeForm(AForm const &Form) const = 0;
};

std::ostream& operator<<( std::ostream& os, const AForm& obj );








#endif