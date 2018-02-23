// Adam Flammino SDEV385 1/28
// Moves a file in Linux
// Returns 0 if sucessful, -1 if not

// Linux flavor: Arch
// Compiler used: gcc


#include <stdio.h>
#include <stdbool.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PATH_LENGTH 256  // Increase value to allow paths longer than 255 chars

int main ()
{
  char sourcePath[MAX_PATH_LENGTH], sourceName[MAX_PATH_LENGTH], destPath[MAX_PATH_LENGTH], destName[MAX_PATH_LENGTH];
  int writeable;

   printf("Enter path of file you would like to move (do not include file name):\t");
   scanf("%s", sourcePath);
   writeable = access (sourcePath, W_OK);
   if(writeable != 0){ // access returns 0 if writeable
     printf("Source folder not writeable! Please change permissions and try again.\n");
     return -1;
     }
   printf("Enter name of file you would like to moved:\t");
   scanf("%s", sourceName);
   char *fullSourcePath = malloc(strlen(sourcePath)+strlen(sourceName)+2); // Allocates memory for path string
   strcpy(fullSourcePath, sourcePath); // Copy path to full path
   strcat(fullSourcePath,"/"); // Adds / before file name
   strcat(fullSourcePath, sourceName); // Append path with file name
   printf("Enter path of where you would like to move the file to (do not include file name):\t");
   scanf("%s", destPath);
   writeable = access (destPath, W_OK);
   if(writeable != 0){
     printf("Destination folder note writeable! Please change permissions and try again.\n");
     return -1;
   }
   printf("Enter name you would like the file to have after moving:\t");
   scanf("%s", destName);
   char *fullDestPath = malloc(strlen(destPath)+strlen(destName)+2); // Allocates memory for path string
   strcpy(fullDestPath, destPath); // Copy path to full path
   strcat(fullDestPath, "/");
   strcat(fullDestPath, destName); // Append path with file name
   printf("Attempting to move %s to %s\n", fullSourcePath, fullDestPath);
   int exitCode = rename(fullSourcePath, fullDestPath);
   if(exitCode == 0) // rename returns -1 when unsucessful
   {
      printf("File moved successfully\n");
      return 0;
   }
   printf("Error code %d: unable to move the file\n", exitCode);
   return -1;
}
