#include "pch.h"
#include <FlashRuntimeExtensions.h>
#include <Windows.h>
#include <string>
#include <sstream>

// Function to show a native Windows alert with customizable button label and title
void showNativeAlert(const std::string& message, const std::string& buttonLabel, const std::string& title) {
    // Create a MessageBox with a custom button label
    MessageBoxA(NULL, message.c_str(), title.c_str(), MB_OK | MB_ICONINFORMATION);
}

// ActionScript function to call the native alert with custom parameters
FREObject ASShowNativeAlert(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]) {
    // Get the message from ActionScript
    uint32_t strLength;
    const uint8_t* asMessage;
    FREGetObjectAsUTF8(argv[0], &strLength, &asMessage);
    std::string message((const char*)asMessage, strLength);

    // Get the button label from ActionScript
    const uint8_t* asButtonLabel;
    FREGetObjectAsUTF8(argv[1], &strLength, &asButtonLabel);
    std::string buttonLabel((const char*)asButtonLabel, strLength);

    // Get the title from ActionScript
    const uint8_t* asTitle;
    FREGetObjectAsUTF8(argv[2], &strLength, &asTitle);
    std::string title((const char*)asTitle, strLength);

    // Show the native alert with the provided parameters
    showNativeAlert(message, buttonLabel, title);

    // Return NULL as no return value is needed
    return NULL;
}

// Context finalizer
void contextFinalizer(FREContext ctx) {
    return;
}

// Context initializer
void contextInitializer(void* extData, const uint8_t* ctxType, FREContext ctx, uint32_t* numFunctionsToSet, const FRENamedFunction** functionsToSet) {
    static FRENamedFunction extensionFunctions[] = {
        { (const uint8_t*)"show_native_alert", NULL, &ASShowNativeAlert }
    };

    *numFunctionsToSet = sizeof(extensionFunctions) / sizeof(FRENamedFunction);
    *functionsToSet = extensionFunctions;
}

// Extension initializer and finalizer
extern "C" {
    __declspec(dllexport) void ExtensionInitializer(void** extData, FREContextInitializer* ctxInitializer, FREContextFinalizer* ctxFinalizer) {
        *ctxInitializer = &contextInitializer;
        *ctxFinalizer = &contextFinalizer;
    }

    __declspec(dllexport) void ExtensionFinalizer(void* extData) {
        return;
    }
}
