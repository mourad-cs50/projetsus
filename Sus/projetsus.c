#include<stdio.h>
#include<string.h>


typedef struct 
{
 int idClient;

char name[100];

char prenom[100];

char email[100];

float solde;

}Clients;



typedef struct 
{
 char idProduit[20] ;

char nom[100];

char categorie [100];

float prix ;

int stock;

char description[100];

}Products;

Clients client ;
Products product[5] = {

 {"P1","Laptop","Electronic",9550.00,11,"A fast laptop with long battery life."},
 {"P2","le petit prince","book",70.00,37,"A timeless story of friendship and imagination."},
 {"P3","Nike air force 1","shoes",450.00,52,"Iconic style and all-day comfort."},
 {"P4","Playstation 5","Electronic",7500.000,23,"Next-gen gaming with stunning speed and graphics."},
 {"P5","The School of Athens","Artwork",375.000,7,"A replica of Raphaels Renaissance masterpiece."},

};

int Current_stock[5];

int Check_user(){

if (client.idClient == 0)
{
    printf("Please create an profile.");
    printf("You cannot access other options if you do not have a profile!");
    return 0;
}

return 1;

}


void Gestion_de_profil_client( ){


int Profile_Choice;

printf("=== Gestion du profil client ===\n");
printf("=== Enter a choice ===\n");

printf("1.Profile creation\n");
printf("2.Editing profile\n");
printf("3.profile consultation\n");

printf("enter a number : ");
scanf("%i" , &Profile_Choice);


switch (Profile_Choice)
    {
    case 1:
         
    if (client.idClient != 0)
    {
        printf("An acount is already existed.\n");
    }
    

        printf("...Profile creation...\n");

        printf("Enter your first name: ");
        scanf("%s" , client.name);

        printf("Enter your second name: ");
        scanf("%s" , client.prenom);

        client.idClient =1;
        client.solde = 0;
         
        sprintf(client.email, "%s%s@Client.com", client.name, client.prenom);
        printf("The email is automaticly generated : %s \n",client.email);

        if (! Check_user())return;
        break;

        case 2:
        if (! Check_user())return;
        printf("...Editing profile...\n");

         printf("Enter your first name: ");
        scanf(" %[^\n]" , client.name);

        printf("Enter your second name: ");
        scanf(" %[^\n]" , client.prenom);

        sprintf(client.email, "%s%s@Client.com", client.name, client.prenom);
        printf("The email is automaticly generated after the editing :  %s \n ",client.email);
        break;

        case 3:
        if (! Check_user())return;
        printf("\n...Client Profile...\n");


        printf("Client ID = %i.\n" , client.idClient);
        printf("First name = %s.\n" ,client.name );
        printf("Second name = %s.\n" , client.prenom);
        printf("Email = %s.\n" ,client.email );

        break;
    
        default:
        printf("Invalid choice\n");
        break;
    }



}
void Gestion_du_Solde_Virtuel(){
     
    if (! Check_user())return;
   
    

    float Buy_Product;
    int Choise_Sold;
    float Amount;
   

    printf("=== Virtual balance management ===\n");
    printf("=== Enter a choice ===\n");

    printf("1.Topping up the virtual balance\n");
    printf("2. Displaying the available amount\n");
    printf("3.Checking your balance before each purchaset\n");

    printf("enter a number : ");
    scanf("%i" , &Choise_Sold);

    switch (Choise_Sold)
    {
    case 1:

    printf(" Enter the balance number you want to recharge: \n");
    scanf("%f" , &Amount);
    client.solde += Amount;

    printf(" The Balance %.2f is added successfully.\n" ,client.solde);
    break;

    case 2:
    printf(" The Balance is: %.2f.\n" , client.solde);
    break;

    case 3:
         
    printf("enter the price of the product that you want to buy: ");
    scanf("%f" , &Buy_Product);
   
    if (Buy_Product <= client.solde)
         {
            printf("your balance is enough for buy process\n");
         }

         else
         {
            printf("your balance is not enough for buy process\n");
         }
    
    default:
    printf("Invalid choice");
    break;
    }
    


}


void Catalogue_des_Produits(){

if (! Check_user())return;
int Choice_product;
char search[20];
char Search_for_Product[20];
int found=0;




printf("=== Products Catalog ===\n");
printf("=== Enter a choice ===\n");

printf("1.Product list with prices and stock\n");
printf("2.to product Search category\n");
printf("3.Product By price Sorting By price descending\n");
printf("4.Product Details\n");
    
printf("enter a number : ");
scanf("%i" , &Choice_product);
   


    
switch (Choice_product)
    {
    case 1:

         for (int i = 0; i < 5 ; i++)
        {
            printf("product p%s | name = %s | prix = %2.f | stock = %i.\n" ,product[i].idProduit,product[i].nom,product[i].prix,product[i].stock);
        }
        break;

    case 2:
       for (int i = 0; i < 5; i++)
       {
        printf("The avaliable categories are : %s\n" , product[i].categorie);
       }
       
      
      printf("Enter the categorie of the product that you want to find:");
         scanf(" %[^\n]" , search);

        for (int i = 0; i < 5; i++)
        {
            if (strcmp (product[i].categorie , search) == 0)
            {
                printf("the product %s is found in %s categorie." ,product[i].nom,product[i].categorie);
                found = 1;
            }
            
        }
        
        if (!found)
        {
            printf("the product is not on the list.\n");
        }
        break;

        case 3:
            printf("Sorting prices By price descending\n");
       
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 4-i; j++)
            {
                if (product[j].prix < product[j+1].prix)
            {
                     Products Min_num = product[j];
                     product[j] = product[j+1];
                     product[j+1] = Min_num ;
            }

            }
            
            
        }

          printf("Sorting prices By price descending:\n");

            for (int i = 0; i < 5; i++)
            {
                printf("product p%s | name=%s | prix=%.2f \n" ,product[i].idProduit,product[i].nom,product[i].prix);
            }
            break;

            case 4:
          printf("enter the id of the product.\n");
         scanf("%s" , Search_for_Product);
        for (int i = 0; i < 5; i++)
        {
            if (strcmp (product[i].idProduit , Search_for_Product) == 0)
            {
                printf("the product = %s.\n  name= %s.\n  categorie= %s.\n  prix=%.2f.\n  stock=%i.\n  description=%s.\n " , product[i].idProduit,product[i].nom,product[i].categorie,product[i].prix,product[i].stock,product[i].description);
                found =1;
            }
        } 

        if (!found)
        {
            printf("the product is not on the list.");   
        
        }
        break;
    default:
    printf("Invalid choice");
        break;
    }


}


void Processus_dAchat(){

if (! Check_user())return;


char Choice_from_the_catalog[10]; 
int Confirm;
int found=0;
int Mark=-1;
int Quantity;

 printf("enter the Id of the product that you want to buy:");
 scanf("%s" , Choice_from_the_catalog);

for (int i = 0; i < 5; i++)
{
    if (strcmp (product[i].idProduit , Choice_from_the_catalog)==0)
    {
        printf("The product is found : %s | product name : %s | product categorie : %s | price : %2.f | stock : %i | description : %s\n " 
         , product[i].idProduit, product[i].nom , product[i].categorie , product[i].prix , product[i].stock , product[i].description);

         Mark=i;
         found = 1;

         printf("Do you want to purchase this product\n");
          printf("1.Yes || 2.No");
           scanf("%i" , &Confirm);
           break;
        } 
    }
    
     if (!found)
    {
        printf("The product is not on the menu\n");
        return;
        
    }

        switch (Confirm)
        {
        case 1:
              
             printf("Enter the quantity you need");
             scanf("%i" , &Quantity);


            if (product[Mark].stock > 0 && client.solde >= (product[Mark].prix * Quantity))
            {
                product[Mark].stock -= Quantity;
                client.solde -= product[Mark].prix * Quantity;
                printf("The purchase was completed successfully.");
                printf("you buy : %s | product: %s| price: %.2f | " , product[Mark].idProduit, product[Mark].nom, product[Mark].prix);
            }
        


        else if (product[Mark].stock <= 0)
        {
            printf("Sorry this product is out .");
        }

        else
       {
           printf("Sorry your balance is not enough.");
       }
           
            break;

            case 2:
             printf("Thank you! we will take you to the main selection board.");
             break;
        default:
        printf("Invalid choice");
            break;
        }

}


void purchasing_statistics(){
    if (! Check_user())return;
int Total_sold[5];
printf("=== Your statistics ===\n");

for (int i = 0; i < 5; i++)
{
   Total_sold[i]= Current_stock[i] - product[i].stock;
}

int Max_sold=Total_sold[0];
int Max_product=0;
for (int i = 1; i < 5; i++)
{
    if (Total_sold[i] > Max_sold)
    {
        Max_sold = Total_sold[i];
        Max_product = i;
    }
    
}

int Min_sold=Total_sold[0];
int Min_product=0;
for (int j = 1; j < 5; j++)
{
    if (Total_sold[j] < Min_sold)
    {
        Min_sold = Total_sold[j];
        Min_product = j;
    }
    
}

printf("The most registered product in the purchase list is : %s | Sold value : %i\n" ,product[Max_product].nom,Max_sold);
printf("The mlowest registered product in the purchase list is : %s | sold value : %i\n" ,product[Min_product].nom,Min_sold);

printf("---Sold---\n");
printf("User sold : %2.f\n" ,client.solde);

printf("---Stock---\n");
for (int i = 0; i < 5; i++)
{
    printf("Product stock = Product name : %s | stock : %i\n" ,product[i].nom,product[i].stock);
}



}


int main (){

   int Choices; 
   for (int i = 0; i < 5; i++)
   {
     Current_stock[i] = product[i].stock;
   }
   
  
   
    
   do
   {



    
    printf("=== CUSTOMER PURCHASE SYSTEM ===\n");
    printf("=== Enter a choice ===\n");

    printf("1.Gestion du profil client\n");
    printf("2.Gestion du solde virtuel\n");
    printf("3.Consultation des produits\n");
    printf("4.Effectuer un achat\n");
    printf("5.Mes statistiques\n");
    printf("0.Quitter l'application\n");

    scanf("%i" , &Choices);
    
    switch (Choices)
    {
    case 1 :Gestion_de_profil_client(); break;
    case 2 :Gestion_du_Solde_Virtuel(); break;
    case 3 :Catalogue_des_Produits(); break;
    case 4 :Processus_dAchat(); break;
    case 5 :purchasing_statistics(); break;
        
    default:
        break;
    }

   } while (Choices!=0);
   



}





