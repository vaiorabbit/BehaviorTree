#pragma once

#include <cstdint>
#include <string>
#include <vector>

class BTNode;
class BTLeafNode;
class BTCompositeNode;
class BTContext;

typedef std::int8_t BTInt8;
typedef std::int32_t BTInt32;
typedef std::string  BTStr;
typedef float BTFloat32;

typedef std::vector<BTNode*> BTNodeList;

typedef BTInt32 BTNodeID;
typedef BTStr   BTNodeName;

enum BTStatus : BTInt8
{
    Success = 0,
    Failure = 1,
    Running = 2,
    Unknown = 3
};
