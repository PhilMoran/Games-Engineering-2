#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Boids\Boid.h"
#include "..\Boids\Flock.h"
#include <iostream>
#include <vector>
//#include "..\Boids\Pvector.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace FormationTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		Flock fish;
		Flock gulls;

		TEST_METHOD(InitialiseWithPredator)
		{
			Boid f(0,0,true);
			
			Assert::AreEqual(7.5f, f.maxSpeed);
			Assert::AreEqual(0.5f, f.maxForce);
		}
		TEST_METHOD(InitialiseWithoutPredator)
		{
			Boid b(0, 0, false);
			
			Assert::AreEqual(2.0f, b.maxSpeed);
			Assert::AreEqual(0.5f, b.maxForce);
		}
		TEST_METHOD(TestSeek)
		{
			Boid c(0, 0, false);
			//c.seek(Pvector(1.0f, 1.0f));
			//Assert::AreEqual(2.0f, c.acceleration);
		}
		TEST_METHOD(NotEquals)
		{
			Assert::AreNotEqual(1, 2);
		}
		TEST_METHOD(IsFalse)
		{
			Assert::IsFalse(fish.test);
		}
		TEST_METHOD(IsTrue)
		{
			Assert::IsTrue(fish.test);
		}
	};
}