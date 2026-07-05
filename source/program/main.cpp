#include "lib.hpp"
#include "../../src/Game/A-File-You-Would-Like-To-Include.h" //follow this path for the game headers (they might be more folders after Game)

// Trampoline hooks add code before or after a function, without replacing it
HOOK_DEFINE_TRAMPOLINE(myTrampolineHook) {
    static void Callback(bool argument) {
        // your custom code

        // Call the original function
        Orig(argument);
    }
};

// Trampoline hooks completly replaces a function with your code
HOOK_DEFINE_REPLACE(myReplaceHook) {
    static void Callback(bool argument) {
        // your custom code
    }
};

extern "C" void exl_main(void* x0, void* x1) {
    // Setup hooking environment
    exl::hook::Initialize();

    // Install the hooks at the provided offset
    myTrampolineHook::InstallAtOffset(0x9a2bd5);
    myReplaceHook::InstallAtOffset(0x9a2bd6);
}

// There are more things in exlaunch, these are only the basics for BOTW modding
// This code won't compile, it's just a little tutorial. Replace it with your own code !