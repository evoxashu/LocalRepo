#include <stdio.h>

int main() {
    FILE *file1, *file2, *upperFile;
    char text[1000], secondFileName[100];
    char content[1000];
    int i, length;
    int ch1, ch2;
    int same = 1;

    printf("Enter a string to write into a file: ");
    fgets(text, sizeof(text), stdin);

    /* Remove newline character */
    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] == '\n') {
            text[i] = '\0';
            break;
        }
    }

    /* Write string into file */
    file1 = fopen("file1.txt", "w");

    if (file1 == NULL) {
        printf("Unable to create file.\n");
        return 1;
    }

    fputs(text, file1);
    fclose(file1);

    printf("String written to file1.txt.\n");

    /* Print file contents in reverse order */
    file1 = fopen("file1.txt", "r");

    length = 0;

    while ((ch1 = fgetc(file1)) != EOF) {
        content[length] = ch1;
        length++;
    }

    fclose(file1);

    printf("\nFile contents in reverse order:\n");

    for (i = length - 1; i >= 0; i--)
        putchar(content[i]);

    /* Compare two files */
    printf("\n\nEnter the name of another file: ");
    scanf("%s", secondFileName);

    file1 = fopen("file1.txt", "r");
    file2 = fopen(secondFileName, "r");

    if (file1 == NULL || file2 == NULL) {
        printf("Unable to open files.\n");
    } else {
        while (1) {
            ch1 = fgetc(file1);
            ch2 = fgetc(file2);

            if (ch1 != ch2) {
                same = 0;
                break;
            }

            if (ch1 == EOF && ch2 == EOF)
                break;
        }

        if (same)
            printf("Both files have the same contents.\n");
        else
            printf("Files have different contents.\n");

        fclose(file1);
        fclose(file2);
    }

    /* Convert lowercase letters to uppercase */
    file1 = fopen("file1.txt", "r");
    upperFile = fopen("uppercase.txt", "w");

    while ((ch1 = fgetc(file1)) != EOF) {
        if (ch1 >= 'a' && ch1 <= 'z')
            ch1 = ch1 - 32;

        fputc(ch1, upperFile);
    }

    fclose(file1);
    fclose(upperFile);

    printf("Uppercase contents saved in uppercase.txt.\n");

    return 0;
}