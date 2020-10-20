#pragma once

#include "IService.h"

#include "IResourceFactory.h"
#include "IServiceSettingsFactory.h"

class BloodService : public IService{

private:
    Service _service;
    shared_ptr<IServiceSettingsFactory> _settings_factory;

public:
    BloodService(shared_ptr<IResourceFactory> resource_factory, shared_ptr<IServiceSettingsFactory> settings_factory);
    void start() final;
};