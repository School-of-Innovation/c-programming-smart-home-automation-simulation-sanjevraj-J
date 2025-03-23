#include <stdio.h>
#define MAX_ROOMS 5  // Maximum number of rooms

// Arrays to store states
int lights[MAX_ROOMS];
int temperatures[MAX_ROOMS];
int motionSensors[MAX_ROOMS];
int locks[MAX_ROOMS];

// Function prototypes
void initializeSystem();
void displayMenu();
void controlLights();
void readTemperature();
void detectMotion();
void securitySystem();
void analyzeHouseStatus();

int main() {
    initializeSystem();
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                controlLights();
                break;
            case 2:
                readTemperature();
                break;
            case 3:
                detectMotion();
                break;
            case 4:
                securitySystem();
                break;
            case 5:
                analyzeHouseStatus();
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

// Initialize the system with default values
void initializeSystem() {
    for (int i = 0; i < MAX_ROOMS; i++) {
        lights[i] = 0;            // All lights OFF
        temperatures[i] = 22 + i; // Example temperatures (22°C, 23°C, ...)
        motionSensors[i] = 0;     // No motion detected
        locks[i] = 1;             // All doors locked
    }
    printf("System initialized successfully!\n\n");
}

// Display the menu
void displayMenu() {
    printf("\n===== Smart Home Automation System =====\n");
    printf("1. Toggle Lights\n");
    printf("2. Read Temperature\n");
    printf("3. Check Motion Sensor\n");
    printf("4. Lock/Unlock Security System\n");
    printf("5. House Status Summary\n");
    printf("6. Exit\n");
}

// Control the lights for a room
void controlLights() {
    int room;
    printf("Enter room number to toggle light (1-%d): ", MAX_ROOMS);
    scanf("%d", &room);

    if (room >= 1 && room <= MAX_ROOMS) {
        lights[room - 1] = !lights[room - 1]; // Toggle light
        printf("Light in Room %d is now %s.\n", room, lights[room - 1] ? "ON" : "OFF");
    } else {
        printf("Invalid room number!\n");
    }

}

// Read temperature of a room
void readTemperature() {
    int room;
    printf("Enter room number to read temperature (1-%d): ", MAX_ROOMS);
    scanf("%d", &room);

    if (room >= 1 && room <= MAX_ROOMS) {
        printf("Temperature in Room %d: %d°C\n", room, temperatures[room - 1]);
    } else {
        printf("Invalid room number!\n");
    }
}

// Check motion sensor status for all rooms
void detectMotion() {
    int room;
    printf("Enter room number to check motion (1-%d): ", MAX_ROOMS);
    scanf("%d", &room);

    if (room >= 1 && room <= MAX_ROOMS) {
        printf("Motion in Room %d: %s\n", room, motionSensors[room - 1] ? "Detected" : "No Motion");
    } else {
        printf("Invalid room number!\n");
    }
}

// Lock or unlock the security system
void securitySystem() {
    int room;
    printf("Enter room number to lock/unlock (1-%d): ", MAX_ROOMS);
    scanf("%d", &room);

    if (room >= 1 && room <= MAX_ROOMS) {
        locks[room - 1] = !locks[room - 1]; // Toggle lock
        printf("Room %d is now %s.\n", room, locks[room - 1] ? "Locked" : "Unlocked");  
    } else {
        printf("Invalid room number!\n");
    }
}

// Analyze and display the house status
void analyzeHouseStatus() {
    printf("\n===== House Status Summary =====\n");

    for (int i = 0; i < MAX_ROOMS; i++) {
        printf("Room %d: Light %s, Temp %d°C, Motion %s, %s\n",
               i + 1,
               lights[i] ? "ON" : "OFF",
               temperatures[i],
               motionSensors[i] ? "Detected" : "No Motion",
               locks[i] ? "Locked" : "Unlocked");
    }
}
