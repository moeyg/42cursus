#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") { }

Cure::Cure(const Cure& cure)
{
	*this = cure;
}

Cure& Cure::operator=(const Cure& cure)
{
	this->type = cure.type;
	return *this;
}

Cure::~Cure(void) { }

Cure* Cure::clone(void) const
{
    return new Cure();
}

void Cure::use(ICharacter& target)
{
    std::cout << PURPLE << "* heals " << target.getName() << "'s wounds *" << RESET << std::endl;
}