#include <stdio.h>
#include <stdlib.h>

//struct for node
struct node {
    void *value;
    struct node *p_left;
    struct node *p_right;
};

//use typedef to make calling the compare function easier
typedef int (*Compare)(const void *, const void *);

//inserts elements into the tree
void insert(void* key, struct node** leaf, Compare cmp)
{
    if( *leaf == NULL )
    {
        *leaf = (struct node*) malloc( sizeof( struct node ) );
        (*leaf)->value = key;
        (*leaf)->p_left = NULL;
        (*leaf)->p_right = NULL;
        printf(  "\nnew node " );
    }
    else if( cmp(key, (* leaf)->value) < 0)
    {
        printf(  "\ngoing left " );
        insert( key, &(* leaf)->p_left, cmp);
    }
    else if( cmp(key, (* leaf)->value) > 0)
    {
        printf(  "\ngoing right " );
        insert( key, &(* leaf)->p_right, cmp);
    }
    else {free(key);}
}

//compares value of the new node against the previous node
int CmpInt(const int *a, const int *b)
{
    if(*a < *b){return -1;}
    else if(*a > *b){return 1;}
    else return 0;
}

char *input( void )
{
    char line[10];
    printf("Please enter a string : ");
    if( fgets( line, sizeof line, stdin ) )
    {
        char *ret;
        ret = line;
        return ret;

    }
    return NULL;
}

//recursive function to print out the tree inorder
void in_order(struct node *root)
{
    if( root != NULL )
    {
        in_order(root->p_left);
        printf("%s\t", *(char*)root->value);
        in_order(root->p_right);
    }
}

//searches elements in the tree
void search(void* key, struct node** leaf, Compare cmp)
{
    if( *leaf != NULL )
    {
        if( cmp(key, (*leaf)->value) == 0)
        {
            printf("\n%d found!\n", *(char*)key);
        }
        //else if( cmp(key, (*leaf)->value ) < 0)
        else if( key < (*leaf)->value )
        {
            //printf(  "\nnot here \n" );
            search( key, &(*leaf)->p_left, cmp);
        }
        else if( cmp(key, (*leaf)->value) > 0)
        {
            //printf(  "\nor here \n" );
            search( key, &(*leaf)->p_right, cmp);
        }
    }
    else printf("\nNot in tree\n");
    return;
}

void delete_tree(struct node** leaf)
{
    if( *leaf != NULL )
    {
        delete_tree(&(*leaf)->p_left);
        delete_tree(&(*leaf)->p_right);
        free( (*leaf) );
    }
}

//displays menu for user
void menu()
{
    printf("\nPress 'i' to insert an element\n");
    printf("Press 's' to search for an element\n");
    printf("Press 'p' to print the tree inorder\n");
    printf("Press 'f' to destroy current tree\n");
    printf("Press 'q' to quit\n");
}

int main(void)
{
    struct node *p_root = NULL;
    void *value;
    char option = 'x';

    while( option != 'q' )
    {
        //displays menu for program
        menu();
        fflush(stdin);
        //gets the char input to drive menu
        option = getchar();
        getchar();

        if( option == 'i') //if 'i' then get an integer input
        {
            value = input();
            insert(value,  &p_root, (Compare)CmpInt);
        }
        else if( option == 's' ) //if 's' then get input value and call the search function
        {
            value = input();
            search(value, &p_root, (Compare)CmpInt);
        }
        else if( option == 'p' ) //if 'p' then call the print table function
        {
            in_order(p_root);
        }
        else if( option == 'f' ) //if 'f' destroy the tree and initailse new one
        {
            delete_tree(&p_root);
            printf("Tree destroyed");
            p_root = NULL;
        }
        else if( option == 'q' )
        {
            printf("Quitting");
        }
    }

    return 0;
}
