#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap,  public FragTrap
{
private:


protected:



public:

	DiamondTrap();					//constructor
	DiamondTrap(std::string name);
	~DiamondTrap();							//destructor
	DiamondTrap (const DiamondTrap &obj);				//copie constructor
	DiamondTrap& operator=(const DiamondTrap& x);		//assignation constructor

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	std::string get_name() const;
	int get_hp() const;
	int get_ep() const;
	int get_atk() const;

};
