#pragma once

#include "DomainCondition.h"
#include "DomainPlan.h"
#include <engine/BasicUtilityFunction.h>
#include <engine/DefaultUtilityFunction.h>
#include <engine/UtilityFunction.h>
/*PROTECTED REGION ID(incl1407153611768) ENABLED START*/
// Add inlcudes here
/*PROTECTED REGION END*/

namespace alica
{
/*PROTECTED REGION ID(meth1407153611768) ENABLED START*/
// Add other things here
/*PROTECTED REGION END*/
class PlanOne1407153611768 : public DomainPlan
{
public:
    PlanOne1407153611768();
    virtual ~PlanOne1407153611768();
    /*PROTECTED REGION ID(pub1407153611768) ENABLED START*/
    // Add additional public methods here
    /*PROTECTED REGION END*/
protected:
    // Override these methods for your use case
    // virtual void run(void* msg) override;
    // virtual void onInit() override;
    // virtual void onTerminate() override;
    /*PROTECTED REGION ID(pro1407153611768) ENABLED START*/
    // Add additional protected methods here
    /*PROTECTED REGION END*/
private:
    /*PROTECTED REGION ID(prv1407153611768) ENABLED START*/
    // Add additional private methods here
    /*PROTECTED REGION END*/
};

class UtilityFunction1407153611768 : public BasicUtilityFunction
{
    std::shared_ptr<UtilityFunction> getUtilityFunction(Plan* plan);
};
} /* namespace alica */