#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int size = 0;
    char *text = "2a98Fa- tTa_?)2*at 9-9_9Ff8*?";
    size = strlen(text);
    int j = 0;

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
        if(text[location] == arr[i]->letter)
            return 0;
    }
    return 1;
}

int frequencyC(const char *text, int size, int location)
{
    int count = 0;
    for(int i = 0; i < size; i++)
    {
        if(text[location] == text[i])
            count++;
    }
    return count;
}

/*
output:
Character: '2', Frequency: 2
Character: 'a', Frequency: 4
Character: '9', Frequency: 4
Character: '8', Frequency: 2
Character: 'F', Frequency: 2
Character: '-', Frequency: 2
Character: ' ', Frequency: 2
Character: 't', Frequency: 2
Character: 'T', Frequency: 1
Character: '_', Frequency: 2
Character: '?', Frequency: 2
Character: ')', Frequency: 1
Character: '*', Frequency: 2
Character: 'f', Frequency: 1
*/
