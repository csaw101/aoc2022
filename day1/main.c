#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *stream;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    int calorie_count = 0;
    int max_calories = 0;

    stream = fopen("input.txt", "r");
    if (stream == NULL) {
        printf("NO FILE!");
        return 1;
    }

    while ((nread = getline(&line, &len, stream)) != -1) {
        calorie_count += atoi(line);
        if (strcmp(line, "\n") == 0) {
            if (calorie_count > max_calories) max_calories = calorie_count;
            calorie_count = 0;
        }
    }

    free(line);
    fclose(stream);

    printf("%d\n", max_calories);

    return 0;
}
