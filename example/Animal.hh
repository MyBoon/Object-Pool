#ifndef		_ANIMAL_HH_
# define	_ANIMAL_HH_

# include "PoolObject.hh"

class Animal : public PoolObject
{

public:
	Animal(void);
	~Animal(void);

public:
	PoolObject *clone(void) const;
	void reset(void);

public:
	void setLife(const unsigned int);
	const unsigned int getLife(void) const;

private:
	unsigned int _life;
};

#endif /*!_ANIMAL_HH_*/