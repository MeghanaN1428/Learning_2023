#include <stdio.h>

struct Time {
    int hours;
    int minutes;
    int seconds;
};

void getTimeDifference(struct Time startTime, struct Time endTime, struct Time* diffTime) {
    int totalStartSeconds, totalEndSeconds, diffSeconds;

    totalStartSeconds = startTime.hours * 3600 + startTime.minutes * 60 + startTime.seconds;
    totalEndSeconds = endTime.hours * 3600 + endTime.minutes * 60 + endTime.seconds;

    diffSeconds = totalEndSeconds - totalStartSeconds;

    diffTime->hours = diffSeconds / 3600;
    diffTime->minutes = (diffSeconds % 3600) / 60;
    diffTime->seconds = (diffSeconds % 3600) % 60;
}

int main() {
    struct Time startTime, endTime, diffTime;

    printf("Enter start time:\n");
    printf("Hours: ");
    scanf("%d", &startTime.hours);
    printf("Minutes: ");
    scanf("%d", &startTime.minutes);
    printf("Seconds: ");
    scanf("%d", &startTime.seconds);

    printf("Enter end time:\n");
    printf("Hours: ");
    scanf("%d", &endTime.hours);
    printf("Minutes: ");
    scanf("%d", &endTime.minutes);
    printf("Seconds: ");
    scanf("%d", &endTime.seconds);

    getTimeDifference(startTime, endTime, &diffTime);

    printf("\nDifference between the two time periods:\n");
    printf("Hours: %d\n", diffTime.hours);
    printf("Minutes: %d\n", diffTime.minutes);
    printf("Seconds: %d\n", diffTime.seconds);

    return 0;
}