#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

void system_call_operations() {
    int fd_read, fd_write;
    char buffer[100];

    // Open a file for reading using system call
    fd_read = open("C:\\Users\\kavan\\DBMS_CODE\\input.txt", O_RDONLY);
    if (fd_read == -1) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }

    // Open a file for writing using system call
    fd_write = open("C:\\Users\\kavan\\DBMS_CODE\\output.txt", O_CREAT | O_WRONLY, 0644);
    if (fd_write == -1) {
        perror("Error opening file for writing");
        close(fd_read);
        exit(EXIT_FAILURE);
    }

    // Read from the file using system call
    ssize_t bytes_read;
    while ((bytes_read = read(fd_read, buffer, sizeof(buffer))) > 0) {
        if (write(fd_write, buffer, bytes_read) == -1) {
            perror("Error writing to file");
            close(fd_read);
            close(fd_write);
            exit(EXIT_FAILURE);
        }
    }
    if (bytes_read == -1) {
        perror("Error reading from file");
        close(fd_read);
        close(fd_write);
        exit(EXIT_FAILURE);
    }

    printf("Data successfully copied from input.txt to output.txt using system calls.\n");

    // Close the files using system call
    if (close(fd_read) == -1) {
        perror("Error closing read file");
        exit(EXIT_FAILURE);
    }
    if (close(fd_write) == -1) {
        perror("Error closing write file");
        exit(EXIT_FAILURE);
    }
}

void file_library_operations() {
    FILE *file_read, *file_write;
    char buffer[100];

    // Open a file for reading using file library
    file_read = fopen("input.txt", "r");
    if (file_read == NULL) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }

    // Open a file for writing using file library
    file_write = fopen("output_lib.txt", "w");
    if (file_write == NULL) {
        perror("Error opening file for writing");
        fclose(file_read);
        exit(EXIT_FAILURE);
    }

    // Read from the file using file library
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file_read)) > 0) {
        if (fwrite(buffer, 1, bytes_read, file_write) != bytes_read) {
            perror("Error writing to file");
            fclose(file_read);
            fclose(file_write);
            exit(EXIT_FAILURE);
        }
    }
    if (ferror(file_read)) {
        perror("Error reading from file");
        fclose(file_read);
        fclose(file_write);
        exit(EXIT_FAILURE);
    }

    printf("Data successfully copied from input.txt to output_lib.txt using file library.\n");

    // Close the files using file library
    if (fclose(file_read) != 0) {
        perror("Error closing read file");
        exit(EXIT_FAILURE);
    }
    if (fclose(file_write) != 0) {
        perror("Error closing write file");
        exit(EXIT_FAILURE);
    }
}

int main() {
    printf("Demonstrating system call operations:\n");
    system_call_operations();
    printf("\nDemonstrating file library operations:\n");
    file_library_operations();
    return 0;
}
