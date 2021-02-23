#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 30

typedef struct Letters
{
    char letter;
    int frequency;

}Letter;

int control(const char *text, int size, int location);
int frequencyC(const char *text, int size, int location);
void print(int j);

Letter ** arr;

int main()
{
    int size = 0, j = 0;;
    printf("Enter the text you want to see the character frequency output.\n\n");
    char text[SIZE];
    gets(text);
    size = strlen(text);
    for(int i = 0; i < size; i++)
    {
        if(!i)
        {
            arr = malloc(sizeof(Letter *));
            arr[j] = malloc(sizeof(Letter));
            arr[j]->letter = text[i];
            arr[j]->frequency = frequencyC(text, size, i);
            j++;
        }
        else
        {
            if(control(text, j, i))
            {
                arr = realloc(arr, sizeof(Letter *) * (j + 1));
                arr[j] = malloc(sizeof(Letter));
                arr[j]->letter = text[i];
                arr[j]->frequency = frequencyC(text, size, i);
                j++;
            }
        }
    }
    print(j);
    return 0;
}

void print(int j)
{
    for(int i = 0; i < j; i++)
        printf("Character: '%c', Frequency: %d\n", arr[i]->letter, arr[i]->frequency);
}

int control(const char *text, int size, int location)
{
    for(int i = 0; i < size; i++)
    {
        if(text[location] == arr[i]->letter || text[location] == (arr[i]->letter + 32) || (text[i] + 32) == arr[i]->letter)
            return 0;
    }
    return 1;
}

int frequencyC(const char *text, int size, int location)
{
    int count = 0;
    for(int i = 0; i < size; i++)
    {
        if(text[location] == text[i] || text[location] == (text[i] + 32) || (text[location] + 32) == text[i])
            count++;
    }
    return count;
}

/*
input:
ARTificial INtelligence DILE

output:
Character: 'A', Frequency: 2
Character: 'R', Frequency: 1
Character: 'T', Frequency: 2
Character: 'i', Frequency: 6
Character: 'f', Frequency: 1
Character: 'c', Frequency: 2
Character: 'l', Frequency: 4
Character: ' ', Frequency: 2
Character: 'I', Frequency: 6
Character: 'N', Frequency: 2
Character: 'e', Frequency: 4
Character: 'g', Frequency: 1
Character: 'D', Frequency: 1
Character: 'L', Frequency: 4
Character: 'E', Frequency: 4
*/
