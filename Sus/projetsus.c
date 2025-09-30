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







void Gestion_de_profil_client( ){


int Profile_Choice;


    printf("=== Gestion du profil client ===\n");
       printf("=== Enter a choice ===\n");

    printf("1.Profile creation\n");
    printf("2.Editing profile\n");
    printf("3.profile consultation\n");

    printf("enter a number\n");
    scanf("%i" , &Profile_Choice);

    if (Profile_Choice == 1)
    {
         printf("...Profile creation...\n");

        printf("Enter your first name: ");
        scanf("%s" , client.name);

        printf("Enter your second name: ");
        scanf("%s" , client.prenom);

        client.idClient =1;
        client.solde = 0;
         
        sprintf(client.email, "%s%s@Client.com", client.name, client.prenom);
        printf("The email is automaticly generated : %s \n",client.email);
    }
    
    else if (Profile_Choice == 2)
    {

        printf("...Editing profile...\n");

         printf("Enter your first name: ");
        scanf("%s" , client.name);

        printf("Enter your second name: ");
        scanf("%s" , client.prenom);

        sprintf(client.email, "%s%s@Client.com", client.name, client.prenom);
        printf("The email is automaticly generated after the editing :  %s \n ",client.email);
        
    }
    
else if (Profile_Choice == 3)
{
    printf("\n...Client Profile...\n");


     printf("Client ID = %i.\n" , client.idClient);
     printf("First name = %s.\n" ,client.name );
     printf("Second name = %s.\n" , client.prenom);
     printf("Email = %s." ,client.email );


}



}
void Gestion_du_Solde_Virtuel(){
    float Buy_Product;
    int Choise_Sold;
    float Amount;
   

     printf("=== Virtual balance management ===\n");
       printf("=== Enter a choice ===\n");

    printf("1.Topping up the virtual balance\\n");
    printf("2. Displaying the available amount\n");
    printf("3.Checking your balance before each purchaset\n");

    printf("enter a number\n");
    scanf("%i" , &Choise_Sold);
    
     if (Choise_Sold == 1)
    {
         printf(" Enter the balance number you want to recharge: \n");
         scanf("%f" , &Amount);
        client.solde += Amount;

         printf(" The Balance %.2f is added successfully.\n" ,client.solde);

    }
    
    else if (Choise_Sold == 2)
    {

        printf(" The Balance is: %.2f.\n" , client.solde);
      
    }
    
else if (Choise_Sold == 3)
{
    printf("enter the price of the product that you want to buy\n");
     scanf("%f" , &Buy_Product);
   
         if (Buy_Product <= client.solde)
         {
            printf("your balance is enough for buy process\n");
         }

         else
         {
            printf("your balance is not enough for buy process\n");
         }
         
}

}


void Catalogue_des_Produits(){
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
    

    scanf("%i" , &Choice_product);
    printf("enter a number\n");


    

    if (Choice_product == 1)
    {
        for (int i = 0; i < 5 ; i++)
        {
            printf("product p%s , name=%s , prix=%2.f , stock=%i.\n" ,product[i].idProduit,product[i].nom,product[i].prix,product[i].stock);
        }
    }
    
    if (Choice_product == 2)
    {
        printf("enter the categorie of the product that you want to find\n");
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
    }
    
    
    

    if (Choice_product == 3)
    {
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
                printf("product p%s \n name=%s \n prix=%.2f \n" ,product[i].idProduit,product[i].nom,product[i].prix);
            }
    }
    
    if (Choice_product == 4)
    {
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

        
        
    }
    
   
    

}




int main (){

   int Choices; 
   
    
   do
   {



    
    printf("=== CUSTOMER PURCHASE SYSTEM ===\n");
    printf("=== Enter a choice ===\n");

    printf("1.Gestion du profil client\n");
    printf("2.Gestion du solde virtuel\n");
    printf("3.Consultation des produits\n");
    printf("4.Effectuer un achat\n");
    printf("5.Quitter l'application\n");

    scanf("%i" , &Choices);
    
    switch (Choices)
    {
    case 1 :Gestion_de_profil_client(); break;
    case 2 :Gestion_du_Solde_Virtuel(); break;
    case 3 :Catalogue_des_Produits(); break;
        
    default:
        break;
    }

   } while (Choices!=5);
   



}





