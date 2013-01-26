#include "Animal.hh"

Animal::Animal(void)
	: PoolObject(), _life(20)
{
}

Animal::~Animal(void)
{
}

PoolObject *Animal::clone(void) const
{
	return (new Animal(*this));
}

void Animal::reset(void)
{
	_life = 20;
}

void Animal::setLife(const unsigned int l)
{
	_life = l;
}

const unsigned int Animal::getLife(void) const
{
	return _life;
}

