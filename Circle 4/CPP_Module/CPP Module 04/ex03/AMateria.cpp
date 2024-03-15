#include "AMateria.hpp"

AMateria::AMateria(void) { }

AMateria::AMateria(const std::string& type)
{
	this->type = type;
}

AMateria::AMateria(const AMateria& aMateria)
{
	*this = aMateria;
}

AMateria& AMateria::operator=(const AMateria& aMateria)
{
	this->type = aMateria.type;
	return (*this);
}

AMateria::~AMateria(void) { }

const std::string&	AMateria::getType(void) const
{
	return (this->type);
}

void    AMateria::use(ICharacter& target)
{
	target.getName();
}