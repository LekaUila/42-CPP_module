#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:

	/* data */

public:

	ScavTrap();					//constructor
	ScavTrap(std::string name);
	~ScavTrap();							//destructor
	ScavTrap (const ScavTrap &obj);				//copie constructor
	ScavTrap& operator=(const ScavTrap& x);		//assignation constructor

	void guardGate();
};
