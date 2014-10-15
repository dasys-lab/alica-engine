/*
 * MultiAgentTestMaster1413200842973.cpp
 *
 *  Created on: Oct 13, 2014
 *      Author: Stefan Jakob
 */

#include "MultiAgentTestMaster1413200842973.h"
#include "TestWorldModel.h"

namespace alicaAutogenerated
{

	shared_ptr<UtilityFunction> UtilityFunction1413200842973::getUtilityFunction(Plan* plan)
	{
		shared_ptr<UtilityFunction> defaultFunction = make_shared<DefaultUtilityFunction>(plan);
		return defaultFunction;
	}

	bool TransitionCondition1413201227586::evaluate(shared_ptr<RunningPlan> rp)
	{
		if(rp->getOwnID() == 8)
		{
			return alicaTests::TestWorldModel::getOne()->isTransitionCondition1413201227586();
		}
		else
		{
			return alicaTests::TestWorldModel::getTwo()->isTransitionCondition1413201227586();
		}
	}

	bool TransitionCondition1413201389955::evaluate(shared_ptr<RunningPlan> rp)
	{
		if(rp->getOwnID() == 8)
		{
			return alicaTests::TestWorldModel::getOne()->isTransitionCondition1413201389955();
		}
		else
		{
			return alicaTests::TestWorldModel::getTwo()->isTransitionCondition1413201389955();
		}
	}
} /* namespace alica */