#include "BloodResourceFactory.h"
#include "BloodServiceSettingsFactory.h"
#include "BloodService.h"


int main(int argc, char** argv){
    auto resource_factory = make_shared<BloodResourceFactory>();
    auto setting_factory = make_shared<BloodServiceSettingsFactory>();
    BloodService service{resource_factory, setting_factory};

    service.start();

    return 0;
}