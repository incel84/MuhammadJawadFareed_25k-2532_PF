#include<stdio.h>

#define MAX 100

int addbook(int isbns[],char titles[][50],float price[],int qty[],int *count){
    int isbn,i;
    char ch;
    int counter=0;

    printf("Enter a ISBN: ");
    scanf("%d",&isbn);
    getchar();

    for(int i=0;i<*count;i++){
        if(isbns[i]==isbn){
            printf("\nBook already existed!");
            return 0;
        }    
    }
    isbns[*count]=isbn;
    printf("\nEnter a Book title: ");
    while(counter<49){
        
        ch=getchar();
        if(ch=='\n'){
            break;
        }
        else{
            titles[*count][counter]=ch;
            counter++;
        }
    }
    titles[*count][counter]='\0';

    printf("\nEnter a price: ");
    scanf("%f",&price[*count]);
    getchar();

    printf("\nEnter a quantity: ");
    scanf("%d",&qty[*count]);
    getchar();

    (*count)++;
    return 1;
}

int sellbook(int isbns[],char titles[][50],float price[],int qty[],int count){
    int isbn,Sellqty,found=-1;

    printf("Enter a ISBN to sell: ");
    scanf("%d",&isbn);
    getchar();

    for(int i=0;i<count;i++){
        if(isbns[i]==isbn){
            found=i;
            break;
        }
    }

    if(found==-1){
        printf("Book not found!");
        return 0;
    }

    printf("Enter a quantity to sell: ");
    scanf("%d",&Sellqty);
    getchar();

    if(Sellqty>qty[found]){
        printf("Not enough quantity in the stocks!");
        return 2;
    }
    else{
        qty[found]-=Sellqty;
        printf("The ISBN %d with title '%s' is sold for %.2f",isbns[found],titles[found],price[found]*Sellqty);
        return 1;
    }
}

int lowstock(int isbns[],char titles[][50],float price[],int qty[],int count){
    int found=0;
    for(int i=0;i<count;i++){
        if(qty[i]<5){
            printf("ISBN: %d | %s| %.2f | Quantity=%d\n",isbns[i],titles[i],price[i],qty[i]);
            found=1;
        }
    }
    if(found==0){
        printf("No low stock books! ");
        return 0;
    }
    return 1;
}

int main(){
        int isbns[MAX]={0},qty[MAX]={0};
        char titles[MAX][50]={{0}};
        float price[MAX]={0};
        int choice;
        int count=0;
        do{    
        printf("\n----Liberty Market Inventory----\n");
        printf("1-Add a new book\n");
        printf("2-Sell a book\n");
        printf("3-Check low stock Books\n");
        printf("4-Exit\n");
        printf("Enter a choice");
        scanf("%d",&choice);
        getchar();
        
        switch(choice){
            case 1: addbook(isbns,titles,price,qty,&count); break;
            case 2: sellbook(isbns,titles,price,qty,count); break;
            case 3: lowstock(isbns,titles,price,qty,count); break;
            case 4: printf("Exiting----\n");  break;
            default: printf("invalid input!"); break;
        }

        }while(choice!=4); 
        return 0;
}