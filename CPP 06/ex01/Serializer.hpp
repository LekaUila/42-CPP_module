
#ifndef SERIALIZER
# define SERIALIZER
#include "Data.hpp"
class Serializer 
{
private:

	/* data */

protected:

	/* data */

public:

	Serializer(/* args */);					//constructor
	~Serializer();							//destructor
	Serializer (const Serializer &obj);				//copie constructor
	Serializer& operator=(const Serializer& x);		//assignation constructor
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

 
};
#endif
