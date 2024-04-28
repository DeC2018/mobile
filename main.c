#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person_t {
    char * name;
    int phone;
} person_t;

int namecmp(const void* a, const void* b);
int phonecmp(const void* a, const void* b);

int main(void)
{
    char name[1000];
    person_t *base;
    int n, i, phone;
    scanf("%d", &n);
    base = malloc(n * sizeof(person_t));


    for(i = 0 ; i < n ; i++)
    {
        scanf("%s%d", name, &phone);

        base[i].name = malloc((strlen(name)+1) * sizeof(char));
        strcpy(base[i].name, name);
        base[i].phone = phone;
    }

    qsort(base, n, sizeof(person_t), namecmp);

    for(i = 0 ; i < n ; i++)
    {
        printf("%20s %d\n", base[i].name, base[i].phone);
    }


    qsort(base, n, sizeof(person_t), phonecmp);

    for(i = 0 ; i < n ; i++)
    {
        printf("%20s %d\n", base[i].name, base[i].phone);
    }

    for(i = 0 ; i < n ; i++)
    {
        free(base[i].name);
    }
    free(base);

    return 0;

}

int namecmp(const void* a, const void* b) {
    const char* const* pa = (const char* const*)a;
    const char* const* pb = (const void*)b;
    return strcmp(*pa, *pb);
}

int phonecmp(const void* a, const void* b)
{
    person_t *pa = a;
    person_t *pb = b;
    return pa->phone - pb->phone;
}
