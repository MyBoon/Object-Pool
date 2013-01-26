Object-Pool
===========

This is my own implementation of the well known object pool pattern.
This Object pool doesn't claim to be better than all other Object Pool implementation.
This is just **my** implementation ... feel free to contact me if I've made something wrong :)

What is an Object Pool ?
========================

The object pool pattern uses a set of initialised objects kept ready to use, rather than allocating and destroying them on demand. A client of the pool will request an object from the pool and perform operations on the returned object. When the client has finished, it returns the object to the pool rather than destroying it. Object pooling can offer a significant performance boost in situations where the cost of initializing a class instance is high, the rate of instantiation of a class is high, and the number of instances in use at any one time is low.