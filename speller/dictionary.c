// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include<stdlib.h>
#include <stdio.h>
#include<string.h>
#include<strings.h>

#include "dictionary.h"
bool loaded = false;
unsigned int diccounter = 0;
// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 676;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{

    node *ptr = table[hash(word)];
    while (ptr != NULL)
    {

        if (strcasecmp(word, ptr->word) == 0)
        {
            return true;
        }
        ptr = ptr->next;
    }

    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A'+ toupper(word[1]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    int charcounter;
    FILE *dic = fopen(dictionary, "r");
    if (dic == NULL)
    {
        return false;
    }
    int buffer;
    int hashed;
    while ((buffer = fgetc(dic)) != EOF)
    {
        charcounter = 0;
        node *new = malloc(sizeof(node));
        if (new == NULL)
        {
            return false;
        }
        do
        {
            new->word[charcounter] = (char)buffer;
            charcounter++;
        }
        while ((buffer = fgetc(dic)) != '\n' && buffer != EOF);
        new->word[charcounter] = '\0';
        diccounter++;
        hashed = hash(new->word);

        if (table[hashed] == NULL)
        {
            table[hashed] = new;
            new->next = NULL;
        }
        else
        {
            new->next = table[hashed];
            table[hashed] = new;
        }
    }
    loaded = true;
    fclose(dic);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    if (loaded)
    {
        return diccounter;
    }
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *crs = table[i];
        node *tmp;
        while(crs != NULL)
        {
            tmp = crs;
            crs = crs->next;
            if(tmp == NULL)
            {
                return false;
            }
            free(tmp);

        }
    }
    // TODO
    return true;
}
