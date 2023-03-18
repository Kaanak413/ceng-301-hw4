#include <time.h>
#include "iostream"
#include <fstream>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;

struct Tree {
 char *title;

Tree *left, *right;
};

void inorder(struct Tree *root) {
  if (root != NULL) {
    // Traverse left
    inorder(root->left);

    // Traverse root
    cout << root->title << " -> ";

    // Traverse right
    inorder(root->right);
  }
}
struct Tree* insertBST(char* book,struct Tree* t) 
{ 

    
     
     
    if(t == NULL)
    {
        
        t=new Tree{book,nullptr,nullptr};
        return t;
    }
    else if(*book < *(t->title))
    {
         t->left=insertBST(book,t->left);
    }
    else if (*(t->title) < *book )
    {
        t->right=insertBST(book,t->right);    
    }
    else
        ;
    
    return t;    
}
Tree *remove_left(Tree *book)
{
  if(book==NULL)
  {
    return NULL;
  }  
 Tree *last_left_node;
 Tree* bookright;   
 last_left_node=book;
 bookright=book->right;
 Tree* parent;
 parent=book;
 bool x=false;
 int k=0;   
 while(!x)
 {
    
    if(last_left_node == NULL)
    {
        return book;
    }
   
    if((last_left_node->left == NULL))
    {
        x=true;
        
        //book = temptree;
        
        if(last_left_node->right == NULL )
        {
            for(int i=0;i<k-1;i++)
            {
                parent=parent->left;
            }
          
            
            int xd1 = strlen(last_left_node->title);
            char * xd = new char[xd1+1];
            strcpy(xd,last_left_node->title);
            book->title=xd;
            last_left_node->title=NULL;
            parent->left=NULL;
            
            
            return book;
            
        }
        else
        {
            Tree* last_right= new Tree{last_left_node->right->title,last_left_node->right->left,last_left_node->right->right};
            
            last_left_node->right = bookright;
            Tree* cpy1= new Tree{last_left_node->title,last_left_node->left,last_left_node->right};
            book=cpy1;
            last_left_node=last_right;
            
         }
        
        
    }
    else
    {
        last_left_node=last_left_node->left;
        k++;
    }
 }
 
}

Tree *remove_right(Tree *book)
{

    if(book==NULL)
  {
    return NULL;
  } 

    if(book->right == NULL && book->left == NULL )
    {
        book=NULL;
        return book;
    }
    else if(book->right == NULL)
    {
        cout<<"This node cannot be removed"<<std::endl;
        book=NULL;
        return NULL;
    }
    else
    {
        Tree * tempnode=book->right;
        book->right=book->right->right;
        book=tempnode;
        if(book->right == NULL)
        {
            book=NULL;
            return book;
        }
        return(remove_right(book->right));
        std::cout<<"commit yaptık"<<std::endl;
    }



}









int main()
{
struct Tree *libBST=NULL;
std::string word;

 ifstream newfile;
 newfile.open("books.txt");


 if(newfile)
 {
    
    
    while (getline(newfile,word))
    {
         char * cstr = new char[word.length()+1];
         strcpy(cstr, word.c_str());
         libBST=insertBST(cstr,libBST);
            
    }
         
    
 }
clock_t start, end;
double cpu_time_used;    
start = clock();
libBST=remove_left(libBST);
libBST=remove_left(libBST);
libBST=remove_right(libBST);
libBST=remove_right(libBST);

std::cout << "Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;

system("pause");
return 0;
}