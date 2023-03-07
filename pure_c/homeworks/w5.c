#include <stdlib.h>
#include <stdio.h>

size_t count_entries(FILE *fp);
void read_weights(int size, FILE *fp);
void average_weight(int size, FILE *fp);

int main(void)
{
    const char fname[] = "data_h5.txt";

    FILE *fp = fopen(fname, "r");

    size_t entries = count_entries(fp);
    
    average_weight(entries, fp);
}

void average_weight(int size, FILE *fp){
    double average = 0.0;
    int weight;
    while (fscanf(fp, "%d", &weight) == 1)
    {
        average += weight;
    }
    fclose(fp);
    average /= size;
    printf("Average weight: %0.3lf",average);
}

size_t count_entries(FILE *fp){
    // Count Lines
    char cr;
    size_t  lines = 0;

    while (cr != EOF)
    {
        if (cr == '\t')
        {
            lines++;
        }
        cr = getc(fp);
    }
    printf("Number of entries: %ld\n", lines);
    rewind(fp);
    return lines;
}