#pragma once

#include "engine/AlicaClock.h"
#include <string>
#include <atomic>

namespace alica
{

class RunningPlan;
class Configuration;
class AlicaEngine;
class ThreadSafePlanInterface;

// For comments, have a look at BasicBehaviour. This class essentially mimics its behaviour.
// TODO: This indicates that these classes should probably be combined
class BasicPlan
{
public:
    BasicPlan();
    virtual ~BasicPlan() = default;

    void start(RunningPlan* rp);
    void stop();

    void setEngine(AlicaEngine* engine) { _ae = engine; }
    void setConfiguration(const Configuration* conf) { _configuration = conf; }

    AlicaTime getInterval() { return _msInterval; }
    void setInterval(int32_t msInterval) { _msInterval = AlicaTime::milliseconds(msInterval); }

protected:
    ThreadSafePlanInterface getPlanContext() const;

    virtual void onInit(){};
    virtual void run(void* msg){};
    virtual void onTerminate(){};

private:
    using Counter = uint64_t;

    void doInit();
    void doRun(void* msg);
    void doTerminate();

    void sendLogMessage(int level, const std::string& message) const;

    static constexpr bool isActive(Counter cnt) { return !(cnt & 1); }
    bool isExecutingInContext() const
    {
        Counter sc = _signalState.load(), ec = _execState.load();
        return sc == ec && isActive(sc);
    }

    static constexpr int DEFAULT_MS_INTERVAL = 100;

    alica::AlicaEngine* _ae;
    const Configuration* _configuration;
    AlicaTime _msInterval;
    int64_t _activeRunJobId;

    std::atomic<RunningPlan*> _signalContext;
    std::atomic<RunningPlan*> _execContext;
    std::atomic<Counter> _signalState;
    std::atomic<Counter> _execState;

    bool _initExecuted;
};
} // namespace alica
