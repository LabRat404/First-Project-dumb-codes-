









#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
int quit()
{
    exit ;
}
//Add new item record(s)
void add ()
{

    struct Record {
        char recordnumber[41];
        char itemnumber[41];
        char quantity[41];
        char weight[41];
        char itemname[41];
        char category[41];
        char recipient[41];
        char final_destination[41];
        char status[41];
    };

    FILE *sfr = fopen("stock.txt", "r");//str is a random name to open a file
    char str;
    float Total;
    int total;
    Total=0;
    //We use '\n' to know how many line there is in the txt file and calculate how many record there is in thx txt file, let us easy to modify, display, delete and search
    while (!feof(sfr))
    {
        str = fgetc(sfr);
        if(str == '\n')
        {
            Total++;
        }
    }
    Total = roundf((Total +1)/10);
    total = (int)Total;
    fclose(sfr);

    int loop;
    int looop;
    int loooop;
    int looooop;
    int bk;
    loop = total;
    int i = 0;
    int c = loop;
    looop = loop;
    loooop = loop;
    looooop = loop;
	bk = total;
    FILE *fr=fopen("stock.txt","r");
    char buffer[50];
    //see if the \n is ocuppied
    fgets(buffer, 49, fr);
    if(buffer[0] != '\n'){
        fclose(fr);
        fr=fopen("stock.txt","r");
    }
	

    struct Record rec1, rec2[c];
    while (loop != 0) {


        fgets(rec2[i].recordnumber, 50, fr);
        fgets(rec2[i].itemname, 50, fr);
        fgets(rec2[i].itemnumber, 50, fr);
        fgets(rec2[i].category, 50, fr);
        fgets(rec2[i].quantity, 50, fr);
        fgets(rec2[i].weight, 50, fr);
        fgets(rec2[i].recipient, 50, fr);
        fgets(rec2[i].final_destination, 50, fr);
        fgets(rec2[i].status, 50, fr);
        fgets(buffer, 50, fr);
        loop--;
        i++;

    }
    i=0;
	fclose(fr);


    //input here
    int test;
    test =0;
    while (1) {
        fseek(stdin, 0, SEEK_END);//clean buffer
        fflush(stdin);
        fr = fopen("stock.txt", "a");
        printf("\nPlease enter a record number for your record :");
        fgets(rec1.recordnumber, 50, stdin);
        fflush(stdin);
        fseek(stdin, 0, SEEK_END);
        while (bk!=0){
        	test = strcmp(rec2[i].recordnumber, rec1.recordnumber);
        	 if(test == 0){
        	 	break;
			 }
        	bk--;
        	i++;
		}
        if(test == 0)
        {
            printf("\nRecord number duplicated...returning to add menu\n\n");
            break;
        }
        printf("\nPlease enter an item name for your record :");
        fgets(rec1.itemname, 40, stdin);
        printf("\nPlease enter an item number for your record :");
        fgets(rec1.itemnumber, 40, stdin);
        printf("\nPlease enter a category for your record :");
        fgets(rec1.category, 40, stdin);
        printf("\nPlease enter a quantity for your record :");
        fgets(rec1.quantity, 40, stdin);
        printf("\nPlease enter a weight for your record :");
        fgets(rec1.weight, 40, stdin);
        printf("\nPlease enter a recipient for your record :");
        fgets(rec1.recipient, 40, stdin);
        printf("\nPlease enter a final destination for your record :");
        fgets(rec1.final_destination, 40, stdin);
        printf("\nPlease enter a status for your record :");
        fgets(rec1.status, 40, stdin);

        fprintf(fr,"\n%s%s%s%s%s%s%s%s%s", rec1.recordnumber, rec1.itemname, rec1.itemnumber, rec1.category, rec1.quantity, rec1.weight, rec1.recipient, rec1.final_destination, rec1.status);
        fclose(fr);

//individual
        FILE *tlfr = fopen("addlog.txt", "r");//test and check if theres a file
        if (tlfr == NULL) {
            FILE *fr = fopen("addlog.txt", "a");
            fprintf(fr, "%i", 0);
            fclose(fr);
        }
        fclose(tlfr);
        int howmany;
        FILE *lfr = fopen("addlog.txt", "r");
        fscanf(lfr,"%d", &howmany);
        FILE *nlfr = fopen("naddlog.txt", "a");
        fprintf(nlfr,"%d", howmany+1);
        char logstring[50];
        howmany = howmany + (howmany*10);
        fgets(logstring, 49, lfr);
        fprintf(nlfr,"\n", logstring);
        while(howmany!=0)
        {
            fgets(logstring, 49, lfr);
            fprintf(nlfr,"%s", logstring);

            howmany--;
        }
        fclose(lfr);
        time_t ltime = time(NULL);
        char *time_str = ctime(&ltime);
        time_str[strlen(time_str) - 1] = '\0';

        fprintf(nlfr, "\n%s\n%s%s%s%s%s%s%s%s%s", time_str, rec1.recordnumber, rec1.itemname, rec1.itemnumber,
                rec1.category,
                rec1.quantity, rec1.weight, rec1.recipient, rec1.final_destination, rec1.status);
        fclose(nlfr);
        remove("addlog.txt");
        rename("naddlog.txt","addlog.txt");
        //end of individual part for add





        printf("Do you want to add another record? Enter 'n' to quit or enter 'y' to add another :");
        char a; /* a stands for answer*/
        scanf(" %c", &a);
        if (a == 'N' || a == 'n') {
            break;
        }
    }
}


//Display item(s)
void  Display() {

    struct Record {
        char recordnumber[41];
        char itemnumber[41];
        char quantity[41];
        char weight[41];
        char itemname[41];
        char category[41];
        char recipient[41];
        char final_destination[41];
        char status[41];
    };
    char buffer[40];


    //We use '\n' to know how many line there is in the txt file and calculate how many record there is in thx txt file, let us easy to modify, display, delete and search
    FILE *sfr = fopen("stock.txt", "r");//sfr is just a random name to open a file
    char str;
    float Total;
    int total;
    Total=0;

    while (!feof(sfr))
    {
        str = fgetc(sfr);
        if(str == '\n')
        {
            Total++;
        }
    }
    Total = roundf((Total +1)/10);// using round because the stock.txt file you send us is missing a '\n' due to EOF
    total = (int)Total;
    fclose(sfr);


    struct Record rec1;
    while (1) {
        printf("Do u want to Display all Record together or one by one ? Enter 1 to display all , Enter 2 to display 1 by 1 Enter:\n");
        int d;//ask user for a selection, chose between display all or one by one
        scanf("%d",&d);
        if (d == 1) {
            while (1) {
                int loop, lop;

                loop = total;
                lop = 1;
                
                struct Record rec1;
                //This code below checks if the txt file is the one you send us or the txt file that we created by using add, edit or delete.(Format of yours and us will be different)
                
                FILE *fr = fopen("stock.txt", "r");
				fgets(buffer, 41, fr);
                if(buffer[0] != '\n'){
                    fclose(fr);
                    fr = fopen("stock.txt", "r");
                }
                fflush(stdin);
                fseek(stdin, 0, SEEK_END);
                while (loop != 0, loop--) {
                    fgets(rec1.recordnumber, 50, fr);
                    fgets(rec1.itemname, 50, fr);
                    fgets(rec1.itemnumber, 50, fr);
                    fgets(rec1.category, 50, fr);
                    fgets(rec1.quantity, 50, fr);
                    fgets(rec1.weight, 50, fr);
                    fgets(rec1.recipient, 50, fr);
                    fgets(rec1.final_destination, 50, fr);
                    fgets(rec1.status, 50, fr);
                    fgets(buffer, 50, fr);
                    printf("\nThe %d Record :\n\nRecord number : %sItem name : %sItem number : %sCategory : %sQuantity : %sWeight : %sRecipient : %sFinal Destination : %sDelivery status : %s",lop,
                           rec1.recordnumber, rec1.itemname, rec1.itemnumber, rec1.category, rec1.quantity, rec1.weight,
                           rec1.recipient, rec1.final_destination, rec1.status);
                    lop++;
                }
                fclose(fr);
                //individual
                FILE *tlfr = fopen("displayallog.txt", "r");//test and check if theres a file
                if (tlfr == NULL) {
                    fr = fopen("displayallog.txt", "a");
                    fprintf(fr, "%i", 0);
                    fclose(fr);
                }
                fclose(tlfr);
                int howmany;
                FILE *lfr = fopen("displayallog.txt", "r");
                fscanf(lfr,"%d", &howmany);
                FILE *nlfr = fopen("ndisplayallog.txt", "a");
                fprintf(nlfr,"%d", howmany+1);
                char logstring[50];
                howmany = howmany + (howmany*1);
                fgets(logstring, 49, lfr);
                fprintf(nlfr,"\n", logstring);
                while(howmany!=0)
                {

                    fgets(logstring, 49, lfr);
                    fprintf(nlfr,"%s", logstring);
                    howmany--;
                }
                fclose(lfr);
                time_t ltime = time(NULL);
                char *time_str = ctime(&ltime);
                time_str[strlen(time_str) - 1] = '\0';
                fprintf(nlfr, "\n%s\n", time_str);
                fclose(nlfr);
                remove("displayallog.txt");
                rename("ndisplayallog.txt","displayallog.txt");
                //end of individual part for display all

                printf("That's all of the record , Enter 'K' to Proceed :\n");
                char a; //Just let user know thats all of the records and let them have a "stop point"
                scanf(" %c", &a);
                printf("Do you want to read another item record(Y/N):\n");
                char aa; //ask for a choice
                scanf(" %c", &aa);
                if (aa == 'N' || aa == 'n') {
                    break;
                }
            }
        }else{
            FILE *nnnfr = fopen("stock.txt", "r");
            int lop, loop;
            loop = 0;
            lop = 1;
            fgets(buffer, 50, nnnfr);
            if(buffer[0] != '\n'){
                fclose(nnnfr);
                nnnfr = fopen("stock.txt", "r");
            }
            while (loop!=total) {

                fgets(rec1.recordnumber, 50, nnnfr);
                fgets(rec1.itemname, 50, nnnfr);
                fgets(rec1.itemnumber, 50, nnnfr);
                fgets(rec1.category, 50, nnnfr);
                fgets(rec1.quantity, 50, nnnfr);
                fgets(rec1.weight, 50, nnnfr);
                fgets(rec1.recipient, 50, nnnfr);
                fgets(rec1.final_destination, 50, nnnfr);
                fgets(rec1.status, 50, nnnfr);
                fgets(buffer, 50, nnnfr);

                printf("\nThe %d Record\n\nRecord number : %sItem name : %sItem number : %sCategory : %sQuantity : %sWeight : %sRecipient : %sFinal Destination : %sDelivery status : %s",lop, rec1.recordnumber,rec1.itemname,rec1.itemnumber,rec1.category,rec1.quantity,rec1.weight,rec1.recipient,rec1.final_destination,rec1.status);
                //individual
                FILE *tlfr = fopen("display1by1log.txt", "r");//test and check if theres a file
                if (tlfr == NULL) {
                    FILE *nnnfr = fopen("display1by1.txt", "a");
                    fprintf(nnnfr, "%i", 0);
                    fclose(nnnfr);
                }
                fclose(tlfr);
                int howmany;
                FILE *lfr = fopen("display1by1.txt", "r");
                fscanf(lfr,"%d", &howmany);
                FILE *nlfr = fopen("ndisplay1by1.txt", "a");
                fprintf(nlfr,"%d", howmany+1);

                char logstring[50];
                howmany = howmany + (howmany*10);
                fgets(logstring, 49, lfr);
                fprintf(nlfr,"\n", logstring);
                while(howmany!=0)
                {
                    fgets(logstring, 49, lfr);
                    fprintf(nlfr,"%s", logstring);

                    howmany--;
                }


                fclose(lfr);


                time_t ltime = time(NULL);
                char *time_str = ctime(&ltime);
                time_str[strlen(time_str) - 1] = '\0';
                fprintf(nlfr, "\n%s\n%s%s%s%s%s%s%s%s%s", time_str, rec1.recordnumber, rec1.itemname,
                        rec1.itemnumber,
                        rec1.category,
                        rec1.quantity, rec1.weight, rec1.recipient, rec1.final_destination, rec1.status);
                fclose(nlfr);
                remove("display1by1.txt");
                rename("ndisplay1by1.txt","display1by1.txt");
                //end of individual part for display 1 by 1



                lop++;
                loop++;
                if(loop==total){
                    printf("\nThis is the end of the file, there is nor record left....\n");
                    break;
                }
                printf("Do you want to read another item record(Y/N):\n");
                char a; //ask for a choice
                scanf(" %c", &a);
                if (a == 'N' || a == 'n') {
                    break;
                }
            }
            fclose(nnnfr);
        }
        printf("Do you want to Read files again?(Y/N):\n");
        char a; //ask for a choice
        scanf(" %c", &a);
        if (a == 'N' || a == 'n') {
            break;
        }
    }
}

void searchEngine(char*search) //using search engine and use search to call this funtion because other funtion can also use or call this funtion
{
    struct Record {
        char recordnumber[40];
        char itemnumber[40];
        char quantity[40];
        char weight[40];
        char itemname[40];
        char category[40];
        char recipient[40];
        char final_destination[40];
        char status[40];
    };
    FILE *sfr = fopen("stock.txt", "r");//str is a random name to open a file
    char str;
    float Total;
    int total;
    Total=0;
    //We use '\n' to know how many line there is in the txt file and calculate how many record there is in thx txt file, let us easy to modify, display, delete and search
    while (!feof(sfr))
    {
        str = fgetc(sfr);
        if(str == '\n')
        {
            Total++;
        }
    }
    Total = roundf((Total +1)/10);
    total = (int)Total;
    fclose(sfr);


    FILE *fr = fopen("stock.txt", "r");
    int loop;
    int loooop;
    loop = total;
    int i = 0;
    int c = loop;
    loooop = loop;
    int copy;
    copy = loop;
    fseek(stdin, 0, SEEK_END);//clean buffer
    fflush(stdin);
    struct Record rec1[c];
    size_t len;
    int j=0;
    char buffer [50];
    fgets(buffer, 50, fr);
    if(buffer[0] != '\n'){
        fclose(fr);
        fr = fopen("stock.txt", "r");
    }
    while (loop != 0, loop--)
    {

        fgets(rec1[i].recordnumber,50,fr);
        len = strlen(rec1[i].recordnumber);
        if (rec1[i].recordnumber[len -1] == '\n') { //turning '\n' to '\0' just to prevent error or effects on displaying the return results
            rec1[i].recordnumber[len -1] = '\0';
        }

        fgets(rec1[i].itemname,50,fr);
        len = strlen(rec1[i].itemname);
        if (rec1[i].itemname[len -1] == '\n') {  //turning '\n' to '\0' just to prevent error or effects on displaying the return results
            rec1[i].itemname[len -1] = '\0';
        }
        fgets(rec1[i].itemnumber,50,fr);
        len = strlen(rec1[i].itemnumber);
        if (rec1[i].itemnumber[len -1] == '\n') {//turning '\n' to '\0' just to prevent error or effects on displaying the return results
            rec1[i].itemnumber[len -1] = '\0';
        }
        fgets(rec1[i].category,50,fr);
        len = strlen(rec1[i].category);
        if (rec1[i].category[len -1] == '\n') { //turning '\n' to '\0' just to prevent error or effects on displaying the return results
            rec1[i].category[len -1] = '\0';
        }
        fgets(rec1[i].quantity,50,fr);
        len = strlen(rec1[i].quantity);
        if (rec1[i].quantity[len -1] == '\n') {  //turning '\n' to '\0' just to prevent error or effects on displaying the return results
            rec1[i].quantity[len -1] = '\0';
        }
        fgets(rec1[i].weight,50,fr);
        len = strlen(rec1[i].weight);
        if (rec1[i].weight[len -1] == '\n') {  //turning '\n' to '\0' just to prevent error or effects on displaying the return results
            rec1[i].weight[len -1] = '\0';
        }
        fgets(rec1[i].recipient,50,fr);
        len = strlen(rec1[i].recipient);
        if (rec1[i].recipient[len -1] == '\n') { //turning '\n' to '\0' just to prevent error or effects on displaying the return results
            rec1[i].recipient[len -1] = '\0';
        }
        fgets(rec1[i].final_destination,50,fr);
        len = strlen(rec1[i].final_destination);
        if (rec1[i].final_destination[len -1] == '\n') { //turning '\n' to '\0' just to prevent error or effects on displaying the return results
            rec1[i].final_destination[len -1] = '\0';
        }
        fgets(rec1[i].status,50,fr);
        len = strlen(rec1[i].status);
        if (rec1[i].status[len -1] == '\n') { //turning '\n' to '\0' just to prevent error or effects on displaying the return results
            rec1[i].status[len -1] = '\0';
        }
        fgets(buffer,50,fr);
        i++;
    }

    fclose(fr);

    int check ;
    check = strlen(search);
    len = strlen(search);   //turning '\n' to '\0' just to prevent error or effects on displaying the return results
    if (search[len] == '\n')
    {
        search[len] = '\0';
    }
    char iname[40][40];     //copy string to so 1 used to compare at lowercase and other one is used to display originally
    char icat[40][40];
    char irec[40][40];
    char ides[40][40];
    char istat[40][40];

    i=0;
    int size;
    while(copy!=0){
        strcpy(iname[i],rec1[i].itemname);
        strcpy(icat[i],rec1[i].category);
        strcpy(irec[i],rec1[i].recipient);
        strcpy(ides[i],rec1[i].final_destination);
        strcpy(istat[i],rec1[i].status);

        size = 40;
        j=0;
        while(size!=0){

            iname[i][j] = tolower(iname[i][j]);
            icat[i][j] = tolower(icat[i][j]);
            irec[i][j] = tolower(irec[i][j]);
            ides[i][j] = tolower(ides[i][j]);
            istat[i][j] = tolower(istat[i][j]);
            j++;
            size--;
        }
        i++;
        copy--;
    }
    fseek(stdin, 0, SEEK_END);//clean buffer
    search[strlen(search) - 1] = '\0';  //double check if the input from user last character is '\0' instead of '\n' from fgets
    printf("\nyou have entered :%s\n", search);
    printf("Search result:\n");
    i = 0;
    int count = 0;
    size = 40;
    while (size!=0){
        search[i] = tolower(search[i]);
        size--;
        i++;
    }
    i=0;
    while (loooop != 0) {
        Again :
        if (loooop <= 0) {
            break;
        }
        //using strstr and lowercase so i can do a similar search instead of a 100% match search
        if (strstr(rec1[i].recordnumber, search) != NULL ) {
            printf("Record number : %s\nItem name : %s\nItem number : %s\nCategory : %s\nQuantity : %s\nWeight : %s\nRecipient : %s\nFinal Destination : %s\nDelivery status : %s\n\n\n",
                   rec1[i].recordnumber, rec1[i].itemname, rec1[i].itemnumber, rec1[i].category, rec1[i].quantity,
                   rec1[i].weight,
                   rec1[i].recipient, rec1[i].final_destination, rec1[i].status);
            i++;
            loooop--;
            count++;
            goto Again;
        }
        //using strstr and lowercase so i can do a similar search instead of a 100% match search
        if (strstr(iname[i], search) != NULL ) {
            printf("Record number : %s\nItem name : %s\nItem number : %s\nCategory : %s\nQuantity : %s\nWeight : %s\nRecipient : %s\nFinal Destination : %s\nDelivery status : %s\n\n\n",
                   rec1[i].recordnumber, rec1[i].itemname, rec1[i].itemnumber, rec1[i].category, rec1[i].quantity,
                   rec1[i].weight,
                   rec1[i].recipient, rec1[i].final_destination, rec1[i].status);
            i++;
            loooop--;
            count++;
            goto Again;
        }
        //using strstr and lowercase so i can do a similar search instead of a 100% match search
        if (strstr(rec1[i].itemnumber, search) != NULL ) {
            printf("Record number : %s\nItem name : %s\nItem number : %s\nCategory : %s\nQuantity : %s\nWeight : %s\nRecipient : %s\nFinal Destination : %s\nDelivery status : %s\n\n\n",
                   rec1[i].recordnumber, rec1[i].itemname, rec1[i].itemnumber, rec1[i].category, rec1[i].quantity,
                   rec1[i].weight,
                   rec1[i].recipient, rec1[i].final_destination, rec1[i].status);
            i++;
            loooop--;
            count++;
            goto Again;
        }
        //using strstr and lowercase so i can do a similar search instead of a 100% match search
        if (strstr(icat[i], search) != NULL ) {
            printf("Record number : %s\nItem name : %s\nItem number : %s\nCategory : %s\nQuantity : %s\nWeight : %s\nRecipient : %s\nFinal Destination : %s\nDelivery status : %s\n\n\n",
                   rec1[i].recordnumber, rec1[i].itemname, rec1[i].itemnumber, rec1[i].category, rec1[i].quantity,
                   rec1[i].weight,
                   rec1[i].recipient, rec1[i].final_destination, rec1[i].status);
            i++;
            loooop--;
            count++;
            goto Again;
        }
        //using strstr and lowercase so i can do a similar search instead of a 100% match search
        if (strstr(rec1[i].quantity, search) != NULL ) {
            printf("Record number : %s\nItem name : %s\nItem number : %s\nCategory : %s\nQuantity : %s\nWeight : %s\nRecipient : %s\nFinal Destination : %s\nDelivery status : %s\n\n\n",
                   rec1[i].recordnumber, rec1[i].itemname, rec1[i].itemnumber, rec1[i].category, rec1[i].quantity,
                   rec1[i].weight,
                   rec1[i].recipient, rec1[i].final_destination, rec1[i].status);
            i++;
            loooop--;
            count++;
            goto Again;
        }
        //using strstr and lowercase so i can do a similar search instead of a 100% match search
        if (strstr(rec1[i].weight, search) != NULL ) {
            printf("Record number : %s\nItem name : %s\nItem number : %s\nCategory : %s\nQuantity : %s\nWeight : %s\nRecipient : %s\nFinal Destination : %s\nDelivery status : %s\n\n\n",
                   rec1[i].recordnumber, rec1[i].itemname, rec1[i].itemnumber, rec1[i].category, rec1[i].quantity,
                   rec1[i].weight,
                   rec1[i].recipient, rec1[i].final_destination, rec1[i].status);
            i++;
            loooop--;
            count++;
            goto Again;
        }
        //using strstr and lowercase so i can do a similar search instead of a 100% match search
        if (strstr(irec[i], search) != NULL ) {
            printf("Record number : %s\nItem name : %s\nItem number : %s\nCategory : %s\nQuantity : %s\nWeight : %s\nRecipient : %s\nFinal Destination : %s\nDelivery status : %s\n\n\n",
                   rec1[i].recordnumber, rec1[i].itemname, rec1[i].itemnumber, rec1[i].category, rec1[i].quantity,
                   rec1[i].weight,
                   rec1[i].recipient, rec1[i].final_destination, rec1[i].status);
            i++;
            loooop--;
            count++;
            goto Again;
        }
        //using strstr and lowercase so i can do a similar search instead of a 100% match search
        if (strstr(ides[i], search) != NULL ) {
            printf("Record number : %s\nItem name : %s\nItem number : %s\nCategory : %s\nQuantity : %s\nWeight : %s\nRecipient : %s\nFinal Destination : %s\nDelivery status : %s\n\n\n",
                   rec1[i].recordnumber, rec1[i].itemname, rec1[i].itemnumber, rec1[i].category, rec1[i].quantity,
                   rec1[i].weight,
                   rec1[i].recipient, rec1[i].final_destination, rec1[i].status);
            i++;
            loooop--;
            count++;
            goto Again;
        }
        //using strstr and lowercase so i can do a similar search instead of a 100% match search
        if (strstr(istat[i], search) != NULL ) {
            printf("Record number : %s\nItem name : %s\nItem number : %s\nCategory : %s\nQuantity : %s\nWeight : %s\nRecipient : %s\nFinal Destination : %s\nDelivery status : %s\n\n\n",
                   rec1[i].recordnumber, rec1[i].itemname, rec1[i].itemnumber, rec1[i].category, rec1[i].quantity,
                   rec1[i].weight,
                   rec1[i].recipient, rec1[i].final_destination, rec1[i].status);
            i++;
            loooop--;
            count++;
            goto Again;
        }
        i++;
        loooop--;
    }
    printf("returned with %d record\n", count);
    printf("Please enter 'k' to continue :");
    char a;
    scanf(" %c", &a);
    //get ready to go back to search()
}
//search part
search() {
    //separating the search engine and search so others functions like delete or modify can call search engine to allow user to comfirm the record number or the record they want to change or delete
    while (1) {
        printf("Please enter a key word of the record you wanted to search : ");
        fseek(stdin, 0, SEEK_END);
        char match[41];
        fgets(match,40,stdin);
        //individual
        FILE *tlfr = fopen("searchlog.txt", "r");//test and check if theres a file
        if (tlfr == NULL) {
            FILE *fr = fopen("searchlog.txt", "a");
            fprintf(fr, "%i", 0);
            fclose(fr);
        }
        fclose(tlfr);
        int howmany;
        FILE *lfr = fopen("searchlog.txt", "r");
        fscanf(lfr,"%d", &howmany);
        FILE *nlfr = fopen("nsearchlog.txt", "a");
        fprintf(nlfr,"%d", howmany+1);
        char logstring[50];
        howmany = howmany + (howmany*2);
        fgets(logstring, 49, lfr);
        fprintf(nlfr,"\n", logstring);
        while(howmany!=0)
        {
            fgets(logstring, 49, lfr);
            fprintf(nlfr,"%s", logstring);

            howmany--;
        }

        fclose(lfr);

        time_t ltime = time(NULL);
        char *time_str = ctime(&ltime);
        time_str[strlen(time_str) - 1] = '\0';
        fprintf(nlfr, "\n%s\n%s", time_str, match);
        fclose(nlfr);
        remove("searchlog.txt");
        rename("nsearchlog.txt","searchlog.txt");
        //end of individual part for search
        searchEngine(match);
        printf("\nDo u want to search for other record?Enter 'y' for yes and 'n' for no :");
        char a2;
        scanf(" %c", &a2);
        if (a2 == 'N' || a2 == 'n') {
            break;
        }
    }
}

void modify()
{
#define LEN 40
#define NUM 50
        char r_num[NUM][LEN];
        char i_num[NUM][LEN];
        char category[NUM][LEN];
        char quantity[NUM][LEN];
        char weight[NUM][LEN];
        char i_name[NUM][LEN];
        char recipient[NUM][LEN];
        char place[NUM][LEN];
        char status[NUM][LEN];

    FILE * outf;
    FILE * fr;
    int cnt=0;
    int item=0;
    int j;
    int i=0;
    int temp;
    char rec[NUM];
    char choice='y';
    char sure='n';
    char buffer[LEN];
    char searchrec;


    FILE *sfr = fopen("stock.txt", "r");    //get the total number of record
    char str;
    float Total;
    int total;
    Total=0;
    while (!feof(sfr))
    {
        str = fgetc(sfr);
        if(str == '\n')
        {
            Total++;
        }
    }
    Total = roundf((Total +1)/10);
    total = (int)Total;
    fclose(sfr);

    i=total;
    j=0;

    fr=fopen("stock.txt","r");

    //see if the \n is ocuppied
    fgets(buffer, 49, fr);
    if(buffer[0] != '\n'){
        fclose(fr);
        fr=fopen("stock.txt","r");
    }
    //resd the data from the data file
    while (total!=0) {

        fgets(r_num[j],LEN,fr);
        fgets(i_name[j],LEN,fr);
        fgets(i_num[j],LEN,fr);
        fgets(category[j],LEN,fr);
        fgets(quantity[j],LEN,fr);
        fgets(weight[j],LEN,fr);
        fgets(recipient[j],LEN,fr);
        fgets(place[j],LEN,fr);
        fgets(status[j],LEN,fr);
        fgets(buffer,LEN,fr);

        j++;
        total--;
    }

    fclose(fr);
    temp=0;

    printf("Do you want to search for the record number first? (modification needs you to input the record number) [y/n]");  //let user to search the record number
    fflush(stdin);
    scanf("%c",&searchrec);
    if (searchrec=='y') {
        printf("Please enter a key word of the record you wanted to search : ");
        fseek(stdin, 0, SEEK_END);
        char match[41];
        fgets(match,40,stdin);
        searchEngine(match);
    }
    printf("\nDo you want to change an item record(y/n): ");       //ask if they want to change the record
    while ((choice=='y')||(choice=='Y')) {
        fflush(stdin);						//let the user to decide whether they want to change anything
        scanf("%c",&choice);

        if ((choice=='y')||(choice=='Y'))     //start the modification
        {
            printf("Please enter record number: ");       //enter record number (as the reference to change any data)
            scanf("%s",rec);
            fflush(stdin);
            fseek(stdin, 0, SEEK_END);
            printf("How many data about this item(%s) need to be changed: ",rec);
            scanf("%d",&temp);

            for (cnt=0;cnt<51;cnt++){                     //check which record item need to be changed
                if (atoi(r_num[cnt])==atoi(rec))
                    break;
            }

            printf("=============================================\n\n");         //display the info of this record item
            printf("The record that you want to change :");
            printf("%s",r_num[cnt]);
            printf("2)  %s",i_name);
            printf("3)  %s",i_num[cnt]);
            printf("4)  %s",category[cnt]);
            printf("5)  %s",quantity[cnt]);
            printf("6)  %s",weight[cnt]);
            printf("7)  %s",recipient[cnt]);
            printf("8)  %s",place[cnt]);
            printf("9)  %s",status[cnt]);
            printf("=============================================\n");


            for (temp;temp>0;temp--) {                           //to change the data in a record item
                printf("Please enter which data you want to change(1-9): \n1) Record number, 2) Item name, 3) Item number, 4) Category, 5) Quantity\n");
                printf("6) Weight, 7) Recipient, 8) Final Destination, 9) Delivery status :");
                fseek(stdin, 0, SEEK_END);
                fflush(stdin);
                scanf("%d",&item);
                printf("Please input the change: ");
                fseek(stdin, 0, SEEK_END);
                fflush(stdin);
                if (item==1) fgets(r_num[cnt],LEN,stdin);
                else if (item==2) fgets(i_name[cnt],LEN,stdin);
                else if(item==3) fgets(i_num[cnt],LEN,stdin);
                else if(item==4) fgets(category[cnt],LEN,stdin);
                else if(item==5) fgets(quantity[cnt],LEN,stdin);
                else if(item==6) fgets(weight[cnt],LEN,stdin);
                else if(item==7) fgets(recipient[cnt],LEN,stdin);
                else if(item==8) fgets(place[cnt],LEN,stdin);
                else if(item==9) fgets(status[cnt],LEN,stdin);
                else {printf("You have a wrong input, please input again.");
                    temp++;}
            }


        } else {
            printf("This is the end for the changes. ");
            break; }
        printf("\nDo you want to change another item record(y/n): ");
    }

    //write the new data back to the txt file
    for (j=0; j<i ;j++)
    {
        outf=fopen("data.txt","a");
        fprintf(outf, "\n%s%s%s%s%s%s%s%s%s", r_num[j], i_name[j], i_num[j], category[j], quantity[j], weight[j], recipient[j], place[j],status[j]);
        fclose(outf);
    }
    remove("stock.txt");
    rename("data.txt","stock.txt");
}


int delete()
{
    while (1) {
        struct Record {
            char recordnumber[40];
            char itemnumber[40];
            char quantity[40];
            char weight[40];
            char itemname[40];
            char category[40];
            char recipient[40];
            char final_destination[40];
            char status[40];
        };
        FILE *sfr = fopen("stock.txt", "r");//str is a random name to open a file
        char str;
        float Total;
        int total;
        Total=0;
        //We use '\n' to know how many line there is in the txt file and calculate how many record there is in thx txt file, let us easy to modify, display, delete and search
        while (!feof(sfr))
        {
            str = fgetc(sfr);
            if(str == '\n')
            {
                Total++;
            }
        }
        Total = roundf((Total +1)/10);
        total = (int)Total;
        fclose(sfr);

        int loop;
        int looop;
        int loooop;
        int looooop;
        loop = total;
        int i = 0;
        int c = loop;
        looop = loop;
        loooop = loop;
        looooop = loop;

        FILE *fr=fopen("stock.txt","r");
        char buffer[50];
        //see if the \n is ocuppied
        fgets(buffer, 49, fr);
        if(buffer[0] != '\n'){
            fclose(fr);
            fr=fopen("stock.txt","r");
            printf("dont have \n");
			      }else{
        	printf("have \n");
		}
        int len;
        len =0;
        struct Record rec1[c];
        while (loop != 0) {


            fgets(rec1[i].recordnumber, 50, fr);
            fgets(rec1[i].itemname, 50, fr);
            fgets(rec1[i].itemnumber, 50, fr);
            fgets(rec1[i].category, 50, fr);
            fgets(rec1[i].quantity, 50, fr);
            fgets(rec1[i].weight, 50, fr);
            fgets(rec1[i].recipient, 50, fr);
            fgets(rec1[i].final_destination, 50, fr);
            fgets(rec1[i].status, 50, fr);
            fgets(buffer, 50, fr);
            loop--;
            i++;

        }
        int j;
        j = 0;
        fclose(fr);
        redel1:
        while (1) {
            redel:
            printf("Do you know the record number of the record you wanted to delete?\nEnter 1 if you know\nEnter 2 if you don't know\nEnter 3 if u want to quit delete\n: ");
            int a;
            scanf("%d", &a);
            if (a == 1) {
                goto start;//??not working
            } else {
                if (a == 2) {
                    while (1) {
                        printf("\nPlease searech for the record number you wanted to delete :");
                        printf("Please enter a key word of the record you wanted to search : ");
                        fseek(stdin, 0, SEEK_END);
                        char match[41];
                        fgets(match,40,stdin);
                        searchEngine(match);
                        printf("\nDid you find the record number you wanted to delete?\nEnter 1 if yes\nEnter 2 if you wish to search again\nEnter 3 to back to modify menu\n: ");
                        int aa;
                        aa = 0;
                        scanf("%d", &aa);
                        if (aa == 1) {
                            break;
                        } else {
                            if (aa == 3) {
                                goto redel;
                            }
                        }
                    }
                    goto start;
                }
                break;
            }
        }
        goto quit;
        //if enter 1 , come here
        start:
        printf("\nplease enter the record number of the record you wanted to delete : ");
        fseek(stdin, 0, SEEK_END);//clean buffer
        char search[41];
        fgets(search, 40, stdin);

        printf("\nyou have entered :%s\n", search);
        printf("Record result:\n");
        //try to ask??
        i = 0;
        int count;
        count = 0;
        int mnumber;
        mnumber = 0;
        int decide;
        decide =0;

        while (looop!=0){


            decide = strcmp(rec1[i].recordnumber, search);

            if (decide ==0){

                printf("\nRecord number:%s\nItem name: %sItem number: %sItem category: %sItem quantity: %sItem weight: %srecipient: %sfinal_destination: %sstatus: %s", rec1[i].recordnumber,rec1[i].itemname,rec1[i].itemnumber,rec1[i].category,rec1[i].quantity,rec1[i].weight,rec1[i].recipient,rec1[i].final_destination,rec1[i].status);
                mnumber = i;
                break;
            }

            i++;
            looop--;
            if(looop < 0){
                printf("\n\ntheres no such record\n\nexiting...");
                goto quit;
            }
        }


        printf("Do you want to delete this record? (The process of delete cannot be restore) Enter 'y' for yes and 'n' for no\n: ");
        char aaa;
        scanf("%c" ,&aaa);
        if (aaa == 'n' || aaa == 'N'){
            goto redel1;
        }
        printf("You sure?(The process of delete cannot be restore) Enter 'y' for yes and 'n' for no\n: ");
        fseek(stdin, 0, SEEK_END);//clean buffer
        char aaaa;
        scanf("%c" ,&aaaa);
        if (aaaa == 'n' || aaaa == 'N'){
            goto redel1;
        }


        //individual
        FILE *tlfr = fopen("deletelog.txt", "r");//test and check if theres a file
        if (tlfr == NULL) {
            FILE *fr = fopen("deletelog.txt", "a");
            fprintf(fr, "%i", 0);
            fclose(fr);
        }
        fclose(tlfr);
        int howmany;
        FILE *lfr = fopen("deletelog.txt", "r");
        fscanf(lfr,"%d", &howmany);
        FILE *nlfr = fopen("ndeletelog.txt", "a");
        fprintf(nlfr,"%d", howmany+1);
        char logstring[50];
        howmany = howmany + (howmany*10);
        fgets(logstring, 49, lfr);
        fprintf(nlfr,"\n", logstring);
        while(howmany!=0)
        {
            fgets(logstring, 49, lfr);
            fprintf(nlfr,"%s", logstring);

            howmany--;
        }

        fclose(lfr);

        time_t ltime = time(NULL);
        char *time_str = ctime(&ltime);
        time_str[strlen(time_str) - 1] = '\0';
        fprintf(nlfr, "\n%s\n%s%s%s%s%s%s%s%s%s", time_str, rec1[mnumber].recordnumber, rec1[mnumber].itemname,
                rec1[mnumber].itemnumber, rec1[mnumber].category, rec1[mnumber].quantity, rec1[mnumber].weight, rec1[mnumber].recipient,
                rec1[mnumber].final_destination,
                rec1[mnumber].status);
        fclose(nlfr);
        remove("deletelog.txt");
        rename("ndeletelog.txt","deletelog.txt");
        //end of individual part for delete




        //starting to delete
        FILE *nfr = fopen("ndata.txt", "a");

        i=0;
    	printf("%d", looooop);
        while(looooop > 0){
            if(i == mnumber){
                i++;
                looooop--;

            }else{
                fprintf(nfr, "\n%s%s%s%s%s%s%s%s%s", rec1[i].recordnumber, rec1[i].itemname,
                        rec1[i].itemnumber, rec1[i].category, rec1[i].quantity, rec1[i].weight, rec1[i].recipient,
                        rec1[i].final_destination,
                        rec1[i].status);
                i++;
                looooop--;
            }

        }
        fclose(nfr);
        fclose(fr);
        remove("stock.txt");
        rename("ndata.txt", "stock.txt");
        printf("\nRecord delete successfully...\n");
        printf("do u want to delete another record?");
        char yna; /* a stands for answer*/
        scanf(" %c", &yna);
        if (yna == 'n' || yna == 'N') {
            break;
        }
    }
    quit:
    printf("exiting delete....");
}


int htxt()
{
	remove("stock.txt");
	rename("nstock.txt","stock.txt");
	return 0;
}


void logs()
{
    struct Record {
        char time [40];
        char recordnumber[40];
        char itemnumber[40];
        char quantity[40];
        char weight[40];
        char itemname[40];
        char category[40];
        char recipient[40];
        char final_destination[40];
        char status[40];
        char buffer [40];
        char item[40];
    };
    int i ;
    int howmany;
    struct Record rec;
    while (1) {

        printf("\nWelcome to LOG\n");
        printf("\n1.View Add logs\n2.View Display all logs\n3.View Display 1by1 logs\n4.View Search logs\n5.View Modify logs\n6.View Delete logs\n7.View all logs\n");
        printf("\nPlease Enter which log you wanted to view, Enter 0 to exit View logs");
        int q;
        q = 0;
        char a;
        FILE *afr,*d1fr,*drfr,*sfr,*mfr,*dfr;
       
        scanf("%d", &q);
        switch (q) {
            case 1:
                printf("\nLoading Add logs...\n");
                afr = fopen("addlog.txt", "r");
                howmany = 0;
                fscanf(afr, "%d", &howmany);
                printf("Return with %d logs", howmany);
                fclose(afr);
                afr = fopen("addlog.txt", "r");
                fgets(rec.buffer, 40, afr);
                i=1;
                while (howmany!=0){
                    fgets(rec.buffer, 40, afr);
                    fgets(rec.time, 40, afr);
                    fgets(rec.recordnumber, 40, afr);
                    fgets(rec.itemname, 40, afr);
                    fgets(rec.itemnumber, 40, afr);
                    fgets(rec.category, 40, afr);
                    fgets(rec.quantity, 40, afr);
                    fgets(rec.weight, 40, afr);
                    fgets(rec.recipient, 40, afr);
                    fgets(rec.final_destination, 40, afr);
                    fgets(rec.status, 40, afr);
                    printf("\n\nThe %d log:",i);
                    printf("\nRecord added time: %sRecord number: %sItem Name: %sItem number: %sItem Category: %sItem quantity: %sItem weight: %sItem recipient: %sItem final destination: %sItem status: %s", rec.time, rec.recordnumber, rec.itemname, rec.itemnumber, rec.category, rec.quantity, rec.weight, rec.recipient, rec.final_destination, rec.status);


                    howmany--;
                    i++;
                }
                printf("\nThis is the end of Add file");
                printf("\nPlease enter 'k' to continue");
                scanf(" %c", &a);
                printf("\nReturning to log menu");
                fclose(afr);
                break;
            case 2:


                printf("\nLoading Display all logs...\n");
                d1fr = fopen("displayallog.txt", "r");
                howmany = 0;
                fscanf(d1fr, "%d", &howmany);
                printf("Return with %d logs", howmany);
                fclose(d1fr);
                d1fr = fopen("displayallog.txt", "r");
                fgets(rec.buffer, 40, d1fr);
                i=1;
                while (howmany!=0){
                    fgets(rec.buffer, 40, d1fr);
                    fgets(rec.time, 40, d1fr);

                    printf("\n\nThe %d log:",i);
                    printf("\nRecord been displayed all at time: %s", rec.time);


                    howmany--;
                    i++;
                }
                printf("\nThis is the end of Display all log file");
                printf("\nPlease enter 'k' to continue");
                scanf(" %c", &a);
                printf("\nReturning to log menu");
                fclose(d1fr);
                break;


            case 3:
               printf("\nLoading display 1 by 1 logs...\n");
                drfr = fopen("display1by1.txt", "r");
                howmany = 0;
                fscanf(drfr, "%d", &howmany);
                printf("Return with %d logs", howmany);
                fclose(drfr);
                drfr = fopen("display1by1.txt", "r");
                fgets(rec.buffer, 40, drfr);
                i=1;
                while (howmany!=0){
                    fgets(rec.buffer, 40, drfr);
                    fgets(rec.time, 40, drfr);
                    fgets(rec.recordnumber, 40, drfr);
                    fgets(rec.itemname, 40, drfr);
                    fgets(rec.itemnumber, 40, drfr);
                    fgets(rec.category, 40, drfr);
                    fgets(rec.quantity, 40, drfr);
                    fgets(rec.weight, 40, drfr);
                    fgets(rec.recipient, 40, drfr);
                    fgets(rec.final_destination, 40, drfr);
                    fgets(rec.status, 40, drfr);
                    printf("\n\nThe %d log:",i);
                    printf("\nRecord displayed time: %sRecord number: %sItem Name: %sItem number: %sItem Category: %sItem quantity: %sItem weight: %sItem recipient: %sItem final destination: %sItem status: %s", rec.time, rec.recordnumber, rec.itemname, rec.itemnumber, rec.category, rec.quantity, rec.weight, rec.recipient, rec.final_destination, rec.status);


                    howmany--;
                    i++;
                }
                
                
                fclose(drfr);
                printf("\nThis is the end of Display 1by1 file");
                printf("\nPlease enter 'k' to continue");
                scanf(" %c", &a);
                printf("\nReturning to log menu");
                

                break;
            case 4:
                printf("\nLoading Search logs...\n");
                sfr = fopen("searchlog.txt", "r");
                howmany = 0;
                fscanf(sfr, "%d", &howmany);
                printf("Return with %d logs", howmany);
                fclose(sfr);
                sfr = fopen("searchlog.txt", "r");
                fgets(rec.buffer, 40, sfr);
                i=1;
                while (howmany!=0){
                    fgets(rec.buffer, 40, sfr);
                    fgets(rec.time, 40, sfr);
                    fgets(rec.item, 40, sfr);

                    printf("\n\nThe %d log:",i);
                    printf("\nRecord been search at time: %s Searched Item: %s", rec.time, rec.item);


                    howmany--;
                    i++;
                }
                printf("\nThis is the end of Search log file");
                printf("\nPlease enter 'k' to continue");
                scanf(" %c", &a);
                printf("\nReturning to log menu");
                fclose(sfr);
                break;

            case 5:
                printf("\nLoading modify logs...\n");
                mfr = fopen("modifylog.txt", "r");
                howmany = 0;
                fscanf(mfr, "%d", &howmany);
                printf("Return with %d logs", howmany);
                fclose(mfr);
                mfr = fopen("modifylog.txt", "r");
                fgets(rec.buffer, 40, mfr);
                i=1;
                while (howmany!=0){
                    fgets(rec.buffer, 40, mfr);
                    fgets(rec.time, 40, mfr);
                    fgets(rec.recordnumber, 40, mfr);
                    fgets(rec.itemname, 40, mfr);
                    fgets(rec.itemnumber, 40, mfr);
                    fgets(rec.category, 40, mfr);
                    fgets(rec.quantity, 40, mfr);
                    fgets(rec.weight, 40, mfr);
                    fgets(rec.recipient, 40, mfr);
                    fgets(rec.final_destination, 40, mfr);
                    fgets(rec.status, 40, mfr);
                    printf("\n\nThe %d log:",i);
                    printf("\nRecord modified time: %s\nOriginal record: \nRecord number: %sItem name: %sItem number: %sItem Category: %sItem quantity: %sItem weight: %sItem recipient: %sItem final destination: %sItem status: %s", rec.time, rec.recordnumber, rec.itemname, rec.itemnumber, rec.category, rec.quantity, rec.weight, rec.recipient, rec.final_destination, rec.status);
                    fgets(rec.recordnumber, 40, mfr);
                    fgets(rec.itemname, 40, mfr);
                    fgets(rec.itemnumber, 40, mfr);
                    fgets(rec.category, 40, mfr);
                    fgets(rec.quantity, 40, mfr);
                    fgets(rec.weight, 40, mfr);
                    fgets(rec.recipient, 40, mfr);
                    fgets(rec.final_destination, 40, mfr);
                    fgets(rec.status, 40, mfr);
                    printf("\nAfter modify: \nRecord number: %sItem name: %sItem number: %sItem Category: %sItem quantity: %sItem weight: %sItem recipient: %sItem final destination: %sItem status: %s", rec.recordnumber, rec.itemname, rec.itemnumber, rec.category, rec.quantity, rec.weight, rec.recipient, rec.final_destination, rec.status);


                    howmany--;
                    i++;
                }
                printf("\nThis is the end of Modify log file");
                printf("\nPlease enter 'k' to continue");
                scanf(" %c", &a);
                printf("\nReturning to log menu");
                fclose(mfr);

                break;
            case 6:
                printf("\nLoading delete logs...\n");
                dfr = fopen("deletelog.txt", "r");
                howmany = 0;
                fscanf(dfr, "%d", &howmany);
                printf("Return with %d logs", howmany);
                fclose(dfr);
                dfr = fopen("deletelog.txt", "r");
                fgets(rec.buffer, 40, dfr);
                i=1;
                while (howmany!=0){
                    fgets(rec.buffer, 40, dfr);
                    fgets(rec.time, 40, dfr);
                    fgets(rec.recordnumber, 40, dfr);
                    fgets(rec.itemname, 40, dfr);
                    fgets(rec.itemnumber, 40, dfr);
                    fgets(rec.category, 40, dfr);
                    fgets(rec.quantity, 40, dfr);
                    fgets(rec.weight, 40, dfr);
                    fgets(rec.recipient, 40, dfr);
                    fgets(rec.final_destination, 40, dfr);
                    fgets(rec.status, 40, dfr);
                    printf("\n\nThe %d log:",i);
                    printf("\nRecord deleted time: %sRecord number: %sItem Name: %sItem number: %sItem Category: %sItem quantity: %sItem weight: %sItem recipient: %sItem final destination: %sItem status: %s", rec.time, rec.recordnumber, rec.itemname, rec.itemnumber, rec.category, rec.quantity, rec.weight, rec.recipient, rec.final_destination, rec.status);


                    howmany--;
                    i++;
                }
                printf("\nThis is the end of delete log file");
                printf("\nPlease enter 'k' to continue");
                scanf(" %c", &a);
                printf("\nReturning to log menu");
                fclose(dfr);

                break;
            case 7:
                printf("\nLoading All logs...\n");
                printf("\nAdd logs:\n");
                afr = fopen("addlog.txt", "r");
                howmany = 0;
                fscanf(afr, "%d", &howmany);
                printf("Return with %d logs", howmany);
                fclose(afr);
                afr = fopen("addlog.txt", "r");
                fgets(rec.buffer, 40, afr);
                i=1;
                while (howmany!=0){
                    fgets(rec.buffer, 40, afr);
                    fgets(rec.time, 40, afr);
                    fgets(rec.recordnumber, 40, afr);
                    fgets(rec.itemname, 40, afr);
                    fgets(rec.itemnumber, 40, afr);
                    fgets(rec.category, 40, afr);
                    fgets(rec.quantity, 40, afr);
                    fgets(rec.weight, 40, afr);
                    fgets(rec.recipient, 40, afr);
                    fgets(rec.final_destination, 40, afr);
                    fgets(rec.status, 40, afr);
                    printf("\n\nThe %d log:",i);
                    printf("\nRecord added time: %sRecord number: %sItem Name: %sItem number: %sItem Category: %sItem quantity: %sItem weight: %sItem recipient: %sItem final destination: %sItem status: %s", rec.time, rec.recordnumber, rec.itemname, rec.itemnumber, rec.category, rec.quantity, rec.weight, rec.recipient, rec.final_destination, rec.status);


                    howmany--;
                    i++;
                }
                printf("\nThis is the end of Add file");

                printf("\nLoading Display all logs...\n");
                printf("\nDisplay all logs:\n");
                d1fr = fopen("displayallog.txt", "r");
                howmany = 0;
                fscanf(d1fr, "%d", &howmany);
                printf("Return with %d logs", howmany);
                fclose(d1fr);
                d1fr = fopen("displayallog.txt", "r");
                fgets(rec.buffer, 40, d1fr);
                i=1;
                while (howmany!=0){
                    fgets(rec.buffer, 40, d1fr);
                    fgets(rec.time, 40, d1fr);

                    printf("\n\nThe %d log:",i);
                    printf("\nRecord been displayed all at time: %s", rec.time);


                    howmany--;
                    i++;
                }
                printf("\nThis is the end of Display all log file");
                fclose(d1fr);





                printf("\nLoading Display 1by1 logs...\n");
                printf("\nDisplay 1by1 logs:\n");
                drfr = fopen("display1by1.txt", "r");
                howmany = 0;
                fscanf(drfr, "%d", &howmany);
                printf("Return with %d logs", howmany);
                fclose(drfr);
                drfr = fopen("display1by1.txt", "r");
                fgets(rec.buffer, 40, drfr);
                i=1;
                while (howmany!=0){
                    fgets(rec.buffer, 40, drfr);
                    fgets(rec.time, 40, drfr);
                    fgets(rec.recordnumber, 40, drfr);
                    fgets(rec.itemname, 40, drfr);
                    fgets(rec.itemnumber, 40, drfr);
                    fgets(rec.category, 40, drfr);
                    fgets(rec.quantity, 40, drfr);
                    fgets(rec.weight, 40, drfr);
                    fgets(rec.recipient, 40, drfr);
                    fgets(rec.final_destination, 40, drfr);
                    fgets(rec.status, 40, drfr);
                    printf("\n\nThe %d log:",i);
                    printf("\nRecord displayed time: %sRecord number: %sItem Name: %sItem number: %sItem Category: %sItem quantity: %sItem weight: %sItem recipient: %sItem final destination: %sItem status: %s", rec.time, rec.recordnumber, rec.itemname, rec.itemnumber, rec.category, rec.quantity, rec.weight, rec.recipient, rec.final_destination, rec.status);


                    howmany--;
                    i++;
                }
                printf("\nThis is the end of Display 1by1 file");
                fclose(drfr);



                printf("\nLoading Search logs...\n");
                sfr = fopen("searchlog.txt", "r");
                printf("\nSearch logs:\n");
                howmany = 0;
                fscanf(sfr, "%d", &howmany);
                printf("Return with %d logs", howmany);
                fclose(sfr);
                sfr = fopen("searchlog.txt", "r");
                fgets(rec.buffer, 40, sfr);
                i=1;
                while (howmany!=0){
                    fgets(rec.buffer, 40, sfr);
                    fgets(rec.time, 40, sfr);
                    fgets(rec.item, 40, sfr);

                    printf("\n\nThe %d log:",i);
                    printf("\nRecord been search at time: %s Searched Item: %s", rec.time, rec.item);


                    howmany--;
                    i++;
                }
                printf("\nThis is the end of Search log file");
                fclose(sfr);
                printf("\nLoading modify logs...\n");
                mfr = fopen("modifylog.txt", "r");
                printf("\nmodify logs:\n");
                howmany = 0;
                fscanf(mfr, "%d", &howmany);
                printf("Return with %d logs", howmany);
                fclose(mfr);
                mfr = fopen("modifylog.txt", "r");
                fgets(rec.buffer, 40, mfr);
                i=1;
                while (howmany!=0){
                    fgets(rec.buffer, 40, mfr);
                    fgets(rec.time, 40, mfr);
                    fgets(rec.recordnumber, 40, mfr);
                    fgets(rec.itemname, 40, mfr);
                    fgets(rec.itemnumber, 40, mfr);
                    fgets(rec.category, 40, mfr);
                    fgets(rec.quantity, 40, mfr);
                    fgets(rec.weight, 40, mfr);
                    fgets(rec.recipient, 40, mfr);
                    fgets(rec.final_destination, 40, mfr);
                    fgets(rec.status, 40, mfr);
                    printf("\n\nThe %d log:",i);
                    printf("\nRecord modified time: %s\nOriginal record: \nRecord number: %sItem name: %sItem number: %sItem Category: %sItem quantity: %sItem weight: %sItem recipient: %sItem final destination: %sItem status: %s", rec.time, rec.recordnumber, rec.itemname, rec.itemnumber, rec.category, rec.quantity, rec.weight, rec.recipient, rec.final_destination, rec.status);
                    fgets(rec.recordnumber, 40, mfr);
                    fgets(rec.itemname, 40, mfr);
                    fgets(rec.itemnumber, 40, mfr);
                    fgets(rec.category, 40, mfr);
                    fgets(rec.quantity, 40, mfr);
                    fgets(rec.weight, 40, mfr);
                    fgets(rec.recipient, 40, mfr);
                    fgets(rec.final_destination, 40, mfr);
                    fgets(rec.status, 40, mfr);
                    printf("\nAfter modify: \nRecord number: %sItem name: %sItem number: %sItem Category: %sItem quantity: %sItem weight: %sItem recipient: %sItem final destination: %sItem status: %s", rec.recordnumber, rec.itemname, rec.itemnumber, rec.category, rec.quantity, rec.weight, rec.recipient, rec.final_destination, rec.status);


                    howmany--;
                    i++;
                }
                printf("\nThis is the end of Modify log file");
                fclose(mfr);

                printf("\nLoading delete logs...\n");
                dfr = fopen("deletelog.txt", "r");
                printf("\nDelete logs:\n");
                howmany = 0;
                fscanf(dfr, "%d", &howmany);
                printf("Return with %d logs", howmany);
                fclose(dfr);
                dfr = fopen("deletelog.txt", "r");
                fgets(rec.buffer, 40, dfr);
                i=1;
                while (howmany!=0){
                    fgets(rec.buffer, 40, dfr);
                    fgets(rec.time, 40, dfr);
                    fgets(rec.recordnumber, 40, dfr);
                    fgets(rec.itemname, 40, dfr);
                    fgets(rec.itemnumber, 40, dfr);
                    fgets(rec.category, 40, dfr);
                    fgets(rec.quantity, 40, dfr);
                    fgets(rec.weight, 40, dfr);
                    fgets(rec.recipient, 40, dfr);
                    fgets(rec.final_destination, 40, dfr);
                    fgets(rec.status, 40, dfr);
                    printf("\n\nThe %d log:",i);
                    printf("\nRecord deleted time: %sRecord number: %sItem Name: %sItem number: %sItem Category: %sItem quantity: %sItem weight: %sItem recipient: %sItem final destination: %sItem status: %s", rec.time, rec.recordnumber, rec.itemname, rec.itemnumber, rec.category, rec.quantity, rec.weight, rec.recipient, rec.final_destination, rec.status);


                    howmany--;
                    i++;
                }
                fclose(dfr);
                printf("\nThis is the end of delete log file");

                printf("\n\n\nThis is the end of all log file");

                printf("\nPlease enter 'k' to continue");
                scanf(" %c", &a);
                printf("\nReturning to log menu");

                break;


            case 0:
                break;
            default :
                printf("Invalid input, exiting view log....\n");
                break;
        }

        printf("Do you want to leave? Enter 'y' to exit log, enter 'n' to view other logs: ");
        fseek(stdin, 0, SEEK_END);//clean buffer
        fflush(stdin);
        char aa;
        scanf("%c", &aa);
        if (aa == 'y'||aa =='Y') {
            end:
            break;
        }

    }


}





//Pass value and
void run (int a)
{
    fseek(stdin, 0, SEEK_END);//clean buffer
    fflush(stdin);
    (a == 1) ? add() : (a == 2) ? Display() : (a == 3) ? search() : (a == 4) ? modify : (a == 5) ? delete():  (a == 6) ? logs() :quit();
}

int main () {
    while (1) {



		
        FILE *testf = fopen("stock.txt", "r");//create a file
        if(testf == NULL){
            printf("\n\n\nFile is missing or empty, please add a record before using other functions\n\n\n");
        }
        fclose(testf);

        printf("\n    *   Welcome to Inventory Management and Record System   *   \n"

               "--<BASIC function>--\n"
               "1. Add New Item<s>:\n"
               "2.Display Item Record<s>:\n"
               "3.Search Item Information:\n"
               "4.Modify Item Record<s>:\n"
               "5.Delete Item Record<s>:\n"
               "6.log<s>:\n"
               "*Enter 0 to quit*\n"
               "What is your option <1-5>?\n"
        );
        //select choice
        int q;
        q=0;
        scanf("%d", &q);
        if (q != 0) {
            run(q);
        }else{
            printf("exiting..... bye!");
            break;
        }
    }
    return 0;
}


