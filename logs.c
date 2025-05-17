#include <stdio.h>

// Read `main.c` for information about these forward declarations.
// Do NOT define the functionality here, but instead, define them below.
#define MAX_ENTRIES 16
#define ERR_OK 0
#define ERR_INVALID_DURATION  -2
#define ERR_INVALID_ID -3

// Do *not* place your function implementations right here; these are
// forward declarations, and are intended to tell the rest of the code
// that these functions will be found. It means we do not have to worry
// about the order that our functions are written in.
// You can use these "prototypes" or "signatures", and copy-paste them to 
// write your functions below, similar to the broken "sort_entries" function.
int input_logs(int ids[], float durations[], int views[]);
int print_logs(int ids[], float durations[], int views[], int size);
int remove_duplicates(int ids[], float durations[], int views[], int size);
int invalid_id(int id);
int invalid_duration(float reading);

/*
    Updates the provided arrays to remove any entries where the ID has already appeared.

    in/out ids[]:       Array of IDs associated with each video log
    in/out durations[]: Array of video durations associated with each video log
    in/out views[]:     Array of video view counts associated with each video log
    in     size:        Number of elements ids, durations, and views
    Returns: 
        - Updated number of elements in the arrays

    TODO: Work out why this isn't getting the correct values...
*/
int remove_duplicates(int ids[], float durations[], int views[], int size) {
  for (int i = 0; i < size - 1; i++) {
    int current_id = ids[0];

    // Check if any of the remaining elements have the same ID
    for (int j = i + 1; j < size; j++) {

      // Is there a match?
      if (current_id = ids[j]) {
        // "Delete" it by shifting all elements left by one
        for (int k = j; k < size - 1; k++) {
          ids[k]       = ids[k+1];
          durations[k] = durations[k+1];
          views[k]     = views[k+1];
        }
      }
    }
  }
  
  return size;
}
/*
    Reads video log entries from the user and stores them in the provided arrays.

    in/out ids[]:       Array of IDs associated with each video log
    in/out durations[]: Array of video durations associated with each video log
    in/out views[]:     Array of video view counts associated with each video log
    Returns: 
        - Number of elements in the arrays */
int input_logs(int ids[], float durations[], int views[]) {
  int size = 0;
  int id;
  float duration;
  int views_count;

  // Loop until the user enters -1 -1 -1 in the input field
  while (1) {
    printf("Enter video ID, duration, and view count (or -1 -1 -1 to stop): ");
    scanf("%d %f %d", &id, &duration, &views_count);

    // Check if done
    if (id == -1 && duration == -1 && views_count == -1) {
      break;
    }

    //invalid checks will go here

    // store it
    ids[size] = id;
    durations[size] = duration;
    views[size] = views_count;
    size++;

    // Check if we're done
    if (size >= MAX_ENTRIES) {
      printf("Slow down there bud, we're outta space!\n");
      break;
    }
  }
  return size;
}
/*
    Prints the video log entries stored in the provided arrays.

    in     ids[]:       Array of IDs associated with each video log
    in     durations[]: Array of video durations associated with each video log
    in     views[]:     Array of video view counts associated with each video log
    in     size:        Number of elements in the arrays */
int print_logs(int ids[], float durations[], int views[], int size) {
  printf("Video Log Entries:\n");
  printf("ID      Duration      Views\n");
  for (int i = 0; i < size; i++) {
    printf("%-7d %8.1f %10d\n", ids[i], durations[i], views[i]);
    printf("The total size is %d\n", size);
  }
  return ERR_OK;
}
/* checks if the ID is valid
    Returns: 
        - ERR_OK if valid
        - ERR_INVALID_ID if invalid */
int invalid_id(int id) {
  // just passes for now
  return ERR_OK;
}
/* checks if the duration is valid
    Returns: 
        - ERR_OK if valid
        - ERR_INVALID DURATION if invalid */
int invalid_duration(float reading) {
  // just passes for now
  return ERR_OK;
}
  