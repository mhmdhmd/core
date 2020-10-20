#pragma once

#include "IResourceFactory.h"

//#include <tuple>

class BloodResourceFactory : public IResourceFactory
{

private:
    shared_ptr<Resource> _resource;
    void get_handler(const shared_ptr<Session> session);
    tuple<float, float, string> get_path_parameters(const shared_ptr<Session> session);
    float calculate(float num1, float num2, string operation);
    string to_json(float result);

public:
    BloodResourceFactory();
    shared_ptr<Resource> get_resource() const final;
};