#include<stdio.h>

#define MAX 100

int productcode[]={1,2,3,4};
int qtystock[]={50,10,20,8};
int priceperproduct[]={100,200,300,150};
int numproducts=4;

int getcustomerinfo(char name[],char cnic[]){
int counter=0;
char ch;

    printf("Enter a name: ");
    while(counter < 50){
        ch=getchar();
        if(ch=='\n'){
            break;
        }
        else{
            name[counter]=ch;
            counter++;
        }
    }
    name[counter]='\0';

    printf("\nEnter a CNIC(xxxxx-xxxxxxx-x): ");
    scanf("%s",cnic);
    getchar();

    return 0;
}

int displayinventory(){

    printf("%-20s%-25s%-25s\n","product code","Quantity in stock","Price per product");
    for(int i=0;i<numproducts;i++){
       printf("%-20d%-25d%-25d\n",productcode[i],qtystock[i],priceperproduct[i]); 
    }
    return 0;

}

int findproductindex(int code){
    for(int i=0;i<numproducts;i++){
        if(productcode[i]==code){
            return i;
        }
    }
    return -1;
}

int updateinventory(int code,int qty){
    int index=findproductindex(code);

    if(index != -1){
        qtystock[index]-=qty;

    }
    return 0;
}

int addtocart(int cartcode[],int cartqty[],int*cartcount){
    int code,qty;
    printf("\nEnter product code: ");
    scanf("%d",&code);
    getchar();
    int index=findproductindex(code);
    if(index == -1){
        printf("\nIvalid product code!");
        return 0;
    }
    printf("\nEnter a Quantity: ");
    scanf("%d",&qty);
    getchar();

    if(qty > qtystock[index]){
        printf("\nNot enough quantity in the stock!");
        return 0;
    }

    cartcode[*cartcount] = code;
    cartqty[*cartcount] = qty;
    (*cartcount)++;

    updateinventory(code,qty);
    return 0;
}

int displaytotal(int cartcode[], int cartqty[], int cartcount) {
    float total = 0;
    for (int i = 0; i < cartcount; i++) {
        int index = findproductindex(cartcode[i]);
        total += priceperproduct[index] * cartqty[i];
    }

    printf("\nTotal bill: %.2f", total);
    printf("\nDo you have promo code (Eid2025)? (y/n): ");
    char ans;
    scanf(" %c", &ans);
    getchar();

    if (ans == 'y' || ans == 'Y') {
        total = total - (total * 0.25);
        printf("25%% discount applied!\n");
    }

    printf("Final Bill: %.2f\n", total);
    return 0;
}

int showinvoice(int cartcode[], int cartqty[], int cartcount, char name[], char cnic[]) {
    printf("\n------ INVOICE ------\n");
    printf("Customer Name: %s\n", name);
    printf("CNIC: %s\n", cnic);
    printf("\n%-10s %-10s %-10s %-10s\n", "Code", "Qty", "Price", "Total");

    float total = 0;
    for (int i = 0; i < cartcount; i++) {
        int index = findproductindex(cartcode[i]);
        float itemTotal = priceperproduct[index] * cartqty[i];
        total += itemTotal;
        printf("%-10d %-10d %-10d %-10.2f\n", cartcode[i], cartqty[i], priceperproduct[index], itemTotal);
    }

    printf("----------------------------\n");
    printf("Total Bill: %.2f\n", total);
    printf("----------------------------\n");
    return 0;
}


int main() {
    char name[50], cnic[20];
    int choice;
    int cartcode[MAX], cartqty[MAX], cartcount = 0;

    printf("===== SUPERMARKET BILLING SYSTEM =====\n");

       do{
        printf("\n1. Enter Customer Information");
        printf("\n2. Display Inventory");
        printf("\n3. Add to Cart");
        printf("\n4. Display Total");
        printf("\n5. Show Invoice");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: getcustomerinfo(name, cnic); break;

            case 2: displayinventory(); break;

            case 3: addtocart(cartcode, cartqty, &cartcount); break;

            case 4: displaytotal(cartcode, cartqty, cartcount); break;

            case 5: showinvoice(cartcode, cartqty, cartcount, name, cnic); break;

            case 6: printf("Exiting the system. Goodbye!\n"); return 0;

            default: printf("Invalid choice! Please try again.\n");
        }
    }while(1);

    return 0;
}
