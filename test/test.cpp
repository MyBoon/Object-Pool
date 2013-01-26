#include "gtest/gtest.h"
#include "Pool.hh"

class TestObject : public PoolObject
{

public:
	TestObject(void) : _attr(15) {}
	~TestObject(void) {}

public:
	PoolObject *clone(void) const {
		return (new TestObject(*this));
	}

	void reset(void) {
		_attr = 15;
	}

public:
	unsigned int _attr;
};

TEST(Init, Pool) {
	Pool p;
	p.configure<TestObject>(3);
	EXPECT_EQ(3, p.size<TestObject>());
}

TEST(Init, EmptyPool) {
	Pool p;
	p.configure<TestObject>(0);
	EXPECT_EQ(0, p.size<TestObject>());
}

TEST(AutoExtendPool, First) {
	Pool p;
	p.configure<TestObject>(2);
	TestObject *o1 = p.get<TestObject>();
	TestObject *o2 = p.get<TestObject>();
	TestObject *o3 = p.get<TestObject>();
	EXPECT_NE(o3, nullptr);
}

TEST(FixedPool, First) {
	Pool p(Pool::FIXED);
	p.configure<TestObject>(2);
	TestObject *o1 = p.get<TestObject>();
	TestObject *o2 = p.get<TestObject>();
	TestObject *o3 = p.get<TestObject>();
	EXPECT_EQ(o3, nullptr);
}

TEST(GetAndRelease, cleanWay) {
	Pool p;
	p.configure<TestObject>(2);
	TestObject *o1 = p.get<TestObject>();
	TestObject *o2 = p.get<TestObject>();
	p.release(o1);
	p.release(o2);
	EXPECT_EQ(2, p.size<TestObject>());
}

TEST(GetAndRelease, getButNotRelease) {
	Pool p;
	p.configure<TestObject>(2);
	TestObject *o1 = p.get<TestObject>();
	TestObject *o2 = p.get<TestObject>();
	EXPECT_EQ(0, p.size<TestObject>());
}

TEST(Reset, simpleCheck) {
	Pool p(Pool::FIXED);
	p.configure<TestObject>(1);
	TestObject *o1 = p.get<TestObject>();
	o1->_attr = 25;
	p.release(o1);
	TestObject *o2 = p.get<TestObject>();
	EXPECT_EQ(15, o2->_attr);
}

int main(int argc, char **argv) {
      ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
}