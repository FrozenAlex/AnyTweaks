#include "main.hpp"
#include "AnyTweaks.hpp"
#include "AnyTweaksConfig.hpp"

Logger& getLogger() {
    static Logger* logger = new Logger(modInfo, LoggerOptions(false, true));
    return *logger;
}

extern "C" void setup(CModInfo& info) {
    info.id = ID;
    info.version = VERSION;
    info.version_long = GIT_COMMIT;
    modInfo.assign(info);
	
    getAnyTweaksConfig().Init(modInfo);
    getLogger().info("Completed AnyTweaks setup!");
}

extern "C" void load() {
    il2cpp_functions::Init();

    getLogger().info("Installing AnyTweaks...");
    AnyTweaks::Install();
    getLogger().info("Installed AnyTweaks!");
}
