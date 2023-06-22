#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

// Structure to hold log entry data
struct LogEntry {
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char timestamp[10];
};

// Function to read data from data.csv and store it in an array of structures
void read_log_entries(struct LogEntry logEntries[], int* numEntries) {
    FILE* file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Skip the header row
    char buffer[1024];
    fgets(buffer, sizeof(buffer), file);

    *numEntries = 0;
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        struct LogEntry entry;
        sscanf(buffer, "%d,%[^,],%f,%d,%d,%[^,\n]",
               &entry.entryNo,
               entry.sensorNo,
               &entry.temperature,
               &entry.humidity,
               &entry.light,
               entry.timestamp);

        logEntries[*numEntries] = entry;
        (*numEntries)++;

        if (*numEntries >= MAX_ENTRIES) {
            printf("Maximum number of entries reached.\n");
            break;
        }
    }

    fclose(file);
}

// Function to display the contents of the array of structures
void display_log_entries(struct LogEntry logEntries[], int numEntries) {
    printf("EntryNo\tSensorNo\tTemperature\tHumidity\tLight\tTimestamp\n");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < numEntries; i++) {
        printf("%d\t%s\t\t%.1f\t\t%d\t\t%d\t%s\n",
               logEntries[i].entryNo,
               logEntries[i].sensorNo,
               logEntries[i].temperature,
               logEntries[i].humidity,
               logEntries[i].light,
               logEntries[i].timestamp);
    }
}

int main() {
    struct LogEntry logEntries[MAX_ENTRIES];
    int numEntries = 0;

    read_log_entries(logEntries, &numEntries);
    display_log_entries(logEntries, numEntries);

    return 0;
}