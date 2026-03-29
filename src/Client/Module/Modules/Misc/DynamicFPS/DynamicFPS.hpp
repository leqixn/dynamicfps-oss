#pragma once
#include "../Module.h"

class DynamicFPS : public Module {
public:
    DynamicFPS() : Module("DynamicFPS", "Misc", "Lowers FPS when AFK or tabbed out") {
        addSetting(&enabled);
        addSetting(&unfocusedFPS);
        addSetting(&afkFPS);
        addSetting(&afkTimeout);
    }

    Setting enabled = Setting("Enabled", true);
    Setting unfocusedFPS = Setting("Unfocused FPS", 20.0f, 1.0f, 60.0f);
    Setting afkFPS = Setting("AFK FPS", 30.0f, 1.0f, 60.0f);
    Setting afkTimeout = Setting("AFK Timeout (Sec)", 60.0f, 10.0f, 300.0f);

    void onTick() override;
    bool isAFK();
};
