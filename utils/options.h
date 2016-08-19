#pragma once

#include <string>

class Group;
class Opt;

class Options {
public:
    Options();
    Group& operator()(std::string name, bool& value, std::string desc);

};
