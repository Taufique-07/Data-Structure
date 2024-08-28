#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include "info.h"

struct account//account details
{
    char username[22];
    char number[13];
    char pin[7];
    float balance;
    struct account* next;
    struct account* prev;
};

struct account* head = NULL;
struct account* tail = NULL;
struct account* current=NULL;
struct account*user;

struct history //for transaction history
{
    char item[25];
    char id[9];
    float amount;
    struct history* next;

};
struct history* top = NULL;

struct history* temp;
struct history* newnode;

struct ticket //Buy ticket
{
    char name[21];
    char location[20];
    struct ticket* next;
    struct ticket* prev;
};

struct ticket* beg=NULL;
struct ticket* last=NULL;
struct ticket* seat;
struct ticket* mark;

//function declaration
void ask();
void startup();
void create();
void login();
void options();
void checkBalance();
void sendMoney();
void cashOut();
void mobileRecharge();
void payment();
void pay();
void payment();
void payBill();
void transferMoney();
void otherServices();
void history(float y);
void game();
void wordGuessing();
void numberGuessing();
void transaction();
void output();
void dlt();
void buyticket();
void purchase();
void ticketinfo();
void choice();
void cancel();
void addticket();
void saveAccounts();
void loadAccounts();
void saveHistory();
void loadHistory();
void addUser(struct account* new_user);
void addTransaction(struct history* new_transaction);


int padding = 30;
char number[12];
char pin[7];
char transactionID[9];
float y;
char x[25];
char seatnum[2];
float cost=0.00;


void ask()
{
    int num;
     printf("\n\n\n%*s1.Go Back to option. ", padding, "");
     printf("\n%*s2.Exit.\n", padding, "");
     printf("\n%*sEnter your Choice :  ", padding, "");
     scanf("%d",&num);

    switch(num)
    {
    case 1:
        options();
    case 2:
        printf("%*s\nExiting FlyCash. Thank you for using FlyCash!\n",padding, "");
        exit(0);
    default :
         system("cls");
         printf("\n%*sInvalid Choice.", padding, "");
         system("pause");
         ask();
    }
}


void startup()
{

    system("cls");
    printf("\n\n\n\n\n\n\n\n");

    printf("%*s*******************************************************************\n", padding, "");
    printf("%*s############      FlyCash - Where Cash Takes Flight        ########\n", padding, "");
    printf("%*s*******************************************************************\n", padding, "");
    printf("%*s*                                                                 *\n", padding, "");
    printf("%*s*        Manage your finances anytime, anywhere!                  *\n", padding, "");
    printf("%*s*           Fly with FlyCash and soar to new heights.             *\n", padding, "");
    printf("%*s*                                                                 *\n", padding, "");
    printf("%*s*                  Choose an option below:                        *\n", padding, "");
    printf("%*s*                                                                 *\n", padding, "");
    printf("%*s*   1. Login                                                      *\n", padding, "");
    printf("%*s*   2. Create Account                                             *\n", padding, "");
    printf("%*s*   3. Exit                                                       *\n", padding, "");
    printf("%*s*                                                                 *\n", padding, "");
    printf("%*s*******************************************************************\n", padding, "");
    printf("\n%*sEnter your choice: ", padding, "");
    int start;
    scanf("%d", &start);

    switch(start)
    {
       case 1:
           login();
           break;
       case 2:
           create();
           break;
       case 3:
           printf("%*s\nExiting FlyCash. Thank you for using FlyCash!\n",padding, "");
           exit(0);
       default :
           printf("%*sWrong Choice !\n",padding, "");
           system("pause");
           startup();
    }
}

void create()
{
    system("cls");

    printf("\n\n\n\n\n\n\n\n");

    printf("%*s*******************************************************************\n", padding, "");
    printf("%*s############      FlyCash - Where Cash Takes Flight        ########\n", padding, "");
    printf("%*s*******************************************************************\n", padding, "");
    printf("%*s*                                                                 *\n", padding, "");
    printf("%*s*        Manage your finances anytime, anywhere!                  *\n", padding, "");
    printf("%*s*           Fly with FlyCash and soar to new heights.             *\n", padding, "");
    printf("%*s*                                                                 *\n", padding, "");
    printf("%*s*                  Create a new account:                          *\n", padding, "");
    printf("%*s*                                                                 *\n", padding, "");
    printf("%*s*******************************************************************\n", padding, "");

    struct account* new1 = (struct account*)malloc(sizeof(struct account));

    if (new1 == NULL)
        {
        printf("Memory allocation failed.\n");
        system("pause");
        create();
        return;
        }

    printf("\n%*sEnter Username : ", padding, "");
    scanf("%21s",&new1->username);

    printf("%*sEnter mobile number : ", padding, "");
    scanf("%11s",&new1->number);

    if (strlen(new1->number) != 11 || strncmp(new1->number, "01", 2) != 0)
        {
        printf("%*sInvalid mobile number format.\n", padding, "");
        free(new1);
        system("pause");
        startup();
        return;
        }

    printf("%*sSet a PIN: ", padding, "");
    scanf("%6s",new1->pin);
    printf("%*sRe-enter PIN: ", padding, "");
    char temp[7];
    scanf("%6s",temp);

    if(strlen(new1->pin) != 6 || strcmp(new1->pin,temp)!=0)
    {
       printf("%*sPIN must contain 6 digits and match the re-entered PIN.\n", padding, "");//verification of PIN
       free(new1);
      system("pause");
      startup();
      return;
    }

    else
    {
    new1->balance = 5000.00;
    new1->next = NULL;
    new1->prev = NULL;

    if (head == NULL)
        {
        head = tail = new1;
        }
    else
    {
        tail->next = new1;
        new1->prev = tail;
        tail = new1;
    }
     saveAccounts();
}
    //current=new1;
    printf("%*sAccount created successfully.\n", padding, "");
    printf("%*sYou Got 5000 TK as Opening Rewords.\n", padding, "");
    printf("Account is ready for login. \n");
    transaction();
    strcpy(x,"Reword! ");
    float amount = 5000;
    history(amount);

    system("pause");//pause the system;
    system("cls");

    startup();
}

void login()
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n");

    printf("%*s*******************************************************************\n", padding, "");
    printf("%*s############      FlyCash - Where Cash Takes Flight        ########\n", padding, "");
    printf("%*s*******************************************************************\n", padding, "");
    printf("%*s*                                                                 *\n", padding, "");
    printf("%*s*        Manage your finances anytime, anywhere!                  *\n", padding, "");
    printf("%*s*           Fly with FlyCash and soar to new heights.             *\n", padding, "");
    printf("%*s*                                                                 *\n", padding, "");
    printf("%*s*                  Login to your account:                         *\n", padding, "");
    printf("%*s*                                                                 *\n", padding, "");
    printf("%*s*                                                                 *\n", padding, "");
    printf("%*s*******************************************************************\n", padding, "");

    printf("%*sEnter mobile number: ", padding, "");
    scanf("%11s",number);

    printf("%*sEnter pin: ", padding, "");
    scanf("%6s",pin);
    current=head;
    while(current!=NULL)
    {
        if(strcmp(current->number, number) == 0 && strcmp(current->pin, pin) == 0)
         {
             options();
         }
         current=current->next;

         loadAccounts();
    }
     printf("%*sInvalid mobile number or password.\n", padding, "");
     printf("%*sPlease Login again.\n", padding, "");
     system("pause");
     login();
     return;
}

void options()
{
    system("cls");
    current = head;
    while (current != NULL)
    {
        if (strcmp(current->number, number) == 0 && strcmp(current->pin, pin) == 0)
            {
            printf("%*sLogin successful.\n", padding, "");
            printf("\n%*sWelcome, %s!\n", padding, "", current->username);
            printf("\n%*sWhat would you like to do?\n", padding, "");
            printf("%*s1. Check Balance\n", padding, "");
            printf("%*s2. Send Money\n", padding, "");
            printf("%*s3. Cash Out\n", padding, "");
            printf("%*s4. Mobile Recharge\n", padding, "");
            printf("%*s5. Payment\n", padding, "");
            printf("%*s6. Transfer Money\n", padding, "");
            printf("%*s7. Other Services\n", padding, "");
            printf("%*s8. Play Game\n", padding, "");
            printf("%*s9. Exit\n", padding, "");

            int choice;
            printf("\n%*sEnter your choice: ", padding, "");
            scanf("%d", &choice);

            switch(choice)
            {
                case 1:
                    checkBalance();
                    ask();
                case 2:
                    sendMoney();
                    ask();
                case 3:
                    cashOut();
                    ask();
                case 4:
                    mobileRecharge();
                    ask();
                case 5:
                    pay();
                    ask();
                case 6:
                    transferMoney();
                    ask();
                case 7:
                    otherServices();
                    ask();
                case 8:
                    game();
                    ask();
                case 9:
                    printf("\n%*sExiting FlyCash. Thank you for using FlyCash!\n", padding, "");
                   startup();

                //exit(0);
                default:
                    printf("\n%*sInvalid choice. Please try again.\n", padding, "");
                    options();
            }
            current=head;
            }
        current = current->next;
    }
}

void checkBalance()
{
    system("cls");

    printf("\n\n\n\n\n\n\n\n");
    printf("%*s*******************************************************************\n", padding, "");
    printf("%*s############      FlyCash - Where Cash Takes Flight        ########\n", padding, "");
    printf("%*s*******************************************************************\n", padding, "");
    printf("%*s*                                                                 *\n", padding, "");
    printf("%*s*        Manage your finances anytime, anywhere!                  *\n", padding, "");
    printf("%*s*           Fly with FlyCash and soar to new heights.             *\n", padding, "");
    printf("%*s*                                                                 *\n", padding, "");
    printf("%*s*                  Check Balance:                                 *\n", padding, "");
    printf("%*s*                                                                 *\n", padding, "");
    printf("%*s*******************************************************************\n", padding, "");

    char checkpin[7];
    printf("%*sEnter PIN to Verify: ", padding, "");
    scanf("%6s", checkpin);
    getchar();

    if (strcmp(current->pin, checkpin) != 0)
    {
       printf("%*sInvalid PIN. Access denied.\n", padding, "");
       checkBalance();
       return;
    }
    else
    {
       printf("%*sCurrent balance: %.2f\n", padding, "", current->balance);
    }

}

void sendMoney()
{
    system("cls");

    float amount;

    // Print the header
    printf("\n\n\n\n\n\n\n\n");
    printf("%*s*******************************************************************\n", padding, "");
    printf("%*s############      FlyCash - Where Cash Takes Flight        ########\n", padding, "");
    printf("%*s*******************************************************************\n", padding, "");
    printf("%*s*                                                                 *\n", padding, "");
    printf("%*s*        Manage your finances anytime, anywhere!                  *\n", padding, "");
    printf("%*s*           Fly with FlyCash and soar to new heights.             *\n", padding, "");
    printf("%*s*                                                                 *\n", padding, "");
    printf("%*s*                     Send Money:                                 *\n", padding, "");
    printf("%*s*                                                                 *\n", padding, "");
    printf("%*s*******************************************************************\n", padding, "");

    // Print the current balance and prompt for the amount to send
    printf("\n%*s*********** Send Money ***********\n", padding, "");
    printf("%*s Current Balance: %.2f\n", padding, "", current->balance);
    printf("%*s***********************************\n", padding, "");

    printf("%*sEnter amount to send: ", padding, "");
    scanf("%f", &amount);

    // Validate the amount
    if (amount <= 0)
    {
        printf("%*sInvalid amount. Please enter a positive amount.\n", padding, "");
        system("pause");
        return; // Exit function after invalid input
    }

    if (amount > current->balance)
    {
        printf("%*sInsufficient balance.\n", padding, "");
        system("pause");
        return; // Exit function after insufficient balance
    }

    // Prompt for recipient's mobile number
    char recipient[12];
    printf("%*sEnter recipient's mobile number: ", padding, "");
    scanf("%11s", recipient);
    getchar();

    struct account* find = head;
    while (find != NULL)
    {
        if (strcmp(find->number, recipient) == 0)
        {
            // Prompt for PIN
            char checkpin[7];
            printf("%*sEnter PIN to Verify: ", padding, "");
            scanf("%6s", checkpin);
            getchar();

            // Validate PIN
            if (strcmp(current->pin, checkpin) != 0)
            {
                printf("%*sInvalid PIN. Access denied.\n", padding, "");
                system("pause");
                return; // Exit function after invalid PIN
            }

            // Process the transaction
            current->balance -= amount;
            find->balance += amount; // Update recipient's account balance

            printf("%*s%.2f successfully sent to %s.\n", padding, "", amount, recipient);
            printf("\n%*sTransaction completed.\n", padding, "");
            printf("%*sCurrent Balance: %.2f\n", padding, "", current->balance);

            // Record the transaction
            transaction();
            strcpy(x, "Send_money");

            printf("%*sTransaction ID: %s\n", padding, "", transactionID);
            history(amount);
            ask();
            return; // Exit function after successful transaction
        }
        find = find->next;
    }

    // If no matching recipient is found after the loop
    printf("%*sRecipient's account not found. Please check the mobile number.\n", padding, "");
    sendMoney();
}


void cashOut()
{
    system("cls");

    float amount;
    float serviceCharge;

    printf("\n\n\n\n\n\n\n\n");
    printf("%*s*******************************************************************\n", padding, "");
    printf("%*s############      FlyCash - Where Cash Takes Flight        ########\n", padding, "");
    printf("%*s*******************************************************************\n", padding, "");
    printf("%*s*                                                                 *\n", padding, "");
    printf("%*s*        Manage your finances anytime, anywhere!                  *\n", padding, "");
    printf("%*s*           Fly with FlyCash and soar to new heights.             *\n", padding, "");
    printf("%*s*                                                                 *\n", padding, "");
    printf("%*s*                        Cash Out                                 *\n", padding, "");
    printf("%*s*                                                                 *\n", padding, "");
    printf("%*s*******************************************************************\n", padding, "");

    printf("\n%*s*********** Cash Out ***********\n", padding, "");
    printf("%*s Current Balance: %.2f\n", padding, "", current->balance);
    printf("%*s*********************************\n", padding, "");

    printf("%*sEnter amount to cash out: ", padding, "");
    scanf("%f", &amount);

    if (amount <= 0)
    {
        printf("%*sInvalid amount. Please enter a positive amount.\n", padding, "");
        system("pause");
        cashOut();
        return;
    }

    if (amount >= current->balance)
    {
        printf("%*sInsufficient balance. Service Charge or Current Balance is not Sufficient ! \n", padding, "");
        system("pause");
        cashOut();
        return;
    }

    char checkpin[7];
    printf("%*sEnter PIN to Verify: ", padding, "");
    scanf("%6s",&checkpin);
    getchar();

    if (strcmp(current->pin, checkpin) != 0)
    {
        printf("%*sInvalid PIN. Access denied.\n", padding, "");
        system("pause");
        cashOut();
        return;
    }

    if (strcmp(current->pin, checkpin) == 0)
    {
        serviceCharge = amount * 0.005;
        if(amount + serviceCharge > current->balance)
        {
            printf("%*sInsufficient balance. Service Charge or Current Balance is not Sufficient ! \n", padding, "");
            system("pause");
            cashOut();
            return;
        }
    }

    current->balance -= (amount + serviceCharge);

    printf("%*s%.2f successfully cashed out.\n", padding, "", amount);
    printf("%*sService charge : %.2f\n", padding, "", serviceCharge);
    printf("%*sCurrent Balance: %.2f\n", padding, "", current->balance);
    transaction();
    printf("%*sTransaction ID: %s\n", padding, "", transactionID);
    strcpy(x,"Cash-Out");
    history(amount);
}

void mobileRecharge()
{
    system("cls");

    float amount;

    printf("\n\n\n\n\n\n\n\n");
    printf("%*s*******************************************************************\n", padding, "");
    printf("%*s############      FlyCash - Where Cash Takes Flight        ########\n", padding, "");
    printf("%*s*******************************************************************\n", padding, "");
    printf("%*s*                                                                 *\n", padding, "");
    printf("%*s*        Manage your finances anytime, anywhere!                  *\n", padding, "");
    printf("%*s*           Fly with FlyCash and soar to new heights.             *\n", padding, "");
    printf("%*s*                                                                 *\n", padding, "");
    printf("%*s*                    Mobile Recharge                             *\n", padding, "");
    printf("%*s*                                                                 *\n", padding, "");
    printf("%*s*******************************************************************\n", padding, "");

    printf("\n%*s*********** Mobile Recharge ***********\n", padding, "");
    printf("%*s Current Balance: %.2f\n", padding, "", current->balance);
    printf("%*s***************************************\n", padding, "");

    printf("%*sEnter amount for recharge: ", padding, "");
    scanf("%f", &amount);

    if (amount < 0)
    {
        printf("%*sInvalid amount. Please enter a positive amount.\n", padding, "");
        system("pause");
        mobileRecharge();
        return;
    }

    if (amount > current->balance)
    {
        printf("%*sInsufficient balance.\n", padding, "");
        system("pause");
        mobileRecharge();
        return;
    }

    char mobileNumber[12];
    printf("%*sEnter mobile number to recharge: ", padding, "");
    scanf("%11s",&mobileNumber);

    char checkpin[7];
    printf("%*sEnter PIN to Verify: ", padding, "");
    scanf("%6s",&checkpin);
    getchar(); // Consume the newline character left in the buffer

    if (strcmp(current->pin, checkpin) != 0)
    {
        printf("%*sInvalid PIN. Access denied.\n", padding, "");
        system("pause");
        mobileRecharge();
        return;
    }

    if (strcmp(current->pin, checkpin) == 0)
    {
        current->balance -= amount;

        printf("%*s%.2f successfully recharged for %s.\n", padding, "", amount, mobileNumber);
        printf("%*sCurrent Balance: %.2f\n", padding, "", current->balance);
        transaction();
        printf("%*sTransaction ID: %s\n", padding, "", transactionID);
        strcpy(x,"Mobile_Recharge");
        history(amount);
    }
}

void pay()
{
    int choice;
    system("cls");

    printf("\n\n\n\n\n\n\n\n");
    printf("%*s*******************************************************************\n", padding, "");
    printf("%*s############      FlyCash - Where Cash Takes Flight        ########\n", padding, "");
    printf("%*s*******************************************************************\n", padding, "");
    printf("%*s*                                                                 *\n", padding, "");
    printf("%*s*        Manage your finances anytime, anywhere!                  *\n", padding, "");
    printf("%*s*           Fly with FlyCash and soar to new heights.             *\n", padding, "");
    printf("%*s*                                                                 *\n", padding, "");
    printf("%*s*                          Pay                                    *\n", padding, "");
    printf("%*s*                                                                 *\n", padding, "");
    printf("%*s*******************************************************************\n", padding, "");

    printf("\n%*s1. Payment\n", padding, "");
    printf("%*s2. Pay Bill\n", padding, "");
    printf("\n%*sEnter your choice: ", padding, "");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            payment();
            break;
        case 2:
            payBill();
            break;
        default:
            printf("%*sInvalid choice.\n", padding, "");
            system("pause");
            pay();
    }
}

void payment()
{
    system("cls");

    float amount;

    printf("\n\n\n\n\n\n\n\n");
    printf("%*s*******************************************************************\n", padding, "");
    printf("%*s############      FlyCash - Where Cash Takes Flight        ########\n", padding, "");
    printf("%*s*******************************************************************\n", padding, "");
    printf("%*s*                                                                 *\n", padding, "");
    printf("%*s*        Manage your finances anytime, anywhere!                  *\n", padding, "");
    printf("%*s*           Fly with FlyCash and soar to new heights.             *\n", padding, "");
    printf("%*s*                                                                 *\n", padding, "");
    printf("%*s*                       Payment                                   *\n", padding, "");
    printf("%*s*                                                                 *\n", padding, "");
    printf("%*s*******************************************************************\n", padding, "");

    printf("\n%*s*********** Payment ***********\n", padding, "");
    printf("%*s Current Balance: %.2f\n", padding, "", current->balance);
    printf("%*s***************************************\n", padding, "");

    printf("%*sEnter Payment amount: ", padding, "");
    scanf("%f", &amount);

    if (amount <= 0)
    {
        printf("%*sInvalid amount. Please enter a positive amount.\n", padding, "");
        system("pause");
        payment();
        return;
    }
    if (amount >= current->balance)
    {
        printf("%*sInsufficient balance.\n", padding, "");
        system("pause");
        payment();
        return;
    }

    char checkpin[7];
    printf("%*sEnter PIN to Verify: ", padding, "");
    scanf("%6s", &checkpin);
    getchar();

    if (strcmp(current->pin, checkpin) != 0)
    {
        printf("%*sInvalid PIN. Access denied.\n", padding, "");
        system("pause");
        payment();
        return;
    }
    if(strcmp(current->pin, checkpin) == 0)
    {
        // charge check
        if (amount + 10 > current->balance)
        {
            printf("%*sInsufficient balance for payment including service charge.\n", padding, "");
            system("pause");
            payment();
            return;
        }

        current->balance -= (amount+10);

        printf("%*s%.2f successfully paid.\n", padding, "", amount);
        printf("%*sService charge : 10Tk \n", padding, "");
        printf("%*sCurrent Balance: %.2f\n", padding, "", current->balance);
        transaction();
        printf("%*sTransaction ID: %s\n", padding, "", transactionID);
        strcpy(x, "Payment     ");
        history(amount);
    }
}

void payBill()
{
    system("cls");

    float amount;
    float charge;

    printf("\n\n\n\n\n\n\n\n");
    printf("%*s*******************************************************************\n", padding, "");
    printf("%*s############      FlyCash - Where Cash Takes Flight        ########\n", padding, "");
    printf("%*s*******************************************************************\n", padding, "");
    printf("%*s*                                                                 *\n", padding, "");
    printf("%*s*        Manage your finances anytime, anywhere!                  *\n", padding, "");
    printf("%*s*           Fly with FlyCash and soar to new heights.             *\n", padding, "");
    printf("%*s*                                                                 *\n", padding, "");
    printf("%*s*                        Pay Bill                                 *\n", padding, "");
    printf("%*s*                                                                 *\n", padding, "");
    printf("%*s*******************************************************************\n", padding, "");

    printf("\n%*s*********** Pay Bill ***********\n", padding, "");
    printf("%*s Current Balance: %.2f\n", padding, "", current->balance);
    printf("%*s*********************************\n", padding, "");

    printf("%*sEnter amount to Pay Bill: ", padding, "");
    scanf("%f", &amount);

    if (amount <= 0)
    {
        printf("%*sInvalid amount. Please enter a positive amount.\n", padding, "");
        system("pause");
        payBill();
        return;
    }
    if (amount > current->balance)
    {
        printf("%*sInsufficient balance.\n", padding, "");
        system("pause");
        payBill();
        return;
    }

    char checkpin[7];
    printf("%*sEnter PIN to Verify: ", padding, "");
    scanf("%6s",&checkpin);
    getchar();

    if (strcmp(current->pin, checkpin) != 0)
    {
        printf("%*sInvalid PIN. Access denied.\n", padding, "");
        system("pause");
        payBill();
        return;
    }
    if(strcmp(current->pin, checkpin) == 0)
    {
        charge = amount * 0.005;

        if (amount + charge > current->balance)
        {
            printf("%*sInsufficient balance for payment including service charge.\n", padding, "");
            system("pause");
            payBill();
            return;
        }

        current->balance -= (amount + charge);

        printf("%*s%.2f successfully paid bill.\n", padding, "", amount);
        printf("%*sService charge : %.2f\n", padding, "", charge);
        printf("%*sCurrent Balance: %.2f\n", padding, "", current->balance);
        transaction();
        printf("%*sTransaction ID: %s\n", padding, "", transactionID);
        strcpy(x,"Pay-Bill.");
        history(amount);
    }
}

void transferMoney()
{
    system("cls");

    float amount;
    char recipient[17];

    printf("\n\n\n\n\n\n\n\n");
    printf("%*s*******************************************************************\n", padding, "");
    printf("%*s############      FlyCash - Where Cash Takes Flight        ########\n", padding, "");
    printf("%*s*******************************************************************\n", padding, "");
    printf("%*s*                                                                 *\n", padding, "");
    printf("%*s*        Manage your finances anytime, anywhere!                  *\n", padding, "");
    printf("%*s*           Fly with FlyCash and soar to new heights.             *\n", padding, "");
    printf("%*s*                                                                 *\n", padding, "");
    printf("%*s*                     Transfer Money                              *\n", padding, "");
    printf("%*s*                                                                 *\n", padding, "");
    printf("%*s*******************************************************************\n", padding, "");

    printf("\n%*s*********** Transfer Money ***********\n", padding, "");
    printf("%*s Current Balance: %.2f\n", padding, "", current->balance);
    printf("%*s***************************************\n", padding, "");

    // Input transfer type
    printf("%*sChoose transfer type:\n", padding, "");
    printf("%*s1. Add Money\n", padding , "");
    printf("%*s2. Bank Transfer\n", padding , "");
    printf("%*sEnter your choice: ", padding, "");
    int type;
    scanf("%d", &type);

    switch (type)
    {
        case 1:
            // Input amount to add
            printf("%*sEnter amount to add: ", padding, "");
            scanf("%f", &amount);
            printf("%*sEnter Bank Account : ", padding, "");
            scanf("%16s",&recipient);

            if (amount <= 0)
            {
                printf("%*sInvalid amount. Please enter a positive amount.\n", padding, "");
                system("pause");
                transferMoney();
                return;
            }

            char checkpin[7];
            printf("%*sEnter PIN to Verify: ", padding, "");
            scanf("%6s", &checkpin);
            getchar();

            if (strcmp(current->pin, checkpin) != 0)
            {
               printf("%*sInvalid PIN. Access denied.\n", padding, "");
               system("pause");
               transferMoney();
               return;
            }

            if (strcmp(current->pin, checkpin) == 0)
            {
                 current->balance += amount;

                printf("%*s%.2f successfully added to your Account from your bank.\n", padding, "", amount);
                printf("%*sCurrent Balance: %.2f\n", padding, "", current->balance);
                transaction();
                printf("%*sTransaction ID: %s\n", padding, "", transactionID);
                strcpy(x,"Add_Money");
                history(amount);
            }
            ask();

        case 2:
            printf("%*sEnter amount to transfer: ", padding, "");
            scanf("%f", &amount);

            if (amount <= 0)
            {
                printf("%*sInvalid amount. Please enter a positive amount.\n", padding, "");
                system("pause");
                transferMoney();
                return;
            }
            if (amount >= current->balance)
            {
                printf("%*sInsufficient balance.\n", padding, "");
                system("pause");
                transferMoney();
                return;
            }

            printf("%*sEnter Bank Account : ", padding, "");
            scanf("%16s",&recipient);
            char checkpin2[7];
            printf("%*sEnter PIN to Verify: ", padding, "");
            scanf("%6s", &checkpin2);
            getchar();

            if (strcmp(current->pin, checkpin2) != 0)
            {
               printf("%*sInvalid PIN. Access denied.\n", padding, "");
               system("pause");
               transferMoney();
               return;
            }

            if (strcmp(current->pin, checkpin2) == 0)
            {
                float serviceCharge = amount * 0.005;
                if (amount + serviceCharge > current->balance)
                {
                   printf("%*sInsufficient balance for payment including service charge.\n", padding, "");
                   system("pause");
                   transferMoney();
                   return;
                }

                 current->balance -= (amount + serviceCharge);

                 printf("%*s%.2f successfully transferred to %s.\n", padding, "", amount, recipient);
                 printf("%*sService Charge (0.5%%): %.2f\n", padding, "", serviceCharge);
                 printf("%*sCurrent Balance: %.2f\n", padding, "", current->balance);
                 transaction();
                 printf("%*sTransaction ID: %s\n", padding, "", transactionID);
                 strcpy(x,"Transfer_Money");
                 history(amount);
            }
            ask();

        default:
            printf("%*sInvalid choice. Please try again.\n", padding, "");
            system("pause");
            transferMoney();
    }
}

void otherServices()
{
    system("cls");

    printf("\n\n\n\n\n\n\n\n");
    printf("%*s*******************************************************************\n", padding, "");
    printf("%*s############      FlyCash - Where Cash Takes Flight        ########\n", padding, "");
    printf("%*s*******************************************************************\n", padding, "");
    printf("%*s*                                                                 *\n", padding, "");
    printf("%*s*        Manage your finances anytime, anywhere!                  *\n", padding, "");
    printf("%*s*           Fly with FlyCash and soar to new heights.             *\n", padding, "");
    printf("%*s*                                                                 *\n", padding, "");
    printf("%*s*                     Other Services                              *\n", padding, "");
    printf("%*s*                                                                 *\n", padding, "");
    printf("%*s*******************************************************************\n", padding, "");

    printf("\n%*s1. Transaction History\n", padding, "");
    printf("%*s2. Buy Tickets\n", padding, "");
    printf("%*s3. Delete Account\n", padding, "");

    printf("\n%*sEnter your choice: ", padding, "");
    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            output();
            ask();
        case 2:
            printf("%*sWelcome To E-ticket .\n", padding, "");
            buyticket();
            ask();
        case 3:
            dlt();
        default:
            printf("\n%*sInvalid choice. Please try again.\n", padding, "");
            system("pause");
            otherServices();
    }
}

void game()
{
    system("cls");
    int choice;

    printf("\n\n\n\n\n\n\n\n");
    printf("%*s***********************************\n", padding, "");
    printf("%*s************ Game Menu ***********\n", padding, "");
    printf("%*s***********************************\n", padding, "");
    printf("%*s1. Word Guessing\n", padding, "");
    printf("%*s2. Number Guessing\n", padding, "");
    printf("%*s3. Go back\n", padding, "");
    printf("\n%*sEnter your choice: ", padding, "");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            wordGuessing();
            ask();
        case 2:
            numberGuessing();
            ask();
        case 3:
           ask();
        default:
            printf("\n%*sInvalid choice. Please try again.\n", padding, "");
            system("pause");
            game();
    }
}

void wordGuessing()
{
    system("cls");
    char word[] = "Flycash";
    char guess[20];
    int count = 0;
    int limit = 3;
    int chance = 0;

    printf("%*sGuess the word. (You have 3 lives)\n", padding, "");

    while (strcmp(guess, word) != 0 && !chance)
        {
        if (count < limit)
        {
            printf("%*s%d lives left\n", padding, "", limit-count);
            printf("%*sEnter a Guess: ", padding, "");
            scanf("%s", guess);
            count++;
            system("cls");
        }
         else
          {
            chance = 1;
          }
    }

    if (chance)
        {
        printf("%*sGet your brain to work, loser!\n", padding, "");
        system("pause");
        ask();
    }
    else
        {
        printf("%*sYou Win!!!\n", padding, "");
        system("pause");
        ask();
        }
}

void numberGuessing()
{
    int guess, ran;
    const int limit = 3;

    printf("%*sWelcome to the Number Guessing Game!\n", padding, "");
    printf("%*sI've selected a random number between 1 and 20.\n", padding, "");
    printf("%*sYou have %d attempts to guess the number.\n", padding, "", limit);

    ran = rand() % 20 + 1;

    for (int i = limit; i > 0; i--)
        {
        printf("%*sEnter your Guess (%d lives left): ", padding, "", i);
        scanf("%d", &guess);
        system("cls");

        if (guess == ran)
            {
            printf("%*sCongratulations! You guessed the correct number. You win!\n", padding, "");
            options();
            }
        else
            {
            printf("%*sTry again\n", padding, "");
            }
    }
    printf("%*sGet your Brain to work, loser!!!!\n", padding, "");
    printf("%*sThe number was %d\n", padding, "", ran);
    ask();
}

void transaction()
{
    char charset[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i < 8; i++)
        {
        int index = rand() % 36;
        transactionID[i] = charset[index];
    }
}

void history(float y)
{
    struct history* new_transaction = (struct history*)malloc(sizeof(struct history));
    newnode = (struct history*) malloc(sizeof(struct history));
    if(newnode==NULL)
    {
        printf("%*s Unfortunate Error! Try again later!\n", padding);
        ask();
        return;
    }

    newnode->next=NULL;
    strcpy(newnode->item,x);
    strcpy(newnode->id,transactionID);
    newnode->amount = y;
    newnode->next=top;
    top=newnode;
    addTransaction(new_transaction);
    saveHistory();
}

void output()
{
    system("cls");

    printf("\n\n\n\n\n\n\n\n");
    printf("%*s*******************************************************************\n", padding, "");
    printf("%*s############      FlyCash - Where Cash Takes Flight        ########\n", padding, "");
    printf("%*s*******************************************************************\n", padding, "");
    printf("%*s*                                                                 *\n", padding, "");
    printf("%*s*        Manage your finances anytime, anywhere!                  *\n", padding, "");
    printf("%*s*           Fly with FlyCash and soar to new heights.             *\n", padding, "");
    printf("%*s*                                                                 *\n", padding, "");
    printf("%*s*                 Transaction History                             *\n", padding, "");
    printf("%*s*                                                                 *\n", padding, "");
    printf("%*s*******************************************************************\n", padding, "");
    printf("\n\n\n");

    temp=top;
    if(temp==NULL)
      {
         printf("%*s You don't have any transaction history right now! Do transaction to se transaction history!\n", padding, "",mark->name);
      }
    printf("Transaction type\t\tTransaction Id\t\t\tAmount\n");
    while(temp!=NULL)
    {
        printf("\n%s\t\t\t%s\t\t\t%.2f TK\n",temp->item,temp->id,temp->amount);
        temp=temp->next;
    }
}

void dlt()
{
    system("cls");

    printf("\n\n\n\n\n\n\n\n");

    printf("%*s*******************************************************************\n", padding, "");
    printf("%*s############         Thank you For Using FlyCash           ########\n", padding, "");
    printf("%*s*******************************************************************\n", padding, "");
    printf("%*s*                                                                 *\n", padding, "");
    printf("%*s*                                                                 *\n", padding, "");
    printf("%*s*                       Account Deletion:                         *\n", padding, "");
    printf("%*s*                                                                 *\n", padding, "");
    printf("%*s*                                                                 *\n", padding, "");
    printf("%*s*                                                                 *\n", padding, "");
    printf("%*s*******************************************************************\n", padding, "");
     printf("%*sProcessing Account Deletion \n", padding, "");
     char number[12];
     printf("%*sEnter your Number : ", padding, "");
     scanf("%11s",&number);

     char pin[7];
     printf("%*sEnter pin: ", padding, "");
     scanf("%6s",&pin);

     current=head;
     while(current!=NULL)
     {
          if(strcmp(current->number, number) == 0 && strcmp(current->pin, pin) == 0)
           {
               if(current->prev!=NULL)
               {
                  current->prev->next=current->next;
               }
               else
               {
                   head=current->next;
               }
                if(current->next!=NULL)
                 {
                current->next->prev=current->prev;
                 }
                 free(current);
                 printf("%*sAccount Deletion Completed! \n", padding, "");
                 printf("%*sReturning to Startup.\n", padding, "");
                 system("pause");
                 startup();
             }
            current=current->next;
    }
         printf("%*sInvalid mobile number or password.\n", padding, "");
         printf("%*sDeletion Failed! Please Try again.\n", padding, "");
         system("pause");
         dlt();

}

void buyticket()
{
    int num,n;

    printf("%*sEnter number of tickets you want to buy: ", padding, "");

    scanf("%d",&num);

    while(num--)
    {
        seat = (struct ticket*)malloc(sizeof(struct ticket));
        if (seat == NULL)
          {
            printf("Memory allocation failed.\n");
            system("pause");
            buyticket();
          }
          system("cls");
    printf("%*sSelect your Ticket here :   \n", padding, "");
    printf("%*s1. Cox's Bazar \t\t    -1200 Tk\n", padding, "");
    printf("%*s2. Kuakata     \t\t    -1000 Tk\n", padding, "");
    printf("%*s3. Sylhet      \t\t    -1000 Tk\n", padding, "");
    printf("%*s4. Rajshahi    \t\t    -900 Tk\n", padding, "");
    printf("%*s5. Rangamati   \t\t    -900 Tk\n", padding, "");
    printf("%*s6. Sundorbon   \t\t    -1100 Tk\n", padding, "");
    printf("%*s7. Nikli       \t\t    -700 Tk\n", padding, "");
        char name[21];
        printf("%*sEnter Passenger name : ", padding, "");
        scanf("%21s",&name);

        char location[15];
        printf("%*sEnter Destination choice : ", padding, "");
        scanf("%d",&n);
     switch(n)
      {
        case 1:
            seat->next=NULL;
            seat->prev=NULL;
            strcpy(seat->name,name);
            strcpy(seat->location,"Cox's Bazar");

          if(beg==NULL)
          {
              beg=mark=seat;
              last=mark;
          }
          else
          {
              mark->next=seat;
              seat->prev=mark;
              mark=seat;
              last=mark;
          }
          cost+=1200;
           break;
        case 2:
           seat->next=NULL;
           seat->prev=NULL;
           strcpy(seat->name,name);
           strcpy(seat->location,"Kuakata");

          if(beg==NULL)
          {
              beg=mark=seat;
              last=mark;
          }
          else
          {
              mark->next=seat;
              seat->prev=mark;
              mark=seat;
              last=mark;
          }
          cost+=1000;
          break;
        case 3:
            seat->next=NULL;
            seat->prev=NULL;
            strcpy(seat->name,name);
            strcpy(seat->location,"Sylhet");

          if(beg==NULL)
          {
              beg=mark=seat;
              last=mark;
          }
          else
          {
              mark->next=seat;
              seat->prev=mark;
              mark=seat;
              last=mark;
          }
          cost+=1000;
          break;
        case 4:
            seat->next=NULL;
            seat->prev=NULL;
            strcpy(seat->name,name);
            strcpy(seat->location,"Rajshahi");

          if(beg==NULL)
          {
              beg=mark=seat;
              last=mark;
          }
          else
          {
              mark->next=seat;
              seat->prev=mark;
              mark=seat;
              last=mark;
          }
          cost+=900;
          break;
        case 5:
            seat->next=NULL;
            seat->prev=NULL;
            strcpy(seat->name,name);
            strcpy(seat->location,"Rangamati");

          if(beg==NULL)
          {
              beg=mark=seat;
              last=mark;
          }
          else
          {
              mark->next=seat;
              seat->prev=mark;
              mark=seat;
              last=mark;
          }
          cost+=900;
          break;
        case 6:
            seat->next=NULL;
            seat->prev=NULL;
            strcpy(seat->name,name);
            strcpy(seat->location,"Sundorbon");

          if(beg==NULL)
          {
              beg=mark=seat;
              last=mark;
          }
          else
          {
              mark->next=seat;
              seat->prev=mark;
              mark=seat;
              last=mark;
          }
          cost+=1100;
          break;
        case 7:
            seat->next=NULL;
            seat->prev=NULL;
            strcpy(seat->name,name);
            strcpy(seat->location,"Nikli");

          if(beg==NULL)
          {
              beg=mark=seat;
              last=mark;
          }
          else
          {
              mark->next=seat;
              seat->prev=mark;
              mark=seat;
              last=mark;
          }
          cost+=700;
          break;

        default:
            printf("%*sInvalid Choice!\n", padding, "");
            system("pause");
            choice();
    }
  }
  choice();
}

void purchase()
{
     system("cls");

    float charge;
    printf("\n%*s*********** Ticket Purches **********\n", padding, "");
    printf("%*s Current Balance: %.2f\n", padding, "", current->balance);
    printf("%*s***************************************\n", padding, "");

    printf("%*sYour total payable = %.2f", padding, "",cost);
    if (cost <= 0)
    {
        printf("%*sInvalid amount. Please enter a positive amount.\n", padding, "");
        system("pause");
        payment();
        return;
    }
    if (cost >= current->balance)
    {
        printf("%*sInsufficient balance.\n", padding, "");
        system("pause");
        payment();
        return;
    }

    char checkpin[7];
    printf("\n");
    printf("%*sEnter PIN to Verify: ", padding, "");
    scanf("%6s",&checkpin);

    if (strcmp(current->pin, checkpin) != 0)
    {
        printf("%*sInvalid PIN. Access denied.\n", padding, "");
        system("pause");
        payment();
        return;
    }
     if (strcmp(current->pin, checkpin) == 0)
    {
        charge = cost + 10;
        if(cost + charge > current->balance)
        {
           current->balance -= (cost + charge);

           printf("%*s%.2f successfully paid.\n", padding, "", cost);
           printf("%*sService charge : 10TK\n", padding, "");
           printf("%*sCurrent Balance: %.2f\n", padding, "", current->balance);
           transaction();
           printf("%*sTransaction ID: %s\n", padding, "", transactionID);
           strcpy(x,"Ticket Purchase");
           history(cost);
           system("pause");

        }
    }
    ticketinfo();
}

void ticketinfo()
{
    system("cls");
    mark=beg;
    while(mark!=NULL)
    {
        printf("%*sPassenger name : %s\n", padding, "",mark->name);
        printf("%*sDestination : %s\n", padding, "",mark->location);
        mark=mark->next;
    }
    ask();
}

void choice()
{
    int m;
    printf("%*s 1. Cancel Ticket.\n", padding, "");
    printf("%*s 2. Add Ticket.\n", padding, "");
    printf("%*s 3. Confirm Purchase.\n", padding, "");
    printf("%*sEnter your choice : ", padding, "");
    scanf("%d",&m);

    switch(m)
    {
        case 1:
            cancel();
            ticketinfo();
            choice();
        case 2:
           addticket();
           choice();
        case 3:
            purchase();
            ask();
        default:
            printf("%*sInvalid Choice!\n", padding, "");
            system("pause");
            choice();
    }

}

void cancel()
{
    char name[21];
    printf("%*s    Enter name of the Passenger wanna cancel Ticket : ", padding, "");
    scanf("%21s",&name);

    mark=beg;
    while(mark!=NULL)
    {
        if(strcmp(mark->name, name) == 0)
        {
             if(mark->prev!=NULL)
             {
                 mark->prev->next=mark->next;
             }

             else
             {
                 beg=beg->next;
             }

             if(mark->next!=NULL)
             {
                 mark->next->prev=mark->prev;
             }
             free(mark);
             printf("%*sTicket has been Canceled !\n", padding, "");
             printf("%*sWaiting for Conformation to Confirm the ticket.\n", padding, "");
             system("pause");
        }
        mark=mark->next;
    }
}

void addticket()
{
    buyticket();
}

void saveAccounts()
{
    FILE *file = fopen("accounts.dat", "w");

    if (file == NULL)
        {
        printf("Error opening file for writing.\n");
        return;
    }

    struct account* current = head;
    while (current != NULL) {
        fwrite(current, sizeof(struct account), 1, file);
        current = current->next;
    }

    fclose(file);
}

void loadAccounts()
{
    FILE *file = fopen("accounts.dat", "r");
    if (file == NULL)
        {
        printf("Error opening file for reading.\n");
        return;
        }

    struct account temp;
    while (fread(&temp, sizeof(struct account), 1, file))
        {
        struct account* new_user = (struct account*)malloc(sizeof(struct account));
        *new_user = temp;
        new_user->next = NULL;
        new_user->prev = NULL;
        addUser(new_user);
    }

    fclose(file);
}

void saveHistory() {
    FILE *file = fopen("history.dat", "w");
    if (file == NULL)
        {
        printf("Error opening file for writing.\n");
        return;
    }

    struct history* current = top;
    while (current != NULL) {
        fwrite(current, sizeof(struct history), 1, file);
        current = current->next;
    }

    fclose(file);
}

void loadHistory()
{
    FILE *file = fopen("history.dat", "r");
    if (file == NULL)
        {
        printf("Error opening file for reading.\n");
        return;
        }

    struct history temp;
    while (fread(&temp, sizeof(struct history), 1, file))
        {
        struct history* new_transaction = (struct history*)malloc(sizeof(struct history));
        *new_transaction = temp;
        new_transaction->next = NULL;
        addTransaction(new_transaction);
    }

    fclose(file);
}

void addUser(struct account* new_user)
 {
    if (head == NULL)
        {
        head = tail = new_user;
    }
    else
        {
        tail->next = new_user;
        new_user->prev = tail;
        tail = new_user;
    }
}

void addTransaction(struct history* new_transaction)
 {
    new_transaction->next = top;
    top = new_transaction;
}


int main()
{
    startup();
    system("cls");
    return 0;
}

