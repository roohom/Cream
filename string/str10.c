// str10.c
// Created by roohom on 2018/11/14.
// 2018/11/14 19:37

//二分法搜索
// 1.设定low为0，high为n-1；
// 2.若low>high，则x不在M中，算法终止。
// 3.设定mid为(low+high)/2.
// 4.若M[mid]<x,设定low为mid+1，并返回步骤2.
// 5.如M[mid]<x,设定low为mid-1,并返回步骤2.
// 6.M[mid]等于x，算法结束。


#include <stdbool.h>
#include <stdio.h>

struct entry
{
    char word[15];
    char definition[50];
};

int compareString(const char str1[], const char str2[])
{
    int i=0, anwser;
    
    while(str1[i] == str2[i] && str1[i] != '\0' && str2[i] !='\0')
        ++i;
    if(str1[i]<str2[i])
    {
        anwser = -1;
    }
    else if(str1[i]==str2[i])
        anwser = 0;
    else
        anwser =1;

    return anwser;
}

int lookUp(const struct entry dictionary[], const char search[], const int entries)
{
    int low=0;
    int high = entries-1;
    int mid,result;
    
    while(low<=high)
    {
        mid = (low+high)/2;
        result = compareString(dictionary[mid].word,search);
        
        if(result == -1)
        {
            low = mid+1;
        }
        else if(result==1)
            high = mid-1;
        else
            return mid;
    }

    return -1;
}


int main(void)
{
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
    
    int entries = 10;
    int word[15];
    int entry;

    printf("ENTER WORD:");
    scanf("%14s" , word);
    entry = lookUp(dictionary, word, entries);

    if(entry != -1)
    {
        printf("%s\n",dictionary[entry].definition);
    }
    else
    {
        printf("Sorry, the word %s you key in is not in the dictionary.\n",word);
    }

}