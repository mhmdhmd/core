#include "BloodServiceSettingsFactory.h"

BloodServiceSettingsFactory::BloodServiceSettingsFactory() {
    _settings = make_shared<Settings>();
    _settings->set_port(8080);
    _settings->set_default_header("Connection", "close");
    _settings->set_default_header("Access-Control-Allow-Origin", "*");
}

shared_ptr<Settings> BloodServiceSettingsFactory::get_settings() const {
    return _settings;
}