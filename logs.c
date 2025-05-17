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