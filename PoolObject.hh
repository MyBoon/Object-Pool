#ifndef		_POOL_OBJECT_HH_
# define	_POOL_OBJECT_HH_

class PoolObject
{
public:
	virtual PoolObject *clone(void) const = 0;
	virtual void reset(void) = 0;
};

#endif /*!_POOL_OBJECT_HH_*/