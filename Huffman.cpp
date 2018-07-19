#include<iostream.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
struct tree
{
 char a[20];
 int s;
 struct tree *left,*right;
}*root=NULL,*tt[20]={NULL},*temp,*temp2,*t2,*ri,*le;
//Priority queue
struct pqu
{
 int info;
 char a[20];
 struct pqu *ptr;
}*front=NULL,*newnode,*node,*newpos,*p1,*p2;
//finds position for a node in priority queue
struct pqu* findposition(int info)
{
 struct pqu *p=NULL;
 for(newpos=front;newpos->info<info&&newpos!=NULL;newpos=newpos->ptr)
 {
  p=newpos;
 }
 return (p);
}
//Inserts a node in priority queue
void enqu(char a[20],int freq)
{
 newnode=(struct pqu*)malloc(sizeof(struct pqu));
 strcpy(newnode->a,a);
 newnode->info=freq;
 newnode->ptr=NULL;
 if(front==NULL)
 {
  front=newnode;
 }
 else
 {
  node=findposition(freq);
  if(node==NULL)
  {
   newnode->ptr=front;
   front=newnode;
  }
  else
  {
   newnode->ptr=node->ptr;
   node->ptr=newnode;
  }
 }
}
//Returns first node in the priority queue
struct pqu* dequ()
{
 newpos=front;
 front=front->ptr;
 return newpos;
}
//Displays Huffman code for a symbol
void info(char c[2])
{
 int m=0,i;
 temp2=root;
 while(strcmp(c,temp2->a)!=0)
 {
  t2=temp2->left;
  for(i=0;i<strlen(t2->a);i++)
  {
   if(t2->a[i]==c[0])
   {
    temp2=temp2->left;
    m=1;
    cout<<"0";
    break;
   }
  }
  if(m!=1)
  {
   temp2=temp2->right;
   cout<<1;
  }
  m=0;
 }
}
//Inserts a node in the Huffman Tree
void insert()
{
 char a1[20],b1[20],v1[20];
 int i,j,z=0,l;
 while(front!=NULL)
 {
  p1=dequ();
  strcpy(a1,p1->a);
  l=p1->info;
  p2=dequ();
  if(p2==NULL)
   break;
  strcpy(b1,p2->a);
  strcpy(v1,a1);
  temp=(struct tree*)malloc(sizeof(struct tree));
  strcpy(temp->a,strcat(v1,b1));
  temp->s=l+p2->info;
  temp->left=NULL;
  temp->right=NULL;
  temp2=temp;
  root=temp;
  for(i=0;i<z;)
  {
   if(strcmp(tt[i]->a,a1)==0)
   {
    temp->left=tt[i];
    for(l=i;l<z;l++)
    {
     tt[l]=tt[l+1];
    }
    i=0;
    continue;
   }
   else if(strcmp(tt[i]->a,b1)==0)
   {
    temp->right=tt[i];
    for(l=i;l<z;l++)
    {
     tt[l]=tt[l+1];
    }
    i=0;
    continue;
   }
   i++;
  }
  if(temp->left==NULL)
  {
   le=(struct tree*)malloc(sizeof(struct tree));
   strcpy(le->a,a1);
   le->left=NULL;
   le->right=NULL;
   temp2->left=le;
  }
  if(temp->right==NULL)
  {
   ri=(struct tree*)malloc(sizeof(struct tree));
   strcpy(ri->a,b1);
   ri->left=NULL;
   ri->right=NULL;
   temp2->right=ri;
  }
  if(front!=NULL)
  enqu(temp2->a,temp2->s);
  tt[z++]=temp2;
 }
}
//Inorder traversal of Huffman tree
void disp(struct tree *rt)
{
 if(rt!=NULL)
 {
  disp(rt->left);
  cout<<" "<<rt->a;
  disp(rt->right);
 }
}
void main()
{
 int i=0,frequency,n;//c=0,count[36]={0};
 char m[20],b[20][2],cont;
 while(1)
 {
  clrscr();
  cout<<"======================================================"<<endl;
  cout<<"		 HUFFMAN CODING"<<endl;
  cout<<"======================================================"<<endl;
  cout<<"Enter the total no of characters : ";
  cin>>n;
  //cout<<"Enter a string:"<<endl;
  //cin.getline(m);
  //n=strlen(m);
  //strcpy(b[i],m);
  /*while(b[c]!='\0')
  {
   if(isalnum(b))
    count[b[c]-'a']++;
   c++;
  }
  for(c=0;c<36;c++)
  {
   if(count[c]!=0)
    cout<<c+'a'<<" occurs "<<count[c]<<" times."<<endl;
  }*/
  for(i=0;i<n;i++)
  {
   cout<<"Enter the character : ";
   cin>>m;
   //cout<<"Enter a string:"<<endl;
   //cin.getline(m);
   strcpy(b[i],m);
   cout<<"Enter frequency for "<<m<<" : ";
   cin>>frequency;
   enqu(m,frequency);
  }
  insert();
  disp(root);
  clrscr();
  cout<<"======================================================"<<endl;
  cout<<"The corresponding codes are....."<<endl;
  cout<<"======================================================"<<endl;
  for(i=0;i<n;i++)
  {
   cout<<" "<<b[i]<<" : ";
   info(b[i]);
   cout<<endl;
  }
  cout<<endl<<" DO YOU WANT TO CONTINUE Y OR N: ";
  cin>>cont;
  if(cont=='y'||cont=='Y')
   continue;
  else
   exit(0);
 }
}
