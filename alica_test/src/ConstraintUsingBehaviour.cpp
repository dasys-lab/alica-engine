/*
 * ConstraintUsingBehaviour.cpp
 *
 *  Created on: Oct 23, 2014
 *      Author: Philipp
 */

#include "ConstraintUsingBehaviour.h"

#include <engine/model/Variable.h>

namespace alicaTests
{

	ConstraintUsingBehaviour::ConstraintUsingBehaviour() :
			alica::BasicBehaviour("ConstraintUsingBehaviour")
	{
		this->callCounter = 0;
		this->query = make_shared<alica::ConstraintQuery>();
	}

	ConstraintUsingBehaviour::~ConstraintUsingBehaviour()
	{
	}

	void ConstraintUsingBehaviour::run(void* msg)
	{
		callCounter++;
//		cout << "ConstraintUsingBehaviour was called " << callCounter << " times!" << endl;
		vector<double> result;
		query->getSolution(runningPlan, result);
	}

	int ConstraintUsingBehaviour::getCallCounter()
	{
		return callCounter;
	}

	void ConstraintUsingBehaviour::initialiseParameters()
	{
		query->addVariable(getVariablesByName("X"));
		query->addVariable(getVariablesByName("Y"));
	}

} /* namespace alica */