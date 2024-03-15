#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		source[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& materiaSource)
{
    *this = materiaSource;
}

MateriaSource&  MateriaSource::operator=(const MateriaSource& materiaSource)
{
	for (int i = 0; i < 4; i++)
    {
        delete this->source[i];
        if (materiaSource.source[i])
            this->source[i] = materiaSource.source[i]->clone();
        else
            this->source[i] = NULL;
    }
	return *this;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		delete source[i];
}

void    MateriaSource::learnMateria(AMateria* aMateria)
{
	for (int i = 0; i < 4; i++)
    {
		if (source[i] == NULL)
        {
			source[i] = aMateria;
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(const std::string& type)
{
	int i;
	
	for (i = 0; i < 4; i++)
    {
		if (source[i] && source[i]->getType() == type)
			break ;
	}
	if (i == 4)
		return (NULL);
	return (source[i]->clone());
}