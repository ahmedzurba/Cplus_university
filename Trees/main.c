////////////////////////////////////////
//the aim of the program is to take a text file as
//argument from command line ,read the input to use it for
//creation of for kind of trees and return a dot file
//for each tree and the time for the creation of the trees
//////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include "libtree.h"
#include<sys/time.h>



struct my_struct
{
    int key;
    struct bstree_node node;
};
struct my_struct_rb
{
    int key;
    struct rbtree_node node;
};
struct my_struct_avl
{
    int key;
    struct avltree_node node;
};
struct my_struct_splay
{
    int key;
    struct splaytree_node node;
};


/////// comparing functions for all trees
int my_cmp(const struct bstree_node *a, const struct bstree_node *b)
{
    struct my_struct *p = bstree_container_of(a,struct my_struct, node);
    struct my_struct *q = bstree_container_of(b,struct my_struct, node);
    return p->key - q->key;
}
int my_cmp_rb(const struct rbtree_node *a, const struct rbtree_node *b)
{
    struct my_struct_rb *p = rbtree_container_of(a,struct my_struct_rb, node);
    struct my_struct_rb *q = rbtree_container_of(b,struct my_struct_rb, node);
    return p->key - q->key;
}
int my_cmp_avl(const struct avltree_node *a, const struct avltree_node *b)
{
    struct my_struct_avl *p = avltree_container_of(a,struct my_struct_avl, node);
    struct my_struct_avl *q = avltree_container_of(b,struct my_struct_avl, node);
    return p->key - q->key;
}
int my_cmp_splay(const struct splaytree_node *a, const struct splaytree_node *b)
{
    struct my_struct_splay *p = splaytree_container_of(a,struct my_struct_splay, node);
    struct my_struct_splay *q = splaytree_container_of(b,struct my_struct_splay, node);
    return p->key - q->key;
}






///////////////////////////////////////////////////////////////////////////

static inline struct bstree_node *get_link(uintptr_t u)
{
    return (struct bstree_node *)(u & ((int)(u & 1) - 1));
}
static inline struct splaytree_node *get_link_s(uintptr_t u)
{
    return (struct splaytree_node *)(u & ((int)(u & 1) - 1));
}
////////////////////////////////////////////////////////////////////

//function to travers the tree and create the dot file
void print_dot_null(int key, int nullcount, FILE* stream)
{
    fprintf(stream, "    null%d [shape=point];\n", nullcount);
    fprintf(stream, "    %d -> null%d;\n", key, nullcount);
}

void bst_print_dot_aux(struct bstree_node *node1, FILE* stream)
{
    static int nullcount = 0;

    struct my_struct *p = bstree_container_of(node1,struct my_struct, node);
    struct my_struct *pright = bstree_container_of(get_link(node1->right),struct my_struct, node);
    struct my_struct *pleft = bstree_container_of(get_link(node1->left),struct my_struct, node);

    if (get_link(node1->left))
    {
        fprintf(stream, "    %d -> %d;\n", p->key, pleft->key);
        bst_print_dot_aux(get_link(node1->left), stream);
    }
    else
        print_dot_null(p->key, nullcount++, stream);

    if (get_link(node1->right))
    {
        fprintf(stream, "    %d -> %d;\n", p->key, pright->key);
        bst_print_dot_aux(get_link(node1->right), stream);
    }
    else
        print_dot_null(p->key, nullcount++, stream);
}

void bst_print_dot(struct bstree_node* tree, FILE* stream)
{
    fprintf(stream, "digraph BST {\n");
    fprintf(stream, "    node [fontname=\"Arial\"];\n");

    struct my_struct *p = bstree_container_of(tree,struct my_struct, node);


    if (!tree)
        fprintf(stream, "\n");
    else if (!tree->right && !tree->left)
        fprintf(stream, "    %d;\n", p->key);
    else
        bst_print_dot_aux(tree, stream);

    fprintf(stream, "}\n");
}
///////////////////////////////////////////////////
void rbt_print_dot_aux(struct rbtree_node *node1, FILE* stream)
{
    static int nullcount1 = 0;

    struct my_struct_rb *p = rbtree_container_of(node1,struct my_struct_rb, node);
    struct my_struct_rb *pright = rbtree_container_of((node1->right),struct my_struct_rb, node);
    struct my_struct_rb *pleft = rbtree_container_of((node1->left),struct my_struct_rb, node);

    if (node1->left)
    {
        fprintf(stream, "    %d -> %d;\n", p->key, pleft->key);
        rbt_print_dot_aux(node1->left, stream);
    }
    else
        print_dot_null(p->key, nullcount1++, stream);

    if (node1->right)
    {
        fprintf(stream, "    %d -> %d;\n", p->key, pright->key);
        rbt_print_dot_aux(node1->right, stream);
    }
    else
        print_dot_null(p->key, nullcount1++, stream);
}

void rbt_print_dot(struct rbtree_node* tree, FILE* stream)
{
    fprintf(stream, "digraph RBTree {\n");
    fprintf(stream, "    node [fontname=\"Arial\"];\n");

    struct my_struct_rb *p = rbtree_container_of(tree,struct my_struct_rb, node);


    if (!tree)
        fprintf(stream, "\n");
    else if (!tree->right && !tree->left)
        fprintf(stream, "    %d;\n", p->key);
    else
        rbt_print_dot_aux(tree, stream);

    fprintf(stream, "}\n");
}
///////////////////////////////////////
void avlt_print_dot_aux(struct avltree_node *node1, FILE* stream)
{
    static int nullcount2 = 0;

    struct my_struct_avl *p = avltree_container_of(node1,struct my_struct_avl, node);
    struct my_struct_avl *pright = avltree_container_of((node1->right),struct my_struct_avl, node);
    struct my_struct_avl *pleft = avltree_container_of((node1->left),struct my_struct_avl, node);

    if (node1->left)
    {
        fprintf(stream, "    %d -> %d;\n", p->key, pleft->key);
        avlt_print_dot_aux(node1->left, stream);
    }
    else
        print_dot_null(p->key, nullcount2++, stream);

    if (node1->right)
    {
        fprintf(stream, "    %d -> %d;\n", p->key, pright->key);
        avlt_print_dot_aux(node1->right, stream);
    }
    else
        print_dot_null(p->key, nullcount2++, stream);
}

void avlt_print_dot(struct avltree_node* tree, FILE* stream)
{
    fprintf(stream, "digraph AVLTree {\n");
    fprintf(stream, "    node [fontname=\"Arial\"];\n");

    struct my_struct_avl *p = avltree_container_of(tree,struct my_struct_avl, node);


    if (!tree)
        fprintf(stream, "\n");
    else if (!tree->right && !tree->left)
        fprintf(stream, "    %d;\n", p->key);
    else
        avlt_print_dot_aux(tree, stream);

    fprintf(stream, "}\n");
}
///////////////////////////////////////////////////
void splayt_print_dot_aux(struct splaytree_node *node1, FILE* stream)
{
    static int nullcount3 = 0;

    struct my_struct_splay *p = splaytree_container_of(node1,struct my_struct_splay, node);
    struct my_struct_splay *pright = splaytree_container_of(get_link_s(node1->right),struct my_struct_splay, node);
    struct my_struct_splay *pleft = splaytree_container_of(get_link_s(node1->left),struct my_struct_splay, node);

    if (get_link_s(node1->left))
    {
        fprintf(stream, "    %d -> %d;\n", p->key, pleft->key);
        splayt_print_dot_aux(get_link_s(node1->left), stream);
    }
    else
        print_dot_null(p->key, nullcount3++, stream);

    if (get_link_s(node1->right))
    {
        fprintf(stream, "    %d -> %d;\n", p->key, pright->key);
        splayt_print_dot_aux(get_link_s(node1->right), stream);
    }
    else
        print_dot_null(p->key, nullcount3++, stream);
}

void splayt_print_dot(struct splaytree_node* tree, FILE* stream)
{
    fprintf(stream, "digraph Splay {\n");
    fprintf(stream, "    node [fontname=\"Arial\"];\n");

    struct my_struct_splay *p = splaytree_container_of(tree,struct my_struct_splay, node);


    if (!tree)
        fprintf(stream, "\n");
    else if (!tree->right && !tree->left)
        fprintf(stream, "    %d;\n", p->key);
    else
        splayt_print_dot_aux(tree, stream);

    fprintf(stream, "}\n");
}




int main( int argc, char *argv[] )
{





    //initialization
    struct timeval tim;
    char ch[10];
    FILE *fp;
    double elapse_bst=0.0,elapse_rb=0.0,elapse_avl=0.0,elapse_splay=0.0;
    double dTime1 ,dTime2;

    struct bstree *bsttree=(struct bstree* )malloc(sizeof(struct bstree));
    bstree_init(bsttree, my_cmp, 0);
    struct rbtree *rb=(struct rbtree* )malloc(sizeof(struct rbtree));
    rbtree_init(rb, my_cmp_rb, 0);
    struct avltree *avl=(struct avltree* )malloc(sizeof(struct avltree));
    avltree_init(avl, my_cmp_avl, 0);
    struct splaytree *splay=(struct splaytree* )malloc(sizeof(struct splaytree));
    splaytree_init(splay, my_cmp_splay, 0);




//// open the file from the command line
    fp = fopen(argv[1],"r");

    if( fp == NULL )
    {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }

    while( ( fscanf(fp,"%s",ch) ) != EOF )

        //insertion part
        if(*ch=='i')
        {

            int h;
            fscanf(fp,"%i",&h);
/////////////////////////////////////////////////////
            gettimeofday(&tim, NULL);
            dTime1 = tim.tv_sec+(tim.tv_usec/1000000.0);

            struct my_struct* newnode=(struct my_struct* )malloc(sizeof(struct my_struct));
            newnode->key=h;
            (bstree_insert(&(newnode->node),bsttree));

            gettimeofday(&tim, NULL);
            dTime2 = tim.tv_sec+(tim.tv_usec/1000000.0);
            elapse_bst+=(dTime2-dTime1);
/////////////////////////////////////////////////////////////

            gettimeofday(&tim, NULL);
            dTime1 = tim.tv_sec+(tim.tv_usec/1000000.0);

            struct my_struct_rb* newrbnode=(struct my_struct_rb* )malloc(sizeof(struct my_struct_rb));
            newrbnode->key=h;
            (rbtree_insert(&(newrbnode->node),rb));

            gettimeofday(&tim, NULL);
            dTime2 = tim.tv_sec+(tim.tv_usec/1000000.0);
            elapse_rb+=(dTime2-dTime1);
//////////////////////////////////////////////////////////////////////
            gettimeofday(&tim, NULL);
            dTime1 = tim.tv_sec+(tim.tv_usec/1000000.0);

            struct my_struct_avl* newAvlnode=(struct my_struct_avl* )malloc(sizeof(struct my_struct_avl));
            newAvlnode->key=h;
            (avltree_insert(&(newAvlnode->node),avl));

            gettimeofday(&tim, NULL);
            dTime2 = tim.tv_sec+(tim.tv_usec/1000000.0);
            elapse_avl+=(dTime2-dTime1);

/////////////////////////////////////////////////////////////////////////
            gettimeofday(&tim, NULL);
            dTime1 = tim.tv_sec+(tim.tv_usec/1000000.0);

            struct my_struct_splay* newSplaynode=(struct my_struct_splay* )malloc(sizeof(struct my_struct_splay));
            newSplaynode->key=h;
            (splaytree_insert(&(newSplaynode->node),splay));

            gettimeofday(&tim, NULL);
            dTime2 = tim.tv_sec+(tim.tv_usec/1000000.0);
            elapse_splay+=(dTime2-dTime1);
/////////////////////////////////////////////////////////////////////////

        }



// look_up part
        else if(*ch=='f')
        {

            int h=0;
            fscanf(fp,"%i",&h);
////////////////////////
            gettimeofday(&tim, NULL);
            dTime1 = tim.tv_sec+(tim.tv_usec/1000000.0);

            struct my_struct* targetnode=(struct my_struct* )malloc(sizeof(struct my_struct));
            (targetnode->key)=h;
            (bstree_lookup(&(targetnode->node),bsttree));
            free(targetnode);

            gettimeofday(&tim, NULL);
            dTime2 = tim.tv_sec+(tim.tv_usec/1000000.0);
            elapse_bst+=(dTime2-dTime1);
/////////////////////////

            gettimeofday(&tim, NULL);
            dTime1 = tim.tv_sec+(tim.tv_usec/1000000.0);

            struct my_struct_rb* targetRbnode=(struct my_struct_rb* )malloc(sizeof(struct my_struct_rb));
            (targetRbnode->key)=h;
            (rbtree_lookup(&(targetRbnode->node),rb));
            free(targetRbnode);

            gettimeofday(&tim, NULL);
            dTime2 = tim.tv_sec+(tim.tv_usec/1000000.0);
            elapse_rb+=(dTime2-dTime1);
///////////////////////////
            gettimeofday(&tim, NULL);
            dTime1 = tim.tv_sec+(tim.tv_usec/1000000.0);

            struct my_struct_avl* targetAvlnode=(struct my_struct_avl* )malloc(sizeof(struct my_struct_avl));
            (targetAvlnode->key)=h;
            (avltree_lookup(&(targetAvlnode->node),avl));
            free(targetAvlnode);

            gettimeofday(&tim, NULL);
            dTime2 = tim.tv_sec+(tim.tv_usec/1000000.0);
            elapse_avl+=(dTime2-dTime1);
//////////////////////////////
            gettimeofday(&tim, NULL);
            dTime1 = tim.tv_sec+(tim.tv_usec/1000000.0);

            struct my_struct_splay* targetSplaynode=(struct my_struct_splay* )malloc(sizeof(struct my_struct_splay));
            (targetSplaynode->key)=h;
            (splaytree_lookup(&(targetSplaynode->node),splay));
            free(targetSplaynode);

            gettimeofday(&tim, NULL);
            dTime2 = tim.tv_sec+(tim.tv_usec/1000000.0);
            elapse_splay+=(dTime2-dTime1);
        }


// deletion part
        else if(*ch=='d')
        {

            int h=0;
            fscanf(fp,"%i",&h);

///////////////////////////
            gettimeofday(&tim, NULL);
            dTime1 = tim.tv_sec+(tim.tv_usec/1000000.0);

            struct my_struct* targetnode=(struct my_struct* )malloc(sizeof(struct my_struct));
            (targetnode->key)=h;
            if(bstree_lookup(&(targetnode->node),bsttree))
            {
                bstree_remove(bstree_lookup(&(targetnode->node),bsttree),bsttree);
            }
            gettimeofday(&tim, NULL);
            dTime2 = tim.tv_sec+(tim.tv_usec/1000000.0);
            elapse_bst+=(dTime2-dTime1);
/////////////////////////////////////
            gettimeofday(&tim, NULL);
            dTime1 = tim.tv_sec+(tim.tv_usec/1000000.0);

            struct my_struct_rb* targetRbnode=(struct my_struct_rb* )malloc(sizeof(struct my_struct_rb));
            (targetRbnode->key)=h;
            if(rbtree_lookup(&(targetRbnode->node),rb))
            {
                rbtree_remove(rbtree_lookup(&(targetRbnode->node),rb),rb);
            }
            gettimeofday(&tim, NULL);
            dTime2 = tim.tv_sec+(tim.tv_usec/1000000.0);
            elapse_rb+=(dTime2-dTime1);
/////////////////////////////////
            gettimeofday(&tim, NULL);
            dTime1 = tim.tv_sec+(tim.tv_usec/1000000.0);

            struct my_struct_avl* targetAvlnode=(struct my_struct_avl* )malloc(sizeof(struct my_struct_avl));
            (targetAvlnode->key)=h;
            if(avltree_lookup(&(targetAvlnode->node),avl))
            {
                avltree_remove(avltree_lookup(&(targetAvlnode->node),avl),avl);
            }
            gettimeofday(&tim, NULL);
            dTime2 = tim.tv_sec+(tim.tv_usec/1000000.0);
            elapse_avl+=(dTime2-dTime1);
///////////////////////////////////
            gettimeofday(&tim, NULL);
            dTime1 = tim.tv_sec+(tim.tv_usec/1000000.0);

            struct my_struct_splay* targetSplaynode=(struct my_struct_splay* )malloc(sizeof(struct my_struct_splay));
            (targetSplaynode->key)=h;
            if(splaytree_lookup(&(targetSplaynode->node),splay))
            {
                splaytree_remove(splaytree_lookup(&(targetSplaynode->node),splay),splay);
            }
            gettimeofday(&tim, NULL);
            dTime2 = tim.tv_sec+(tim.tv_usec/1000000.0);
            elapse_splay+=(dTime2-dTime1);
/////////////////////////////////////////
        }
    fclose(fp);




    FILE *fp2,*fp3,*fp4,*fp5;
    fp2 = fopen("bstree_dot_file.txt","w");
    fp3 = fopen("rbtree_dot_file.txt","w");
    fp4 = fopen("avltree_dot_file.txt","w");
    fp5 = fopen("splaytree_dot_file.txt","w");
    bst_print_dot(bsttree->root, fp2);
    rbt_print_dot(rb->root,fp3);
    avlt_print_dot(avl->root,fp4);
    splayt_print_dot(splay->root,fp5);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
    fclose(fp5);

/////printing the time for each tree
    printf("BSTree\t\t%.4lf\nRBTree\t\t%.4lf\nAVLTree\t\t%.4lf\nSplayTree\t%.4lf",elapse_bst,elapse_rb,elapse_avl,elapse_splay);

    return 0;
}
