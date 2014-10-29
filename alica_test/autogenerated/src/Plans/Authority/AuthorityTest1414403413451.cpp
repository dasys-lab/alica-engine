#include "Plans/Authority/AuthorityTest1414403413451.h"
using namespace alica;
/*PROTECTED REGION ID(eph1414403413451) ENABLED START*/ //Add additional using directives here
#include "DistXContour.h"
#include "engine/USummand.h"
#include "DummyTestSummand.h"
/*PROTECTED REGION END*/
namespace alicaAutogenerated
{
//Plan:AuthorityTest

/* generated comment
 
 Task: DefaultTask  -> EntryPoint-ID: 1414403429951

 Task: AttackTask  -> EntryPoint-ID: 1414403522424

 */
shared_ptr<UtilityFunction> UtilityFunction1414403413451::getUtilityFunction(Plan* plan)
{
  /*PROTECTED REGION ID(1414403413451) ENABLED START*/
	vector<long> relevantEntryPoints;
	relevantEntryPoints.push_back(1414403522424);
	relevantEntryPoints.push_back(1414403429951);
	vector<pair<double, double>> contourPoints;
	contourPoints.push_back(make_pair(-1, 0.1));
	contourPoints.push_back(make_pair(1, 1));

	DummyTestSummand* us = new DummyTestSummand(1.0, "Something", 1, relevantEntryPoints);
	list<USummand*> utilSummands;
	utilSummands.push_back(us);
  shared_ptr < UtilityFunction > function = make_shared < UtilityFunction > ("test", utilSummands, 0.1, 0.1, plan);

  return function;

  /*PROTECTED REGION END*/
}

//State: UpperState in Plan: AuthorityTest

//State: LowerState in Plan: AuthorityTest

}
