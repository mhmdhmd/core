#pragma once

#include "IServiceSettingsFactory.h"

class BloodServiceSettingsFactory : public IServiceSettingsFactory {

private:
    shared_ptr<Settings> _settings;

public:
    BloodServiceSettingsFactory();
    shared_ptr<Settings> get_settings() const final;
};