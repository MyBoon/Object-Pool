#include "Pool.hh"
#include "Human.hh"
#include "Animal.hh"

int main()
{
	Pool p;
	p.configure<Human>(500);
	p.configure<Animal>(200);

	Human *h1 = p.get<Human>();
	if (h1)
	{
		std::cout << "life : " << h1->getLife() << std::endl;
		std::cout << p.size<Human>() << std::endl;
		p.release(h1);
		std::cout << p.size<Human>() << std::endl;
	}

	Animal *a1 = p.get<Animal>();
	if (a1)
	{
		std::cout << "life : " << a1->getLife() << std::endl;
		std::cout << p.size<Animal>() << std::endl;
		p.release(a1);
		std::cout << p.size<Animal>() << std::endl;
	}
}
