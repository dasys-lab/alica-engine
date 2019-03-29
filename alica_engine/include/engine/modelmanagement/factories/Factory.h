#pragma once

#include "engine/AlicaEngine.h"
#include "engine/modelmanagement/ModelManager.h"

#include <yaml-cpp/yaml.h>

#include <map>

namespace alica
{
using ReferenceList = std::list<std::pair<int64_t, int64_t>>;
class AlicaElement;
class Factory
{
public:
    Factory() = delete;
    static void setModelManager(ModelManager* modelManager);

protected:
    static ReferenceList stateInTransitionReferences;
    static ReferenceList stateOutTransitionReferences;
    static ReferenceList stateAbstractPlanReferences;
    static ReferenceList transitionSynchReferences;
    static ReferenceList transitionInStateReferences;
    static ReferenceList transitionOutStateReferences;
    static ReferenceList paramSubPlanReferences;
    static ReferenceList paramSubVarReferences;
    static ReferenceList paramVarReferences;
    static ReferenceList conditionVarReferences;
    static ReferenceList quantifierScopeReferences;
    static ReferenceList epStateReferences;
    static ReferenceList epTaskReferences;
    static ReferenceList planTypePlanReferences;
    static ReferenceList rtmRoleReferences;
    static ReferenceList charCapReferences;
    static ReferenceList charCapValReferences;


    template <typename T>
    static T getValue(const YAML::Node& node, const std::string& key);
    template <typename T>
    static T getValue(const YAML::Node& node, const std::string& key, T defaultValue);
    static const AlicaElement* getElement(const int64_t id);
    static int64_t getReferencedId(const std::string& referenceString);
    static int64_t getReferencedId(const YAML::Node& referenceNode);
    static std::vector<int64_t> getReferencedIds(const YAML::Node& referenceListNode);
    static void storeElement(AlicaElement* ael, const std::string& type);
    static void setAttributes(const YAML::Node& node, AlicaElement* ael);
    static bool isValid(const YAML::Node& node) {return node && YAML::NodeType::Null != node.Type();}
private:
    static ModelManager* modelManager;
};

template <typename T>
T Factory::getValue(const YAML::Node& node, const std::string& key)
{
    if (isValid(node[key])) {
        return node[key].as<T>();
    } else {
        std::cerr << "Error Node: " << node << std::endl;
        AlicaEngine::abort("Factory: Node does not provide an value for: ", key);
        // does not happen, because abort() cancels the current process
        return T();
    }
}

template <typename T>
T Factory::getValue(const YAML::Node& node, const std::string& key, T defaultValue)
{
    if (isValid(node[key])) {
        return node[key].as<T>();
    } else {
        return defaultValue;
    }
}
} // namespace alica
