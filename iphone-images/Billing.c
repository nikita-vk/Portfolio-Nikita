#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define GST 0.09
#define SGT 0.09

typedef struct{ 
    char name[40];
    int quantity;
}invoicept1;

typedef struct {
    char itemname[40];
    int quantity;
    float  price;
}invoicept2;

void geninvoice(void);
void showinvoice(void);
void searchinvoice(void);
char savefile(char);


int main()
{
    char input[10];
    int option;
        
    printf("   ==========Nikki's Restaurant==========   \n");
    printf("What you would like to do today:\n");

    while(1)
    {
        
        printf("1. Generate invoice\n2. Show all invoices\n3. Search invoice\n4. Exit\n");
        printf("Enter your choice: ");

        if (fgets(input, sizeof(input), stdin)!=NULL)
        {
            if(sscanf(input, "%d", &option) !=1)
            {
                printf("\a");
                fflush(stdout);
                printf("Oops! Try again by entering the number corresponding to your desired option\n") ;
                continue;
            }
            if (option==4)
            {
                break;
            }


            switch (option){
                case 1:
                geninvoice();
                break;
                case 2:
                showinvoice();
                break;
                case 3:
                searchinvoice();
                break;
                default:
                printf("\a");
                fflush(stdout);
                printf("Oops! Try again by entering the number corresponding to your desired option \n");
                break;
            }
            

        }
           
        
        
    }
    return 0;
}


void geninvoice()
{ 
    invoicept1 personalinfo;
    invoicept2 iteminfo[20];
    int i;
    time_t t;
    struct tm *tm_info;
    char buffer[37],
        yesorno;
    float runsum=0,
        discount=0,
        discounted=0;
    FILE *file;
    

    file=fopen("invoices.txt", "a");
        
    time(&t);
    tm_info=localtime(&t);
    strftime(buffer, 37, "Date: %Y/%m/%d\nTime: %H:%M:%S", tm_info);


    printf("Enter customer name: ");
    fgets(personalinfo.name, sizeof(personalinfo.name), stdin);
    printf("Enter the number of items: ");
    scanf("%d", &personalinfo.quantity);
    while (getchar() != '\n'); 
    for (i=1; i<=personalinfo.quantity;i++)
        {
        printf("Enter item name: ");
        fgets(iteminfo[i].itemname, sizeof(iteminfo[i].itemname), stdin);
        size_t len=strlen(iteminfo[i].itemname);
        if (len>0 && iteminfo[i].itemname[len-1]=='\n')
        {
            iteminfo[i].itemname[len-1]='\0';
        }
        printf("Enter item quantity: ");
        scanf("%d", &iteminfo[i].quantity);
        while (getchar() != '\n'); 
        printf("Enter the price of the item: ");
        scanf("%f", &iteminfo[i].price);
        while (getchar() != '\n'); 
        }
    printf("Would you like to add a discount? [y/n]");
    scanf("%c", &yesorno);
    while (getchar() != '\n'); 
    if (yesorno=='y')
    {
        printf("How much Discount?");
        scanf("%f", &discount);
        while (getchar() != '\n'); 
    }
else 
    {
        printf("ok\n");
    }


    printf("INVOICE\n");
    printf("   ==========Nikki's Restaurant==========   \n");
    printf("Invoice to: %s\n", personalinfo.name);
    printf("%s\n", buffer);
    printf("--------------------------------------------\n");
    printf( "Items          Qty                  Total\n");
    printf("--------------------------------------------\n");
    for (i=1; i<=personalinfo.quantity; i++)
    {
    printf("%s            %d                 %.2f", iteminfo[i].itemname, iteminfo[i].quantity, iteminfo[i].price*iteminfo[i].quantity);
    printf("\n");
    runsum=runsum+(iteminfo[i].price*iteminfo[i].quantity);
    }
    discounted=(discount/100.0)*runsum;
    printf("--------------------------------------------\n");
    printf("SUBTOTAL                                %.2f\n", runsum);
    printf("Discount @%.2f%%                          %.2f\n", discount, discounted);
    printf("                                         ----\n");
    printf("Net Total:                                %.2f\n",runsum-discounted);
    printf("GST @9%%                                  %.2f\n", GST*(runsum-discounted));
    printf("sGT @9%%                                  %.2f\n", SGT*(runsum-discounted));
    printf("--------------------------------------------\n");
    printf("Grand Total                               %.2f\n", (runsum-discounted)+ (GST*(runsum-discounted))+(SGT*(runsum-discounted)));
    printf("--------------------------------------------\n\n");
    printf("Would you like to save this invoice? [y/n]");
    scanf("%c", &yesorno);
    while (getchar() != '\n'); 
    if (savefile(yesorno)=='y')
    {   
        fprintf(file,"   ==========Nikki's Restaurant==========   \n");
        fprintf(file,"Invoice to: %s\n", personalinfo.name);
        fprintf(file,"%s\n", buffer);
        fprintf(file,"--------------------------------------------\n");
        fprintf( file,"Items          Qty                  Total\n");
        fprintf(file,"--------------------------------------------\n");
         for (i=1; i<=personalinfo.quantity; i++)
        {
        fprintf(file,"%s            %d                     %.2f", iteminfo[i].itemname, iteminfo[i].quantity, iteminfo[i].price*iteminfo[i].quantity);
        fprintf(file,"\n");
    
        }
        fprintf(file,"SUBTOTAL                                %.2f\n", runsum);
        fprintf(file,"Discount @%.2f%%                          %.2f\n", discount, discounted);
        fprintf(file,"                                         ----\n");
        fprintf(file,"Net Total:                                %.2f\n",runsum-discounted);
        fprintf(file,"GST @9%%                                  %.2f\n", GST*(runsum-discounted));
        fprintf(file,"sGT @9%%                                  %.2f\n", SGT*(runsum-discounted));
        fprintf(file,"--------------------------------------------\n");
        fprintf(file,"Grand Total                               %.2f\n", (runsum-discounted)+ (GST*(runsum-discounted))+(SGT*(runsum-discounted)));
        fprintf(file,"--------------------------------------------\n");
        fprintf(file, "End\n");
        printf("invoice successfully saved!\n");
        
    }
else 
    if (yesorno='n')
    {
        printf("ok\n");
    }

    fclose(file);
    return ;

}

char savefile(char yesorno)
{
    char yn=yesorno;
    if (yn=='y' || yn=='Y')
    {
        return 'y';
    }
else 
    if (yn=='n' || yn=='N')
    {
        return 'n';

    }
else 
    {printf("Oops! please enter 'y' for yes and 'n' for no.\n");
    scanf("%c", &yn);
    
        savefile(yn);
    }
   
}

void showinvoice()
{   
    FILE *file;
    char c;
    file=fopen("invoices.txt", "r");

    c=fgetc(file);
    while (c!=EOF)
    {   
        printf("%c", c);
        c=fgetc(file);
    }
    fclose(file);
    return ;
}

void searchinvoice()
{
    char invoicename[40],
        c[20]="Nikki's Restaurant",
        e[4]="End",
        d;
    int i,
    f;
    char line[256];
    int line_number = 1;
    int found = 0,
    anotherfound=0;
    FILE *file;
    file=fopen("invoices.txt", "r");
    

   
    printf("Please enter the name of the person's invoice: ");
    fgets(invoicename,sizeof(invoicename), stdin);
    invoicename[strcspn(invoicename,"\n")]='\0';
    
    
     while(1)
     
      { 
    
        
           if (!fgets(line, sizeof(line), file)) {
        break; 
           }
        {
            if (strstr(line, invoicename)) 
        {
            
            found = 1;
            printf("%s", line);
            fgets((line),sizeof(line), file);
            while(!strstr(line,c))
            {
                fgets(line,sizeof(line), file);
                printf("%s", line);
                
                if (strstr(line,e))
                {
                    break;
                }

            }

            fclose(file);
            
        }
         
         
            
        
        
         
        
        }
      }

    if (!found) {
        printf("String '%s' is not found in the file.\n", invoicename);
       
        }

      

    return ;
}