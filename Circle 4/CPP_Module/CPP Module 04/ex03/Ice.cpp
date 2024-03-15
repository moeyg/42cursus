#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") { }

Ice::Ice(const Ice& ice)
{
	*this = ice;
}

Ice&    Ice::operator=(const Ice &ice)
{
	this->type = ice.type;
	return *this;
}

Ice::~Ice(void) { }

Ice*    Ice::clone(void) const
{
    return new Ice();
}

void Ice::use(ICharacter& target)
{
    std::cout << BLUE << "* shoots an ice bolt at " << target.getName() << " *" << RESET << std::endl;
}
