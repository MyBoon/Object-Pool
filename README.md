Object-Pool
===========

This is my C++ implementation of the well known object pool pattern.
This Object pool doesn't claim to be better than all other Object Pool implementations. This is just **my** implementation :)

What is an Object Pool ?
------------------------

The object pool pattern uses a set of initialised objects kept ready to use, rather than allocating and destroying them on demand. A client of the pool will request an object from the pool and perform operations on the returned object. When the client has finished, it returns the object to the pool rather than destroying it. Object pooling can offer a significant performance boost in situations where the cost of initializing a class instance is high, the rate of instantiation of a class is high, and the number of instances in use at any one time is low.

Some specifications
-------------------

- Automaticly in *AUTO EXTEND* mode : when no more objects are available and one is requested, the pool creates an object. (can be disabled)

- Can handle all types of objects whenever they inherits of the PoolObject interface.

- Can be use as a Multi Object Pool (see example)

How to use Object-Pool ?
------------------------

Take a look inside the *example* directory.

A word about the PoolObject Interface
-------------------------------------

When you inherit from PoolObject, you are forced to implement two methods :

- Clone : make another exact replica of the object. In most case, this implementation can be used :

```c++
PoolObject *YourObject::clone(void) const
{
	return (new YourObject(*this));
}
```

- Reset : reset all object attributes. In this way, the pool always returns *clean* objects.