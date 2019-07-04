#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
typedef struct fileWords{
    char word[20];
}fileWords;
fileWords words[3000];
node * sortedArrayToBST(fileWords arr[], int start, int end);
node * successor(node* leaf);
node * predecessor(node *pred);
node *root;
node *leaf; //last node we reached while searching for word
node *leafParent;
node *leafParentOfParent;
int main()
{
    dealWithInputFile();
    int n = sizeof(words)/sizeof(words[0]);
    root = sortedArrayToBST(words, 0, n-1);
    //check if tree is balanced
    switch(isBalanced(root)){
        case 1:printf("The tree is balanced\n");break;
        case 0:printf("The tree is not balanced\n");break;
    }

    //height of tree
    printf("Height of the tree = %d\n\n",height(root));

    //word to search for in tree
    char testWord[50];
    int spaces=0;
    int i;
    printf("Enter a word to search for: ");
    scanf("%s",&testWord);
    switch(searching(root,testWord)){
        case 1:printf("The word <%s> is correct\n",testWord);break;
        case 0: printf("\nWord <%s> is Wrong\n",testWord);
                printf("Leaf word is <%s>\n",leaf->word);
                printf("Successor is <%s>\n",successor(leaf)->word);
                printf("Predecessor is <%s>\n",predecessor(leaf)->word);
                break;
    }
    return 0;
}

void dealWithInputFile(){
    int count =0;
    FILE *af = fopen("English Dictionary.txt","r");
    char line[50];
    while(!feof(af)){
        fgets(line,50,af);
        strtok(line,"\n");
        strcpy(words[count].word,line);
        count++;
    }
}
node * sortedArrayToBST(fileWords arr[], int start, int end){
    if (start > end)
      return NULL;

    //Get the middle element and make it root
    int mid = (start + end)/2;
    node *root = newNode(arr[mid].word);

    // construct the left subtree
    root->left =  sortedArrayToBST(arr, start, mid-1);

    // construct the right subtree
    root->right = sortedArrayToBST(arr, mid+1, end);

    return root;
}

int searching(node *root,char *word)
{
    while (root != NULL)
    {
        if (strcmp(word,root->word)<0){
            leafParentOfParent=leafParent;
            leafParent=leaf;
            leaf =root;
            root = root->left;
        }

        else if (strcmp(word,root->word)>0){
            leafParentOfParent=leafParent;
            leafParent=leaf;
            leaf =root;
            root = root->right;
        }
        else
            return 1;// if the key is found
    }
    return 0;
}

node * successor(node* suc){
    if(suc->right){
        suc = suc->right;
        while(suc->left){
            suc = suc->left;
        }
    }
    else{
        if(leafParent->right!=NULL&&strcmp(suc->word,leafParent->right->word)==0)
               suc=leafParentOfParent;
        else if(leafParent->left!=NULL&&strcmp(suc->word,leafParent->left->word)==0)
                suc=leafParent;
    }
        return suc;
}
node * predecessor(node *pred){
    if(pred->left){
        pred = pred->left;
        while(pred->right){
            pred = pred->right;
        }
    }
    else{
        if(leafParent->left!=NULL&&strcmp(pred->word,leafParent->left->word)==0)
                pred=leafParentOfParent;
         else if(leafParent->right!=NULL&&strcmp(pred->word,leafParent->right->word)==0)
                 pred=leafParent;
    }
        return pred;
}
