/*
 * SimpleTestPlan1412252439925.cpp
 *
 *  Created on: Oct 8, 2014
 *      Author: Stefan Jakob
 */

#include "SimpleTestPlan1412252439925.h"

using namespace alica;

namespace alicaAutogenerated
{

	shared_ptr<UtilityFunction> UtilityFunction1412252439925::getUtilityFunction(Plan* plan)
	{
		shared_ptr<UtilityFunction> defaultFunction = make_shared<DefaultUtilityFunction>(plan);
		return defaultFunction;
	}

	bool PreCondition1412781707952::evaluate(shared_ptr<RunningPlan> rp)
	{
		return true;
	}


	bool RunTimeCondition1412781693884::evaluate(shared_ptr<RunningPlan> rp)
	{
		return true;
	}


	bool TransitionCondition1412761926856::evaluate(shared_ptr<RunningPlan> rp)
	{
		return rp->anyChildrenStatus(PlanStatus::Success);
		//return rp->anyChildrenTaskSuccess();
	}


} /* namespace alica */

