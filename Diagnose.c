#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Enable define
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif

void enableANSIMode() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    if (hOut == INVALID_HANDLE_VALUE) {
        fprintf(stderr, "Error: Unable to get console handle.\n");
        return;
    }

    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode)) {
        fprintf(stderr, "Error: Unable to get console mode.\n");
        return;
    }

    if (!SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING)) {
        fprintf(stderr, "Error: Unable to set console mode.\n");
    }
}


//function to execute commands
int executeCMDCommand(const char *command) {
    int ret = system(command);
    if (ret == -1) {
        perror("[ERROR] Command execution failed");
    }
    return ret;
}

// Function to print colored messages
void printColoredMessage(const char* message, int r, int g, int b) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole == INVALID_HANDLE_VALUE) {
        printf("%s", message);
        return;
    }
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
    printf("\033[38;2;%d;%d;%dm%s\033[0m", r, g, b, message);
}


// Function to check if the program has admin privileges
int isAdmin() {
    BOOL isAdmin = FALSE;
    HANDLE hToken = NULL;

    // Open the process token and check the elevation
    if (OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &hToken)) {
        TOKEN_ELEVATION elevation;
        DWORD size;

        // Get token information about the elevation level
        if (GetTokenInformation(hToken, TokenElevation, &elevation, sizeof(elevation), &size)) {
            isAdmin = elevation.TokenIsElevated;  // Check if the token has elevated privileges
        }
    }

    // Close the token handle
    if (hToken) {
        CloseHandle(hToken);
    }

    return isAdmin;
}

// Enhanced checkDisk function
void checkDisk() {
    if (!isAdmin()) {
        printColoredMessage("[ERROR] This program requires administrative privileges. Please run as Administrator.\n", 255, 0, 0);
        return;
    }

    char drive[3];
    printColoredMessage("[INPUT] Enter the drive to check (e.g., C:): ", 255, 255, 0);
    scanf("%2s", drive);

    char command[50];
    snprintf(command, sizeof(command), "chkdsk %s /f /r", drive);

    printColoredMessage("\n[INFO] Checking disk for errors. This may take some time...\n", 255, 255, 0);
    int ret = executeCMDCommand(command);

    if (ret == 0) {
        printColoredMessage("[SUCCESS] Disk checked successfully.\n", 0, 255, 0);
    } else {
        printColoredMessage("[ERROR] Disk check failed.\n", 255, 0, 0);
        printColoredMessage("[SOLUTION] Ensure the drive is not in use and run 'chkdsk /f' as Administrator in CMD.\n", 255, 255, 0);
        printColoredMessage("[TIP] You may need to schedule a disk check on reboot for system drives.\n", 255, 255, 0);
    }

    printColoredMessage("[INFO] Task complete. Review the above output for details.\n", 0, 255, 255);
}


// Function to check system files using sfc
void checkSystemFiles() {
    printColoredMessage("\n[INFO] Checking system files...\n", 255, 255, 0);
    int ret = executeCMDCommand("sfc /scannow");
    if (ret == 0) {
        printColoredMessage("[SUCCESS] System files are in good condition.\n", 0, 255, 0);
    } else {
        printColoredMessage("[ERROR] System file integrity check failed.\n", 255, 0, 0);
        printColoredMessage("[SOLUTION] Ensure the system has sufficient disk space and try again.\n", 255, 255, 0);
    }
}

// Function to check network connectivity
void checkNetwork() {
    printColoredMessage("\n[INFO] Checking network connectivity...\n", 255, 255, 0);
    int ret = executeCMDCommand("ping -n 3 google.com");
    if (ret == 0) {
        printColoredMessage("[SUCCESS] Network is connected.\n", 0, 255, 0);
    } else {
        printColoredMessage("[ERROR] Network connectivity issue detected.\n", 255, 0, 0);
        printColoredMessage("[SOLUTION] Check your internet connection, router settings, or firewall.\n", 255, 255, 0);
    }
}

// Function to check for Windows Update issues
void checkWindowsUpdate() {
    printColoredMessage("\n[INFO] Checking Windows Update...\n", 255, 255, 0);
    int ret = executeCMDCommand("powershell -Command \"Get-WindowsUpdateLog\"");
    if (ret == 0) {
        printColoredMessage("[SUCCESS] Windows Update log checked.\n", 0, 255, 0);
    } else {
        printColoredMessage("[ERROR] Failed to check Windows Update log.\n", 255, 0, 0);
        printColoredMessage("[SOLUTION] Run 'Get-WindowsUpdateLog' in an elevated PowerShell.\n", 255, 255, 0);
    }
}

// Function to clear temporary files
void clearTempFiles() {
    printColoredMessage("\n[INFO] Clearing temporary files...\n", 255, 255, 0);
    int ret = executeCMDCommand("del /q /f /s %TEMP%\\*");
    if (ret == 0) {
        printColoredMessage("[SUCCESS] Temporary files cleared.\n", 0, 255, 0);
    } else {
        printColoredMessage("[ERROR] Failed to clear temporary files.\n", 255, 0, 0);
        printColoredMessage("[SOLUTION] Run 'cleanmgr' or manually delete files in the Temp folder.\n", 255, 255, 0);
    }
}

// Function to check disk space
void checkDiskSpace() {
    printColoredMessage("\n[INFO] Checking disk space...\n", 255, 255, 0);
    int ret = executeCMDCommand("wmic logicaldisk get size,freespace,caption");
    if (ret == 0) {
        printColoredMessage("[SUCCESS] Disk space checked successfully.\n", 0, 255, 0);
    } else {
        printColoredMessage("[ERROR] Failed to check disk space.\n", 255, 0, 0);
        printColoredMessage("[SOLUTION] Use 'This PC' to manually view disk space.\n", 255, 255, 0);
    }
}

// Function to check CPU temperature (requires additional tools)
void checkCPUTemperature() {
    printColoredMessage("\n[INFO] Checking CPU temperature...\n", 255, 255, 0);
    int ret = executeCMDCommand("wmic /namespace:\\\\root\\wmi path MSAcpi_ThermalZoneTemperature get CurrentTemperature");
    if (ret == 0) {
        printColoredMessage("[SUCCESS] CPU temperature checked.\n", 0, 255, 0);
    } else {
        printColoredMessage("[ERROR] Failed to check CPU temperature.\n", 255, 0, 0);
        printColoredMessage("[SOLUTION] Use third-party tools like HWMonitor or CoreTemp.\n", 255, 255, 0);
    }
}

// Function to check Windows Defender status
void checkDefenderStatus() {
    printColoredMessage("\n[INFO] Checking Windows Defender status...\n", 255, 255, 0);
    int ret = executeCMDCommand("powershell Get-MpComputerStatus");
    if (ret == 0) {
        printColoredMessage("[SUCCESS] Windows Defender status checked.\n", 0, 255, 0);
    } else {
        printColoredMessage("[ERROR] Failed to check Windows Defender status.\n", 255, 0, 0);
        printColoredMessage("[SOLUTION] Verify that Windows Defender is enabled.\n", 255, 255, 0);
    }
}

// Function to check for application errors (Event Viewer)
void checkAppErrors() {
    printColoredMessage("\n[INFO] Checking application errors...\n", 255, 255, 0);
    int ret = executeCMDCommand("eventvwr.msc");
    if (ret == 0) {
        printColoredMessage("[SUCCESS] Application errors checked.\n", 0, 255, 0);
    } else {
        printColoredMessage("[ERROR] Failed to open Event Viewer.\n", 255, 0, 0);
        printColoredMessage("[SOLUTION] Open Event Viewer manually to check for application errors.\n", 255, 255, 0);
    }
}

// Function to check Windows Firewall status
void checkFirewallStatus() {
    printColoredMessage("\n[INFO] Checking firewall status...\n", 255, 255, 0);
    int ret = executeCMDCommand("netsh advfirewall show allprofiles state");
    if (ret == 0) {
        printColoredMessage("[SUCCESS] Firewall status checked.\n", 0, 255, 0);
    } else {
        printColoredMessage("[ERROR] Failed to check firewall status.\n", 255, 0, 0);
        printColoredMessage("[SOLUTION] Verify firewall settings manually via Control Panel.\n", 255, 255, 0);
    }
}


// Main program
int main() {
       int choice;                                         
       do{

    SetConsoleTitle("Windows 10/11 Diagnostics Tool");

    printColoredMessage("**********************************************\n", 0, 255, 255);
    printColoredMessage("     Windows 10/11 Diagnostics Tool By Harshit Mishra\n", 0, 255, 255);
    printColoredMessage("**********************************************\n", 0, 255, 255);
    printColoredMessage("\n[INFO] Starting diagnostics...\n", 255, 255, 0);
  
    printf("Choose an Operation\n");
    printf("01. Check Disk\n");
    printf("02. Check System Files\n");
    printf("03. Check Network Issue\n");
    printf("04. Check windows update Issue\n");
    printf("05. Clear temporary\n");
    printf("06. Check Disk Space\n");
    printf("07. Check CPU Temperature\n");
    printf("08. Check Defender Status (Malware test)\n");
    printf("09. Check App error's\n");
    printf("10. Check Firewall Status\n");
    printf("11. Run Advance Checkup\n");
    printf("12. Help\n");
    printf("We are working on this project\n");
    printf("0.  Exit\n");
    printf("\n Enter Your Choice\n");
    scanf("%d", &choice);
    switch(choice){
          case 1: checkDisk(); 
          break;

          case 2: checkSystemFiles();
          break;

          case 3: checkNetwork();
          break;

          case 4: checkWindowsUpdate();
          break;

          case 5: clearTempFiles();
          break;

          case 6: checkDiskSpace();
          break;

          case 7: checkCPUTemperature();
          break;

          case 8: checkDefenderStatus();
          break;

          case 9: checkAppErrors();
          break;

          case 10: checkFirewallStatus();
          break;

          case 11:
              checkDisk();
              checkSystemFiles();
              checkNetwork();
              checkWindowsUpdate();
              clearTempFiles();
              checkDiskSpace();
              checkCPUTemperature();
              checkDefenderStatus();
              checkAppErrors();
              checkFirewallStatus();
              break;

          case 12: printColoredMessage("Welcome To Help Section This is Harshit Mishra\n",0, 255, 255);
                   printColoredMessage("This Is the windows diagnostics software I devloped for checking solving your computer problems\n",0, 255, 255);
                   printColoredMessage("It is just like a doctor who checks computer nurves and find diseas and try to fix them.\n",0, 255, 255);
                   printColoredMessage("Simple to use just type A number of operation you want to perform\n",0, 255, 255);
                   printColoredMessage("Like if you want to check disk just type number 1\n",0, 255, 255);
                   printColoredMessage("If you want to Run all test at once just type 11\n",0, 255, 255);
                   break;

          case 0: printColoredMessage("Good bye exiting.........\n\n",0, 255, 255);
          break;

          default: printColoredMessage("Wrong Input please enter valid number of command\n",0, 255, 255);       
    }

    printColoredMessage("\nDiagnostics completed.\n", 255, 255, 255);
    printColoredMessage("**********************************************\n", 0, 255, 255);
    printColoredMessage("[INFO] If issues persist, refer to the solutions provided.\n", 255, 255, 0);
    printColoredMessage("**********************************************\n", 0, 255, 255);
       }while(choice != 0);
    return 0;
}
