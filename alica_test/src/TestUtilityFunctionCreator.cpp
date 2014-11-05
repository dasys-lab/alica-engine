/*
 * TestUtilityFunctionCreator.cpp
 *
 *  Created on: Oct 8, 2014
 *      Author: Stefan Jakob
 */

#include "TestUtilityFunctionCreator.h"
#include "SimpleTestPlan1412252439925.h"
#include "MultiAgentTestMaster1413200842973.h"
#include "MultiAgentTestPlan1413200862180.h"
#include "ConstraintTestPlan1414068524245.h"
#include "engine/BasicUtilityFunction.h"

#include <iostream>

using namespace std;
using namespace alicaAutogenerated;

namespace alicaTests
{

	TestUtilityFunctionCreator::~TestUtilityFunctionCreator()
	{
	}

	TestUtilityFunctionCreator::TestUtilityFunctionCreator()
	{
	}

	shared_ptr<alica::BasicUtilityFunction> TestUtilityFunctionCreator::createUtility(long utilityfunctionConfId)
	{
		switch (utilityfunctionConfId)
		{
			case 1407153703092:
			case 1407153683051:
			case 1407153663917:
			case 1407153645238:
			case 1407153611768:
			case 1407152758497:
			case 1402488437260:
			case 1402488991641:
			case 1402488770050:
			case 1402488870347:
			case 1402488893641:
			case 1402489318663:
			case 1402488634525:
			case 1412252439925:
				return make_shared<UtilityFunction1412252439925>();
				break;
			case 1413200862180:
				return make_shared<UtilityFunction1413200862180>();
				break;
			case 1413200842973:
				return make_shared<UtilityFunction1413200842973>();
				break;
			case 1414068524245:
				return make_shared<UtilityFunction1414068524245>();
				break;
			default:
				cerr << "TestUtilityFunctionCreator: Unknown utility function id requested: " << utilityfunctionConfId
						<< endl;
				throw new exception();
				break;
		}
		return nullptr;
	}

} /* namespace alica */
