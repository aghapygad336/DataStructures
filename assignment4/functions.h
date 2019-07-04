typedef struct node
{
    char word[50];
    struct node *left, *right;
}node;
node * newNode(char *word){
    node* n = (node*)malloc(sizeof(node));
    strcpy(n->word,word);
    n->left=NULL;
    n->right=NULL;
    return n;
}
int height(node *r){
    if(r)
         return 1 + max(height(r->left), height(r->right));
    else
        return 0;
}
int max(int a, int b){
  return (a >= b)? a: b;
}

int isBalanced(node *root){
   int l;
   int r;
   if(root == NULL)
    return 1;
   l = height(root->left);
   r = height(root->right);
   if( abs(l-r) <= 1 &&
       isBalanced(root->left) &&
       isBalanced(root->right))
     return 1;
   return 0;
}

