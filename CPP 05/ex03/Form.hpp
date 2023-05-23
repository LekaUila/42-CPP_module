
#ifndef FORM
# define FORM
# include <iostream>
class Bureaucrat;

class Form 
{
private:

	const std::string	__name;
	const int			__grade_need_to_sign;
	const int			__grade_need_to_exe;
	bool				__is_signed;
	class GradeTooHighException : public std::logic_error
	{
	
	public:
		GradeTooHighException()
		: std::logic_error::logic_error("Grade Too High : Must be 0 < Grade < 151")
		{}
	};
	class GradeTooLowException : public std::logic_error
	{
	
	public:
		GradeTooLowException()
		: std::logic_error::logic_error("Grade Too Low : Must be 0 < Grade < 151")
		{}
	};
	class FormNotSigned : public std::logic_error
	{

	public:
		FormNotSigned()
		: std::logic_error::logic_error("Form Not Signed")
		{}
	};


protected:

	/* data */

public:

	Form(std::string n, int gs, int ge);					//constructor
	virtual ~Form() = 0;							//destructor
	Form (const Form &obj);				//copie constructor
	Form& operator=(const Form& x);		//assignation constructor

	const std::string getName() const;
	bool isSigned() const;
	int	getGradeToSign() const;
	int	getGradeToExe() const;
	
	void beSigned(Bureaucrat obj);
	virtual void execute(Bureaucrat const & executor) const;

};
std::ostream& operator<<(std::ostream &out, const Form &obj);

#endif
