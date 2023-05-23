#include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{
private:

	/* data */

public:

	FragTrap();					//constructor
	FragTrap(std::string name);
	~FragTrap();							//destructor
	FragTrap (const FragTrap &obj);				//copie constructor
	FragTrap& operator=(const FragTrap& x);		//assignation constructor

	void highFivesGuys(void);
};
