# include "../hash_table.h"
# include <stdint.h>
# include <stdio.h>

int main()
{
	printf("Starting tests.\n\n");

	printf("Try to initialize a hash table\n");
	struct htable *table = create_htable(10);

	printf("Try to add 5  values in the hash table\n");
    int *a = malloc(sizeof(int));
    *a = 2;
    int *b = malloc(sizeof(int));
    *b = 3;
    int *c = malloc(sizeof(int));
    *c = 26;
    int *d = malloc(sizeof(int));
    *d = 25965;
    int *e = malloc(sizeof(int));
    *e = 5;
    printf("Adding 'toto' to the htable -> ");
    int ares = add_htable(table, "toto", a);
    if (ares != 0)
    {
        printf("OK !\n");
    }
    else
    {
        printf("KO...\n");
    }
    printf("Adding 'tata' to the htable -> ");
    int bres = add_htable(table, "tata", b);
    if (bres != 0)
    {
        printf("OK !\n");
    }
    else
    {
        printf("KO...\n");
    }
    printf("Adding 'tutu' to the htable -> ");
    int cres = add_htable(table, "tutu", c);
    if (cres != 0)
    {
        printf("OK !\n");
    }
    else
    {
        printf("KO...\n");
    }
    printf("Adding 'titi' to the htable -> ");
    int dres = add_htable(table, "titi", d);
    if (dres != 0)
    {
        printf("OK !\n");
    }
    else
    {
        printf("KO...\n");
    }
    printf("Adding 'toto' to the htable again (should fail) -> ");
    int eres = add_htable(table, "toto", e);
    if (eres != 0)
    {
        printf("OK !\n");
    }
    else
    {
        printf("KO...\n");
    }
    
	printf("\nTrying to search elements in the htable.\n");
    
    

    clear_htable(table);

    free(a);
    free(b);
    free(c);
    free(d);
    free(e);

	return 0;
}
