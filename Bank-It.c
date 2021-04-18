#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int account_number=100000;
void deposit(int);
void debit(int);
void amounttransfer(int);
void balance_enquiry(int);
void transaction_history(int);
void profile(int);
struct custumer_data
{
    char name[40];
    char password[12];
    int age;
    char gender;
    int balance;
    struct history* transaction;
}datas[1000];
struct history
{
    char credit[5][100];
    char debit[5][100];
};
void deposit(int accountnumber)
{
    printf("Enter the ammount to be deposited:\n");
    int amount;
    scanf("%d",&amount);
    if(amount<1){
        printf("Invalid amount\n");
        return;
    }
    datas[accountnumber-100001].balance=datas[accountnumber-100001].balance+amount;
    printf("Your balance is %d\n",datas[accountnumber-100001].balance);
}
void debit(int accountnumber)
{
    printf("Your balance is %d",datas[accountnumber-100001].balance);
    printf("Enter the ammount to be debited:\n");
    int amount;
    scanf("%d",&amount);
    while(amount>(datas[accountnumber-100001].balance)-2500){
        printf("enter the amount less the %d\n",(datas[accountnumber-100001].balance-2500));
        printf("Enter the ammount to be debited:\n");
        scanf("%d",&amount);
    }
    datas[accountnumber-100001].balance=datas[accountnumber-100001].balance-amount;
    printf("Your balance is %d\n",datas[accountnumber-100001].balance);
}
void balance_enquiry(int accountnumber)
{
    printf("\n\nYour balance is %d\n",datas[accountnumber-100001].balance);
}
void amounttransfer(int accountnumber)
{
    printf("Enter the account number to which you need to transfer:\n");
    int transferaccountnumber;
    scanf("%d",&transferaccountnumber);
    while(transferaccountnumber<100001 || transferaccountnumber>account_number)
    {
        printf("INVALID ACCOUNT NUMBER\n");
        printf("Enter a valid account number:\n");
        scanf("%d",&transferaccountnumber);
    }
    printf("The account holder name: %s\n",datas[transferaccountnumber-100001].name);
    printf("Enter the ammount to be transfered:\n");
    int amount;
    scanf("%d",&amount);
    while(amount>(datas[accountnumber-100001].balance)-2500){
        printf("enter the amount less the %d\n",(datas[accountnumber-100001].balance-2500));
        printf("Enter the amount to be transfered:\n");
        scanf("%d",&amount);
    }
    datas[transferaccountnumber-100001].balance+=amount;
    datas[accountnumber-100001].balance-=amount;
    printf("\n\n                Transaction sucessfull              \n\n");
    //printf("Your balance is %d\n",datas[accountnumber-100001].balance);
}
void transaction_history(int accountnumber)
{
    printf("\nThis future will be coded soon........\n");
}
void profile(int accountnumber)
{
    printf("\nName: %s\n",datas[accountnumber-100001].name);
    printf("Age: %d\n",datas[accountnumber-100001].age);
    printf("Gender: %c",datas[accountnumber-100001].gender);
}

void login()
{
    int accountnumber,choice;
    char password[15];
    printf("Enter your account number:\n");
    scanf("%d",&accountnumber);
    while(accountnumber<100001 || accountnumber>account_number)
    {
        printf("INVALID ACCOUNT NUMBER if you dont have account create it:\n");
        printf("Enter a valid account number:\n");
        scanf("%d",&accountnumber);
    }
    printf("Enter your password:\n");
    scanf("%s",password);
    while(strcmp(datas[accountnumber-100001].password,password)!=0)
       {
           printf("PASSWORD NOT MATCHED\n");
           printf("Enter your password:\n");
           scanf("%s",password);
       }
       printf("\n\nLOGIN SUCCESSFULL:)\n\n");
       printf("WELCOME YOU %s\n",datas[accountnumber-100001].name);
       int terminate=1;
       do{
       printf("1.deposit\n2.debit\n3.balance_enquiry\n4.amounttransfer\n5.transaction history\n6.profile\n");
       scanf("%d",&choice);
       switch(choice)
       {
       case 1:
        deposit(accountnumber);
        break;
       case 2:
        debit(accountnumber);
        break;
       case 3:
        balance_enquiry(accountnumber);
        break;
       case 4:
        amounttransfer(accountnumber);
        break;
       case 5:
        transaction_history(accountnumber);
       case 6:
        profile(accountnumber);
        break;
        dafault:
            printf("Invalid input");
       }
       printf("\n\nEnter 0 to LOGOUT\n");
       scanf("%d",&terminate);
       }while(terminate);
}
int checkforpassword(char* password)
{
    int len=strlen(password),g=0,k=0,l=0;
    if(len<8)
        return 1;
    else
        for(int i=0;i<len;i++)
        {
            if(isupper(password[i]))
                g=1;
            if(islower(password[i]))
                k=1;
            if(isdigit(password[i]))
                l=1;
            if(g && k && l)
                return 0;
        }
        return 1;
}
void createNewAccount()
{
    int tempbalance;
    account_number++;
    char temppassword[14];
    printf("\n          We are very gladfull of seeing you in your family              \n");
    printf("Enter your name:\n");
    scanf("%s",(datas[account_number-100001].name));
    printf("Enter your age:\n");
    scanf("%d",&(datas[account_number-100001].age));
    printf("Enter your Gender:\nM-male\nF-female\nT-transgender\n");
    scanf(" %c",&(datas[account_number-100001].gender));

    printf("The minimum balance should be 2500,Enter your Initial deposit\n");
    scanf("%d",&tempbalance);
    while(tempbalance<2500){
        printf("The ammount is insufficient????\n");
        printf("The minimum balance **MUST** be 2500,Enter your Initial deposit\n");
        scanf("%d",&tempbalance);
    }
    datas[account_number-100001].balance=tempbalance;
    printf("Create your password:  should contain atleast one character and number and a upper and lower case each, min of 8 char \n");
    scanf("%s",datas[account_number-100001].password);
    while(checkforpassword(datas[account_number-100001].password))
    {
        printf("The password you entered is not strong enough\n");
        printf("Create your password:  should contain atleast one character and number and a upper and lower case each, min of 8 char \n");
        scanf("%s",datas[account_number-100001].password);
    }
    printf("    YOUR ACCOUNT NUMBER IS   %d    \n",account_number);
    printf("    PASSWORD YOU ENTERED IS   %s   \n                  YOU HAVE SUCCESSFULLY CREATED THE ACCOUNT                   \n",datas[account_number-100001].password);
}

int main()
{
    int terminate;
    do{
    int choice;
    printf("''''''''''''''''''WELCOME  BANK OF BANK''''''''''''''''''\n    1.LOGIN    \n    2.CREATE NEW ACCOUNT    \n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        login();
        break;
    case 2:
        createNewAccount();
        break;
    default:
        printf("ERROR     ENTER PROPER INPUT");
    }
    printf("\nEnter 0 to exit:");
    scanf("%d",&terminate);
    }while(terminate);
    return 0;
}

