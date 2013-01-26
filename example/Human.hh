#ifndef		_HUMAN_HH_
# define	_HUMAN_HH_

# include "PoolObject.hh"

class Human : public PoolObject
{

public:
	Human(void);
	~Human(void);

public:
	PoolObject *clone(void) const;
	void reset(void);

public:
	void setLife(const unsigned int);
	const unsigned int getLife(void) const;

private:
	unsigned int _life;
};

#endif /*!_HUMAN_HH_*/