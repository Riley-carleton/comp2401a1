#include <stdio.h>

// These are defined values.
// They do not reserve memory like a variable.
// Instead, the first phase of building - "pre-processing"
// Will essentially find-and-replace with what is written to the right.
// You should define some yourself to avoid "magic numbers",
// unchanging numbers that might need explanation or appear multiple times.
// It's a bit like commenting the value.
#define MAX_ENTRIES 16
#define ERR_OK 0
#define ERR_INVALID_DURATION  -2
#define ERR_INVALID_ID -3

// These are "forward declarations".
// It tells the rest of the code to expect to find a function
// that works like this somewhere once we compile and link our code.
// We will NOT put the body of the function here, to keep things clean.
// Instead, we will leave this forward declaration untouched, 
// and define the functions in another file: `logs.c`.
// These are like promises; "When I link other files, you'll find them"
int input_logs(int ids[], float durations[], int views[]);
int print_logs(int ids[], float durations[], int views[], int size);
int remove_duplicates(int ids[], float durations[], int views[], int size);
int invalid_id(int id);
int invalid_duration(float reading);

int main(void) {
    // Define your variables and call the functions from logs.c here
    int ids[MAX_ENTRIES];
    int views[MAX_ENTRIES];
    float durations[MAX_ENTRIES];
    int size = input_logs(ids, durations, views);
    print_logs(ids, durations, views, size);
    return 0;
}


