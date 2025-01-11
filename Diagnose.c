#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Declarations
void showMenu();
void runDiskCheck();
void runNetworkCheck();
void runSystemFileCheck();
void cleanTemporaryFiles();
void optimizeStartupPrograms();
void visitWebsite();
void showHelp();
void aboutProgram();

// Developer Info
#define DEVELOPER "Harshit Mishra"
#define WEBSITE "https://mishraharshit.vercel.app"

// Main Function
int main() {
    int choice;

    while (1) {
        showMenu();
        printf("Enter your choice (1-7): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                runDiskCheck();
                break;
            case 2:
                runNetworkCheck();
                break;
            case 3:
                runSystemFileCheck();
                break;
            case 4:
                cleanTemporaryFiles();
                break;
            case 5:
                optimizeStartupPrograms();
                break;
            case 6:
                visitWebsite();
                break;
            case 7:
                showHelp();
                break;
            case 8:
                aboutProgram();
                break;
            case 0:
                printf("Exiting the program. Thank you for using this tool.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\nPress Enter to return to the menu...\n");
        getchar();
        getchar();
    }

    return 0;
}

// Display Main Menu
void showMenu() {
    system("cls || clear");
    printf("=============================================\n");
    printf("      Powerful Windows Troubleshooter\n");
    printf("           Developed by %s\n", DEVELOPER);
    printf("           Website: %s\n", WEBSITE);
    printf("=============================================\n");
    printf("1. Run Disk Check\n");
    printf("2. Run Network Diagnostics\n");
    printf("3. Run System File Check\n");
    printf("4. Clean Temporary Files\n");
    printf("5. Optimize Startup Programs\n");
    printf("6. Visit Developer's Website\n");
    printf("7. Help\n");
    printf("8. About\n");
    printf("0. Exit\n");
    printf("=============================================\n");
}

// Disk Check Function
void runDiskCheck() {
    printf("\nRunning Disk Check...\n");
    system("chkdsk /f /r"); // Runs Windows Disk Check
    printf("Disk check completed.\n");
}

// Network Diagnostics Function
void runNetworkCheck() {
    printf("\nRunning Network Diagnostics...\n");
    system("ipconfig /flushdns");  // Clears DNS cache
    system("netsh int ip reset"); // Resets TCP/IP settings
    system("netsh winsock reset"); // Resets Winsock catalog
    printf("Network diagnostics completed. Please restart your computer if necessary.\n");
}

// System File Check Function
void runSystemFileCheck() {
    printf("\nRunning System File Check...\n");
    system("sfc /scannow"); // Runs System File Checker
    printf("System file check completed. Check for any messages above.\n");
}

// Clean Temporary Files Function
void cleanTemporaryFiles() {
    printf("\nCleaning Temporary Files...\n");
    system("del /q /f /s %TEMP%\\*"); // Deletes temporary files
    system("cleanmgr"); // Opens Disk Cleanup tool
    printf("Temporary files cleaned.\n");
}

// Optimize Startup Programs Function
void optimizeStartupPrograms() {
    printf("\nOptimizing Startup Programs...\n");
    printf("Use Task Manager to enable or disable startup programs.\n");
    system("start taskmgr"); // Opens Task Manager
    printf("Task Manager opened. Please configure startup programs manually.\n");
}

// Visit Developer's Website Function
void visitWebsite() {
    int choice;
    printf("\nDo you want to visit the developer's website?\n");
    printf("1. Yes\n");
    printf("0. No (Return to Main Menu)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Redirecting to %s...\n", WEBSITE);
        system("start https://mishraharshit.vercel.app"); // Opens website in default browser
    } else if (choice == 0) {
        printf("Returning to the main menu...\n");
    } else {
        printf("Invalid choice. Returning to the main menu.\n");
    }
}

// Help Section
void showHelp() {
    printf("\nHelp Section\n");
    printf("=============================================\n");
    printf("This program is a powerful Windows troubleshooter designed to help you diagnose\n");
    printf("and fix common issues on your Windows PC.\n");
    printf("Options available:\n");
    printf("1. Disk Check: Scans and fixes errors on your hard drive.\n");
    printf("2. Network Diagnostics: Diagnoses and resets network settings.\n");
    printf("3. System File Check: Scans and repairs corrupted system files.\n");
    printf("4. Clean Temporary Files: Deletes temporary files to free up space.\n");
    printf("5. Optimize Startup Programs: Helps you manage startup programs.\n");
    printf("6. Visit Developer's Website: Redirects to the developer's website.\n");
    printf("How to Use:\n");
    printf("1. Select the option from the menu by entering the corresponding number.\n");
    printf("2. Follow the on-screen instructions.\n");
    printf("=============================================\n");
    printf("Developer: %s\n", DEVELOPER);
    printf("Website: %s\n", WEBSITE);
}

// About Program Section
void aboutProgram() {
    printf("\nAbout This Program\n");
    printf("=============================================\n");
    printf("Powerful Windows Troubleshooter\n");
    printf("Version: 2.0\n");
    printf("Developer: %s\n", DEVELOPER);
    printf("Website: %s\n", WEBSITE);
    printf("This program is designed to simplify troubleshooting for Windows users.\n");
    printf("=============================================\n");
}
