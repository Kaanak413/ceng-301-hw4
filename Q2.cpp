#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;
struct Heap {
char character;
int occurrence;
Heap *left, *right;
};
struct Heap* occurrenceHeap=NULL;

void insert(Heap *newChar,Heap* &root)
{
   if(root == NULL)
   {
    root = newChar;
    return ;
   } 
   if(root->left==NULL && (root->occurrence>newChar->occurrence))
   {
    root->left = newChar;
    return ;

   }
   else if(root->left==NULL)
   {    
        char kd = newChar->character;
        int kd1 = newChar->occurrence;
        char pd = root->character;
        int pd1 = root->occurrence;
        root->character=kd;
        root->occurrence=kd1;
        newChar->character=pd;
        newChar->occurrence=pd1;
        root->left=newChar;
        return;
    
   }
    if((root->right==NULL)&& (root->occurrence>newChar->occurrence) )
    {
    root->right = newChar;
    return ;
    }
    else if(root->right==NULL)
    {
        char xd = newChar->character;
        int xd1 = newChar->occurrence;
        char yd = root->character;
        int yd1 = root->occurrence;
        root->character=xd;
        root->occurrence=xd1;
        newChar->character=yd;
        newChar->occurrence=yd1;
        root->right=newChar;
        return;

    }
    if(root->left->occurrence>root->right->occurrence)
    {
        insert(newChar,root->right);
    }
    else
    {
        insert(newChar,root->left);
    }



}

void readfromfile(char *filename)
{
    char xd;
    Heap occurrenceH[26] = {0};

    ifstream f(filename);
    while(f >> xd)
    {
        if (xd >= 97 && xd <= 122) //make small charachters big,counting makes it easier
        { 
        xd = xd -32;
        }
         if (xd < 65 || xd > 90)
        { 
            continue;
        }
        const int index = xd- 65;

        (occurrenceH[index].occurrence)++; //store it in heap array
        (occurrenceH[index].character)=xd;
        occurrenceH[index].left,occurrenceH[index].right = NULL;
    }
    for(int i=0;i<26;i++)
    {
        struct Heap *tmptree = (struct Heap*)malloc(sizeof(struct Heap));//pass it to the temp struct.
        tmptree->character=occurrenceH[i].character;
        tmptree->occurrence=occurrenceH[i].occurrence;
        tmptree->left=occurrenceH[i].left;
        tmptree->right=occurrenceH[i].right;
        insert(tmptree,occurrenceHeap);
        
    }




}


void inorder(struct Heap *root) {
  if (root != NULL) {
    // Traverse left
    inorder(root->left);

    // Traverse root
    cout << root->character << " -> ";

    // Traverse right
    inorder(root->right);
  }
}













int main()
{
    
    
    
    
    readfromfile("books.txt");
 
    inorder(occurrenceHeap);

    system("pause");














    return 0;
}