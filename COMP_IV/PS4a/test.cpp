#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

#include "CircularBuffer.hpp"

// Tests various aspects of the contructor.
BOOST_AUTO_TEST_CASE(Constructor)
{
	// Shouldn't fail.
	BOOST_REQUIRE_NO_THROW(CircularBuffer(100));

	// Should fail.
	BOOST_REQUIRE_THROW(CircularBuffer(0), std::exception);
	BOOST_REQUIRE_THROW(CircularBuffer(0), std::invalid_argument);
	BOOST_REQUIRE_THROW(CircularBuffer(-1), std::invalid_argument);
}

// Checks the size() method
BOOST_AUTO_TEST_CASE(Size)
{
	CircularBuffer test(1);

	
	BOOST_REQUIRE(test.size() == 0);

	test.enqueue(5);

	
	BOOST_REQUIRE(test.size() == 1);

	test.dequeue();
	BOOST_REQUIRE(test.size() == 0);
}

// Checks the isEmpty() method
BOOST_AUTO_TEST_CASE(isEmpty)
{
	// True
	CircularBuffer test(5);
	BOOST_REQUIRE(test.isEmpty() == true);

	// False
	CircularBuffer test2(5);
	test2.enqueue(5);
	BOOST_REQUIRE(test2.isEmpty() == false);
}

// Checks the isFull() method
BOOST_AUTO_TEST_CASE(isFull)
{
	CircularBuffer test(5);
	BOOST_REQUIRE(test.isFull() == false);

	CircularBuffer test2(1);
	test2.enqueue(5);
	BOOST_REQUIRE(test2.isFull() == true);
}

// Test enqueue
BOOST_AUTO_TEST_CASE(Enqueue)
{
	// These test basic enqueuing
	CircularBuffer test(5);

	BOOST_REQUIRE_NO_THROW(test.enqueue(1));
	BOOST_REQUIRE_NO_THROW(test.enqueue(2));
	BOOST_REQUIRE_NO_THROW(test.enqueue(3));
	BOOST_REQUIRE_NO_THROW(test.enqueue(4));
	BOOST_REQUIRE_NO_THROW(test.enqueue(5));
	BOOST_REQUIRE_THROW(test.enqueue(6), std::runtime_error);
}

// Test dequeue
BOOST_AUTO_TEST_CASE(Dequeue)
{
	CircularBuffer test(5);

	test.enqueue(0);
	test.enqueue(1);
	test.enqueue(2);

	BOOST_REQUIRE(test.dequeue() == 0);
	BOOST_REQUIRE(test.dequeue() == 1);
	BOOST_REQUIRE(test.dequeue() == 2);
	BOOST_REQUIRE_THROW(test.dequeue(), std::runtime_error);
}
