#include "Human.hh"

Human::Human(void)
	: PoolObject(), _life(100)
{
}

Human::~Human(void)
{
}

PoolObject *Human::clone(void) const
{
	return (new Human(*this));
}

void Human::reset(void)
{
	_life = 100;
}

void Human::setLife(const unsigned int l)
{
	_life = l;
}

const unsigned int Human::getLife(void) const
{
	return _life;
}

