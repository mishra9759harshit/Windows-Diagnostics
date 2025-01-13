#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
void askUsername();
void logUserInteraction(const char *username);

// Developer Info
#define DEVELOPER "Harshit Mishra"
#define WEBSITE "https://mishraharshit.vercel.app"

// Global Variable for Username
char username[50];

// Main Function
int main() {
    int choice;

    askUsername();

    while (1) {
        showMenu();
        printf("Enter your choice (0-8): ");
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
                printf("Exiting the program. Thank you for using this tool, %s.\n", username);
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

// Ask for Username
void askUsername() {
    printf("Please enter your name: ");
    getchar(); // To consume the newline character left in the input buffer
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0'; // Remove trailing newline character
    printf("Welcome, %s!\n", username);
    logUserInteraction(username);
}

// Log User Interaction
void logUserInteraction(const char *username) {
    FILE *logFile = fopen("user_log.txt", "a");
    if (logFile == NULL) {
        perror("Error opening log file");
        return;
    }

    time_t currentTime = time(NULL);
    char *timestamp = ctime(&currentTime);
    timestamp[strcspn(timestamp, "\n")] = '\0'; // Remove trailing newline character

    fprintf(logFile, "User: %s | Logged in at: %s\n", username, timestamp);
    fclose(logFile);
}

// Display Main Menu
void showMenu() {
    system("cls || clear");
    printf("=============================================\n");
    printf("      Powerful Windows Troubleshooter\n");
    printf("           Developed by %s\n", DEVELOPER);
    printf("           Website: %s\n", WEBSITE);
    printf("=============================================\n");
    printf("Welcome, %s!\n", username);
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
    system("chkdsk /f /r");
    printf("Disk check completed.\n");
}

// Network Diagnostics Function
void runNetworkCheck() {
    printf("\nRunning Network Diagnostics...\n");
    system("ipconfig /flushdns");
    system("netsh int ip reset");
    system("netsh winsock reset");
    printf("Network diagnostics completed. Please restart your computer if necessary.\n");
}

// System File Check Function
void runSystemFileCheck() {
    printf("\nRunning System File Check...\n");
    system("sfc /scannow");
    printf("System file check completed. Check for any messages above.\n");
}

// Clean Temporary Files Function
void cleanTemporaryFiles() {
    printf("\nCleaning Temporary Files...\n");
    system("del /q /f /s %TEMP%\\*");
    system("cleanmgr");
    printf("Temporary files cleaned.\n");
}

// Optimize Startup Programs Function
void optimizeStartupPrograms() {
    printf("\nOptimizing Startup Programs...\n");
    system("start taskmgr");
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
        system("start https://mishraharshit.vercel.app");
    } else if (choice == 0) {
        printf("Returning to the main menu...\n");
    } else {
        printf("Invalid choice. Returning to the main menu.\n");
    }
}

// Help Section
void showHelp() {
    printf("\nHelp Section\n");
    printf("=====#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
void askUsername();
void logUserInteraction(const char *username);

// Developer Info
#define DEVELOPER "Harshit Mishra"
#define WEBSITE "https://mishraharshit.vercel.app"

// Global Variable for Username
char username[50];

// Main Function
int main() {
    int choice;

    askUsername();

    while (1) {
        showMenu();
        printf("Enter your choice (0-8): ");
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
                printf("Exiting the program. Thank you for using this tool, %s.\n", username);
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

// Ask for Username
void askUsername() {
    printf("Please enter your name: ");
    getchar(); // To consume the newline character left in the input buffer
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0'; // Remove trailing newline character
    printf("Welcome, %s!\n", username);
    logUserInteraction(username);
}

// Log User Interaction
void logUserInteraction(const char *username) {
    FILE *logFile = fopen("user_log.txt", "a");
    if (logFile == NULL) {
        perror("Error opening log file");
        return;
    }

    time_t currentTime = time(NULL);
    char *timestamp = ctime(&currentTime);
    timestamp[strcspn(timestamp, "\n")] = '\0'; // Remove trailing newline character

    fprintf(logFile, "User: %s | Logged in at: %s\n", username, timestamp);
    fclose(logFile);
}

// Display Main Menu
void showMenu() {
    system("cls || clear");
    printf("=============================================\n");
    printf("      Powerful Windows Troubleshooter\n");
    printf("           Developed by %s\n", DEVELOPER);
    printf("           Website: %s\n", WEBSITE);
    printf("=============================================\n");
    printf("Welcome, %s!\n", username);
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
    system("chkdsk /f /r");
    printf("Disk check completed.\n");
}

// Network Diagnostics Function
void runNetworkCheck() {
    printf("\nRunning Network Diagnostics...\n");
    system("ipconfig /flushdns");
    system("netsh int ip reset");
    system("netsh winsock reset");
    printf("Network diagnostics completed. Please restart your computer if necessary.\n");
}

// System File Check Function
void runSystemFileCheck() {
    printf("\nRunning System File Check...\n");
    system("sfc /scannow");
    printf("System file check completed. Check for any messages above.\n");
}

// Clean Temporary Files Function
void cleanTemporaryFiles() {
    printf("\nCleaning Temporary Files...\n");
    system("del /q /f /s %TEMP%\\*");
    system("cleanmgr");
    printf("Temporary files cleaned.\n");
}

// Optimize Startup Programs Function
void optimizeStartupPrograms() {
    printf("\nOptimizing Startup Programs...\n");
    system("start taskmgr");
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
        system("start https://mishraharshit.vercel.app");
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
    printf("=============================================\n");
}

// About Program Section
void aboutProgram() {
    printf("\nAbout This Program\n");
    printf("=============================================\n");
    printf("Developer: %s\n", DEVELOPER);
    printf("Website: %s\n", WEBSITE);
    printf("=============================================\n");
}
=======================================\n");
    printf("This program is a powerful Windows troubleshooter designed to help you diagnose\n");
    printf("and fix common issues on your Windows PC.\n");
    printf("=============================================\n");
}

// About Program Section
void aboutProgram() {
    printf("\nAbout This Program\n");
    printf("=============================================\n");
    printf("Developer: %s\n", DEVELOPER);
    printf("Website: %s\n", WEBSITE);
    printf("=============================================\n");
}
