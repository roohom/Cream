// str09.c
// Created by roohom on 2018/11/14.
// 2018/11/14 19:10

#include <stdio.h>
#include <stdbool.h>

struct entry
{
    char word[15];
    char definition[50];
};

bool equalString(const char str1[], const char str2[])
{
    int i=0;
    bool equalFlag;

    while(str1[i]==str2[i] && str1[i] !='\0' && str2[i] != '\0')
    {
        ++i;
    }
    if(str1[i] == '\0' && str2[i] == '\0')
    {
        equalFlag = true;
    }
    else
    {
        equalFlag = false;
    }
    return equalFlag;
}


int lookUp(const struct entry dictionary[], const char search[], const char entries)
{
    int i;

    for(i=0;i<entries;++i) {
        if (equalString(search, dictionary[i].word))
            return i;
    }
    return -1;
}

int main(void) {
    const struct entry dictionary[100] =
            {{"aardvark", "a burrowing African mammal"},
             {"abyss",    "a bottomless pit"},
             {"acumen",   "mentally sharp;keen"},
             {"addle",    "to become confused"},
             {"aerie",    "a high nest"},
             {"affix",    "to append;attach"},
             {"agar",     "a jelly made from seaweed"},
             {"ahoy",     "a nautical call of greeting"},
             {"aigrette", "an ornamental cluster of feathers"},
             {"ajar",     "partially opened"}};

    char word[10];
    int entries = 10;
    int entry;

    printf("ENTER WORD:\n");
    scanf("%14s",word);
    entry = lookUp(dictionary,word, entries);

    if(entry != -1)
    {
        printf("%s\n",dictionary[entry].definition);
    }
    else
    {
        printf("Sorry, the word %s you key in is not in the dictionary.\n",word);
    }


}