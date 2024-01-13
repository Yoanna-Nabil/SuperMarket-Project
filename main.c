#include <stdio.h>
#include <stdlib.h>

#include <windows.h>
#include <conio.h>
#define maxNameOfProduct 20
#define maxNameOfCategory 20
#define maxNumOfProductsPerCategory 20
#define maxNumOfCategorysInMarket 20
typedef struct product product;
typedef struct category category;
typedef struct market market;

struct product
{
    char productName[maxNameOfProduct];
    int productQuantity;
    double productPrice;

};

struct category
{
    char categoryName[maxNameOfCategory];
    product products[maxNumOfProductsPerCategory];
    int productCount;
};

struct market
{
    category categories[maxNumOfCategorysInMarket];
    int categoryCount;
};

void initialMarket(market *market)
{
    market->categoryCount=2;

    for(int i=0; i<2; i++)
    {
        market->categories[i].productCount=2;
    }


    strcpy(market->categories[0].categoryName,"Milks");
    strcpy(market->categories[1].categoryName,"Vegetables");

    strcpy(market->categories[0].products[0].productName,"Nedo");
    market->categories[0].products[0].productPrice=10;
    market->categories[0].products[0].productQuantity=10;

    strcpy(market->categories[0].products[1].productName,"Johaina");
    market->categories[0].products[1].productPrice=20;
    market->categories[0].products[1].productQuantity=20;


    strcpy(market->categories[1].products[0].productName,"Cucambers");
    market->categories[1].products[0].productPrice=5;
    market->categories[1].products[0].productQuantity=10;

    strcpy(market->categories[1].products[1].productName,"Lemons");
    market->categories[1].products[1].productPrice=3;
    market->categories[1].products[1].productQuantity=5;

}

void displayMarket(market *market)
{
    if(market->categoryCount!=0)
    {
        for(int i=0; i<market->categoryCount; i++)
        {
            printf("\n\n");

            printf("Category Name : %s \n",market->categories[i].categoryName);

            for(int j=0; j<market->categories[i].productCount; j++)
            {
                printf("  product Name : %s  | product Quantity : %d  | one product price : %.2f  | product Total price : %.2f\n"
                       ,market->categories[i].products[j].productName,
                       market->categories[i].products[j].productQuantity,
                       market->categories[i].products[j].productPrice,
                       market->categories[i].products[j].productQuantity *(market->categories[i].products[j].productPrice ));
            }
        }
    }
    else
    {
        printf("there is no data to display plz add data and display it \n");
    }

}

void addCategory(market *market)
{

    char c;
    do
    {


        if(market->categoryCount<maxNumOfCategorysInMarket)
        {

            printf("plz enter name of category that you want to add : ");


            scanf("%s",market->categories[market->categoryCount].categoryName);

            market->categories[market->categoryCount].productCount=0;
            market->categoryCount++;
            printf("category added successfully \n");
        }
        else
        {
            printf("you can not add more \n");
        }

        printf("\n\n");
        printf("Do you want to add another category in the supermarket? (Y|N)  \n");
        printf("\n");
        c = getch();


    }
    while(c=='y'||c=='Y');


}


void removeCategory(market *market)
{
    char c;
    do
    {


        if(market->categoryCount>0)
        {
            char catName[20];

            printf("enter name of category that you want to remove it : ");

            scanf("%s",catName);
            int findIndex=-1;
            for(int i=0; i<market->categoryCount; i++)
            {
                if(strcmp(market->categories[i].categoryName,catName)==0)
                {
                    findIndex=i;
                    break;
                }

            }

            if(findIndex!=-1)
            {
                for(int i=findIndex; i<market->categoryCount-1; i++)
                {
                    market->categories[i]=market->categories[i+1];
                }

                market->categoryCount--;
                printf("Category removed successfully.\n");
            }
            else
            {
                printf("this category not found \n");
            }

        }
        else
        {
            printf("there is no categories \n");
        }

        printf("\n\n");
        printf("Do you want to remove a category from the supermarket? (Y|N)  \n");
        printf("\n");
        c = getch();
    }
    while(c=='y'||c=='Y');

}

void addProduct(market *market)
{

    char c;
    do
    {
        char pName[maxNameOfProduct],cName[maxNameOfCategory];
        int price,quantity;

        printf("plz enter Product Name : ");

        scanf("%s",pName);

        printf("plz enter Category Name That you want to add Product on it : ");

        scanf("%s",cName);

        int findIndexOfCategory=-1;

        for(int i=0; i<market->categoryCount; i++)
        {
            if( strcmp(market->categories[i].categoryName,cName)==0)
            {
                findIndexOfCategory=i;
                break;
            }
        }

        if(findIndexOfCategory!=-1)
        {
            if(market->categories[findIndexOfCategory].productCount<maxNumOfProductsPerCategory)
            {
                strcpy(market->categories[findIndexOfCategory].products[market->categories[findIndexOfCategory].productCount].productName,pName);


                printf("plz enter quantity of this product : ");

                scanf("%d",&quantity);
                market->categories[findIndexOfCategory].products[market->categories[findIndexOfCategory].productCount].productQuantity=quantity;

                printf("plz enter price of one product : ");

                scanf("%d",&price);
                market->categories[findIndexOfCategory].products[market->categories[findIndexOfCategory].productCount].productPrice=price;

                market->categories[findIndexOfCategory].productCount++;

                printf("you added %s in %s",pName,cName);




            }

        }
        else
        {
            printf("this category not found plz try to enter correct Category Name\n");
        }
        printf("\n\n");
        printf("Do you want to add another product? (Y|N)  \n");
        printf("\n");
        c = getch();
    }
    while(c=='y'||c=='Y');



}

void removeProduct(market *market)
{
    char c;
    do
    {
        char pName[maxNameOfProduct],cName[maxNameOfCategory];


        printf("plz enter Product Name to delete it: ");

        scanf("%s",pName);

        printf("plz enter Category Name That you want to delete Product from it : ");

        scanf("%s",cName);

        int categoryIndex=-1;

        for(int i=0; i<market->categoryCount; i++)
        {
            if(strcmp(market->categories[i].categoryName,cName)==0)
            {
                categoryIndex=i;
                break;
            }
        }

        int productIndex=-1;
        if(categoryIndex!=-1)
        {
            for(int i=0; i<market->categories[categoryIndex].productCount; i++)
            {
                if(strcmp(market->categories[categoryIndex].products[i].productName,pName)==0)
                {
                    productIndex=i;
                    break;
                }
            }


            if(productIndex!=-1)
            {

                for(int i=productIndex; i<market->categories[categoryIndex].productCount-1; i++)
                {
                    market->categories[categoryIndex].products[i]=market->categories[categoryIndex].products[i+1];
                }
                market->categories[categoryIndex].productCount--;
                printf("you removed %s from %s \n",pName,cName);
            }
            else
            {
                printf("%s not found in %s \n",pName,cName);
            }
        }
        else
        {
            printf("%s not found \n",cName);
        }
       printf("\n\n");
        printf("Do you want to remove another product? (Y|N)  \n");
        printf("\n");
        c = getch();
    }
    while(c=='y'||c=='Y');





}



int main()
{
    market market;
    initialMarket(&market);

    int selectedOption = 0;

    char menu[20][80] =
    {
        "Display market Data",
        "Add Category",
        "Remove Category",
        "Add Product",
        "Remove Product",
        "Move Product to Another Category",
        "Sell",
        "Exit",
    };
    while (1)
    {

        system("cls");

        printf("\n\t\t\t\t\t\t\tSuper Market:\n");

        for (int i = 0; i < 8; i++)
        {



            if (selectedOption == i)
            {

                printf("-> %s", menu[i]);
            }
            else
            {

                printf("   %s", menu[i]);
            }
        }


        char key = _getch();

        switch (key)
        {
        case 72:

            if (selectedOption <= 0)
            {
                selectedOption = 7;
            }
            else
            {
                selectedOption--;
            }

            break;

        case 80:

            if (selectedOption >= 7)
            {
                selectedOption = 0;
            }
            else
            {
                selectedOption++;
            }

            break;

        case 13:
            switch (selectedOption)
            {
            case 0:
                system("cls");
                displayMarket(&market);
                _getch();
                system("cls");
                break;

            case 1:
                system("cls");

    displayMarket(&market);
    printf("\n\n");
                addCategory(&market);
                _getch();
                system("cls");
                break;

            case 2:
                system("cls");
                removeCategory(&market);
                _getch();
                system("cls");
                break;

            case 3:
                system("cls");
                addProduct(&market);
                _getch();
                break;

            case 4:
                system("cls");
                removeProduct(&market);
                _getch();
                break;

            case 5:
                system("cls");

                _getch();
                break;


            case 6:
                system("cls");
                _getch();
                break;

            case 7:
                system("cls");
                return 0;
                break;
            }

            break;
        case 27:
            system("cls");
            return 0;
            break;



        }
    }

    return 0;
}
