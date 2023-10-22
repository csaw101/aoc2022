#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *stream;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    int counter = 0;
    int calories = 0;

    stream = fopen("input.txt", "r");
    if (stream == NULL) {
        printf("NO FILE");
        return 1;
    }
    while ((nread = getline(&line, &len, stream)) != -1) {
        counter += atoi(line);
        if (strcmp(line, "\n") == 0) {
            if (counter > calories) calories = counter;
            counter = 0;
        }
    }

    free(line);
    fclose(stream);

    printf("%d\n", calories);

    return 0;
}
