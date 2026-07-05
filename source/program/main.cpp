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

// This will hook the main function of botw (nnMain)
HOOK_DEFINE_TRAMPOLINE(mainHook) {
    static void Callback(void* thisPtr) { // Note that if there aren't any argument in the base function, you should write `void* [a name]` !
        Orig(thisPtr);

        // your custom code
    }
};


extern "C" void exl_main(void* x0, void* x1) {
    // Setup hooking environment
    exl::hook::Initialize();

    // Install the hooks at the provided offset (offsets can be found in uking_function.csv, at this link : https://github.com/zeldaret/botw/blob/master/data/uking_functions.csv)
    myTrampolineHook::InstallAtOffset(0x9a2bd5);
    myReplaceHook::InstallAtOffset(0x9a2bd6);

    mainHook::InstallAtOffset(0x7d5fe4);
}

// There are more things in exlaunch, these are only the basics for BOTW modding
// This code won't compile, it's just a little tutorial. Replace it with your own code !