#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <math.h>
#include <libxml/xmlschemastypes.h>

typedef struct {
    char name[21];
    char surname[31];
    char gender[2];//M or F
    char occupancy[31];
    char level_of_education[5];//PhD, MSc, BSc, HS, or PS
    char email[40];
    char bank_account_number[15];//split by - and combine them 123-4567890
    char IBAN[30];//TR12 3456 7890 1234 5678 90 donot take the first second digits and assign it to IBAN variable
    char account_type[15];//deposit, drawing, or daily_deposit
    char currency_unit[10];//€, ₺, or $
    char total_balance_available[8];//Displays the available balances of the customer in the bank account
    char available_for_loan[10];//May be one of the emojis: ☹😊
   
}Customer;

void readFileStoreInArray(FILE* fp, Customer* cu, int size){//The function to read file data and store to customers struct array

   if(!fp){//If there is an error occured while reading file
        printf("The file couldnot be finded!");
        exit(1);
    }

    memset(cu, 0, size);//To reset the array firstly

    char line[300];//store it in the line char array
    int rowCount = 0;//To hold the count of the lines
    int fieldCount = 0;//To hold the fields of the Csv File
    int i = 0;//For the index of cu array

    char firstLine[200];
    //To jump to the second line
    fgets(firstLine, 200, fp);

    while(fgets(line, 300, fp)){

        fieldCount = 0;//Reset the field number

        char* field = strtok(line,",");//seperate by commas   

        while(field) {  //'\000'

           
            if(fieldCount == 0 && strcmp(cu[i].name, "")==0){ //If the name attribute is not assigned
                char* comma_position = strchr(field, '\0'); //find the next location of the comma
                int length;
                if (comma_position != NULL) { //The comma is found
                length = comma_position - field; //The number of characters before the comma 
                } 
                strncpy(cu[i].name,field,length); //Assign the name 
                field = field + 1 + strlen(cu[i].name);
            }
            
            ///////////////////
            
            else if(fieldCount == 1 && strcmp(cu[i].surname, "")==0){ //If the surname attribute is not assigned
                char* comma_position = strchr(field, ','); //find the next location of the comma
                int length;
                if (comma_position != NULL) { //The comma is found
                length = comma_position - field; //The number of characters before the comma  
                } 
                strncpy(cu[i].surname,field,length); //Assign the surname
                field = field + 1 + strlen(cu[i].surname);

            }
            ///////////////////
            
            else if(fieldCount == 2 && (strncmp (field,",",1)==0)){//If the gender field is empty in the CSV file
                strcpy(cu[i].gender,"");
                field = field + 1;
            }

            else if(fieldCount == 2 && strcmp(cu[i].gender, "")==0){ //If the gender attribute is not assigned
                strncpy(cu[i].gender,field,1); //Assign the gender
                field = field + 2;
            }
                
            ///////////////////

            else if(fieldCount == 3 && (strncmp (field,",",1)==0)){//If the occupancy field is empty in the CSV file

                strcpy(cu[i].occupancy,"");
                field = field + 1;
            }

            else if(fieldCount == 3 && strcmp(cu[i].occupancy, "")==0){ //If the occupancy attribute is not assigned
                char* comma_position = strchr(field, ','); //find the next location of the comma
                int length;
                if (comma_position != NULL) { //The comma is found
                length = comma_position - field; //The number of characters before the comma  
                } 
                strncpy(cu[i].occupancy,field,length); //Assign the occupancy
                field = field +1 + strlen(cu[i].occupancy);
            }
                
            ///////////////////
          
            
            else if(fieldCount == 4 && (strncmp (field,",",1)==0)){//If the level_of_education field is empty in the CSV file

                strcpy(cu[i].level_of_education,"");
                field = field + 1;
            }

            else if(fieldCount == 4 && strcmp(cu[i].level_of_education, "")==0){ //If the level_of_education attribute is not assigned
                char* comma_position = strchr(field, ',');//find the next location of the comma
                int length;
                if (comma_position != NULL) { //The comma is found
                length = comma_position - field; //The number of characters before the comma  
                } 
                strncpy(cu[i].level_of_education,field,length); //Assign the level_of_education
                field = field + 1 + strlen(cu[i].level_of_education);
            }
                

            ///////////////////
         
            else if(fieldCount == 5 && (strncmp (field,",",1)==0)){//If the email field is empty in the CSV file

                strcpy(cu[i].email,"");
                field = field + 1;
            }

            else if(fieldCount == 5 && strcmp(cu[i].email, "")==0){ //If the email attribute is not assigned
                char* comma_position = strchr(field, ','); //find the next location of the comma
                int length;
                if (comma_position != NULL) { //The comma is found
                length = comma_position - field; //The number of characters before the comma   
                } 
                strncpy(cu[i].email,field,length); //Assign the email
                field = field + 1 + strlen(cu[i].email);
            }
                

            ///////////////////
      
            else if(fieldCount == 6 && (strncmp (field,",",1)==0)){//If the bank_account_number field is empty in the CSV file

                strcpy(cu[i].bank_account_number,"");
                field = field + 1;
            }

            else if(fieldCount == 6 && strcmp(cu[i].bank_account_number, "")==0){ //If the bank_account_number attribute is not assigned
                char* comma_position = strchr(field, ','); //find the next location of the comma
                int length;
                if (comma_position != NULL) { //The comma is found
                length = comma_position - field; //The number of characters before the comma   
                } 
                strncpy(cu[i].bank_account_number,field,length); //Assign the bank_account_number
                field = field + 1 + strlen(cu[i].bank_account_number);
            }
                


            ///////////////////
        
            else if(fieldCount == 7 && (strncmp (field,",",1)==0)){//If the IBAN field is empty in the CSV file

                strcpy(cu[i].IBAN,"");
                field = field + 1;
            }


            else if(fieldCount == 7 && strcmp(cu[i].IBAN, "")==0){ //If the IBAN attribute is not assigned
                char* comma_position = strchr(field, ','); //find the next location of the comma
                int length;
                if (comma_position != NULL) { //The comma is found
                length = comma_position - field; //The number of characters before the comma  
                } 
                strncpy(cu[i].IBAN,field,length); //Assign the IBAN
                field = field + 1 + strlen(cu[i].IBAN);
            }
                

            ///////////////////
          
            else if(fieldCount == 8 && (strncmp (field,",",1)==0)){//If the account_type field is empty in the CSV file

                strcpy(cu[i].account_type,"");
                field = field + 1;
            }

            else if(fieldCount == 8 && strcmp(cu[i].account_type, "")==0){ //If the account_type attribute is not assigned
                char* comma_position = strchr(field, ',');//find the next location of the comma
                int length;
                if (comma_position != NULL) { //The comma is found
                length = comma_position - field; //The number of characters before the comma   
                } 
                strncpy(cu[i].account_type,field,length); //Assign the account_type
                field = field + 1 + strlen(cu[i].account_type);
            }
                

            ///////////////////
         
            else if(fieldCount == 9 && (strncmp (field,",",1)==0)){//If the currency_unit field is empty in the CSV file

                strcpy(cu[i].currency_unit,"");
                field = field + 1;
            }


            else if(fieldCount == 9 && strcmp(cu[i].currency_unit, "")==0){ //If the currency_unit attribute is not assigned
                char* comma_position = strchr(field, ','); //find the next location of the comma
                int length;
                if (comma_position != NULL) { //The comma is found
                length = comma_position - field; //The number of characters before the comma 
                } 
                strncpy(cu[i].currency_unit,field,length); //Assign the currency_unit
                field = field + 1 + strlen(cu[i].currency_unit);
            }
                

            ///////////////////
         
            else if(fieldCount == 10 && (strncmp (field,",",1)==0)){//If the total_balance_available field is empty in the CSV file

                strcpy(cu[i].total_balance_available,"");
                field = field + 1;
            }

            else if(fieldCount == 10 && strcmp(cu[i].total_balance_available, "")==0){ //If the total_balance_available attribute is not assigned
                char* comma_position = strchr(field, ','); //find the next location of the comma
                int length;
                if (comma_position != NULL) { //The comma is found
                length = comma_position - field; //The number of characters before the comma  
                } 
                strncpy(cu[i].total_balance_available,field,length); //Assign the total_balance_available
                field = field + 1 + strlen(cu[i].total_balance_available);
            }
                

            ///////////////////
            
            else if(fieldCount == 11 && (strncmp (field,",",1)==0)){//If there is no emoji in the CSV file and the last character is ','

                strcpy(cu[i].available_for_loan,"");
                field = field + 1;
            }
       
            else if(fieldCount == 11 && strcmp(cu[i].available_for_loan, "")==0){ //If the available_for_loan attribute is not assigned
                char* comma_position = strchr(field, '\n'); //find the next location of the comma
                int length;
                if (comma_position != NULL) { //The comma is found
                length = comma_position - field; //The number of characters before the comma   
                } 
                 strncpy(cu[i].available_for_loan,field,length); //Assign the available_for_loan
                 field = field + 1 + strlen(cu[i].available_for_loan);
            }
           
            fieldCount++;//Update the field value
            if(fieldCount==12)//If we reach to end of the line
                break;//Go to the next line

        }
        memset(line,'\000' , sizeof(line));//Reset the line array 
        i++;
    }
}

void printValues(Customer* c,int number){ //The function to print the elements of the customers struct array
    for(int i = 0; i < number; i++){
        printf("%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n\n",
                    c[i].name,
                    c[i].surname,
                    c[i].gender,
                    c[i].occupancy,
                    c[i].level_of_education,
                    c[i].email,
                    c[i].bank_account_number,
                    c[i].IBAN,
                    c[i].account_type,
                    c[i].currency_unit,
                    c[i].total_balance_available,
                    c[i].available_for_loan);
    }
}

bool writeToBinaryFile(FILE *fpb,Customer *data,int total){ //The function to create a binary file

    if(fpb==NULL) //If an error occured while opening the binary file
        return false;

    if (fwrite(data,sizeof(Customer),total,fpb) != total) //If fwrite doesnt return the total number of elements in the customers array
        return false;


}

Customer *readFromBinaryFile(char* fileName,int *tp){ //The function that returns the pointer of the array

    FILE *fpbr= fopen(fileName,"rb");//Open the file

    if(fpbr==NULL) return NULL; // If there is a problem return NULL
  
    Customer cus;
    Customer *cp=&cus;

    while(fread(cp,sizeof(Customer),1,fpbr) != 0){ //There is no problem while reading the struct
        *tp=*tp+1;
    }

    Customer* data=(Customer*)malloc(*tp*sizeof(Customer)); //Allocate memory for the number of structs

    fseek(fpbr, 0, SEEK_SET); //put the file pointer to the beginning of the file

    if(fread(data,sizeof(Customer),*tp,fpbr) != *tp){ //If there is a problem reading whole structs
         free(data); //Free the allocated space in memory
         return NULL;
    }

    if (fclose(fpbr)==EOF){ //If there is a problem occured while closing the file
            free(data); //Free the allocated space in memory
            return NULL;
    }

    return data;

}

unsigned int littleToBigEnd(int n) { //The function that converts the little endion version of the number to the big endion

int numArr[32],i,tempB[32];      

memset(numArr,0,sizeof(numArr));//filling the array with zeros
memset(tempB,0,sizeof(tempB));//filling the array with zeros
int count = 0; 

for(i=31;n>0;i--)    
{   
    numArr[i]=n % 2;    
    n=n/2; 
    count++;//counting how many digits the number has 
}  

memset(tempB,0,sizeof(tempB));//filling the array with zeros

for(int i = 0; i < 32; i++){
    tempB[i] = numArr[i]; //filling temp array with num array values 
}

memset(numArr,0,sizeof(numArr));
//divide the b array into eight parts and converison to big endian version
int count1 = 0;
for(int i = 31; i >= 0; i = i - 8){ //filling the array with 8 bit parts from end to beginning
    i = i - 8;
    for(int j = 0; j < 8; j++){
        numArr[count1] = tempB[i + 1];
        i++;
        count1++;
    }

} 
int valueOfDigits = 31; //To multiply the binary digits with their digit values
unsigned int result = 0;

//converting binary to decimal
for(int m = 0; m<32; m++){
    result += pow(2, valueOfDigits) * numArr[m];
    valueOfDigits--;
}

return result;

}

void createXML(Customer *binaryData,int *tp){ //The function that creates Xml file 

    xmlDocPtr doc = NULL;       /* document pointer */ //For the tree
    xmlNodePtr root_node = NULL, node = NULL, node1 = NULL,node2 = NULL,node3 = NULL;  /* node pointers */

    doc = xmlNewDoc(BAD_CAST "1.0"); //To create the tree
    root_node = xmlNewNode(NULL, BAD_CAST "records"); //Implement the root node
    xmlDocSetRootElement(doc, root_node); //Lİnk the rootnode to the tree

    for(int i=1;i<*tp+1;i++){

    char str[128];
    sprintf(str, "%d", i); // integer to string

    int totalba;
    sscanf(binaryData[i-1].total_balance_available, "%d", &totalba); //String to int

    unsigned int result=littleToBigEnd(totalba);
    char number[256];
    sprintf(number, "%u",result); //unsigned int to String

    node=xmlNewChild(root_node, NULL, BAD_CAST "row", NULL); //implement the row elements 
    xmlNewProp(node, BAD_CAST "id", BAD_CAST str); // implement the id attribute of the row

    node1=xmlNewChild(node, NULL, BAD_CAST "customer_info", NULL); //The first child of the row CUSTOMER INFO

    xmlNewChild(node1, NULL, BAD_CAST "name",BAD_CAST binaryData[i-1].name); //The child of the CUSTOMER INFO
    xmlNewChild(node1, NULL, BAD_CAST "surname", BAD_CAST binaryData[i-1].surname); //The child of the CUSTOMER INFO
    xmlNewChild(node1, NULL, BAD_CAST "gender", BAD_CAST binaryData[i-1].gender); //The child of the CUSTOMER INFO
    xmlNewChild(node1, NULL, BAD_CAST "occupancy", BAD_CAST binaryData[i-1].occupancy); //The child of the CUSTOMER INFO
    xmlNewChild(node1, NULL, BAD_CAST "level_of_education", BAD_CAST binaryData[i-1].level_of_education); //The child of the CUSTOMER INFO
    xmlNewChild(node1, NULL, BAD_CAST "email", BAD_CAST binaryData[i-1].email); //The child of the CUSTOMER INFO


    node2=xmlNewChild(node, NULL, BAD_CAST "bank_account_info", NULL); //The second child of the row BANK ACCOUNT INFO

    xmlNewChild(node2, NULL, BAD_CAST "bank_account_number", BAD_CAST binaryData[i-1].bank_account_number); //The child of the BANK ACCOUNT INFO
    xmlNewChild(node2, NULL, BAD_CAST "IBAN", BAD_CAST binaryData[i-1].IBAN); //The child of the BANK ACCOUNT INFO
    xmlNewChild(node2, NULL, BAD_CAST "account_type", BAD_CAST binaryData[i-1].account_type); //The child of the BANK ACCOUNT INFO
    node3=xmlNewChild(node2, NULL, BAD_CAST "total_balance_available", BAD_CAST binaryData[i-1].total_balance_available); //The child of the BANK ACCOUNT INFO
    xmlNewChild(node2, NULL, BAD_CAST "available_for_loan", BAD_CAST binaryData[i-1].available_for_loan); //The child of the BANK ACCOUNT INFO

    xmlNewProp(node3, BAD_CAST "currency_unit", BAD_CAST binaryData[i-1].currency_unit); // implement the currency_unit attribute of the total_balance_available
    xmlNewProp(node3, BAD_CAST "bigEnd_Version", BAD_CAST number); // implement the bigEnd_Version attribute of the total_balance_available


    }

    xmlSaveFormatFileEnc("records.xml", doc, "UTF-8", 1);
    xmlFreeDoc(doc);


}

void xsdValidation(){//XML validation with XSD
    xmlDocPtr doc;
    xmlSchemaPtr schema = NULL;
    xmlSchemaParserCtxtPtr ctxt;
	
    char *XMLFileName = "records.xml"; // write your xml file here
    char *XSDFileName = "2020510017_2020510085.xsd"; // write your xsd file here
    
    
    xmlLineNumbersDefault(1); //set line numbers, 0> no substitution, 1>substitution
    ctxt = xmlSchemaNewParserCtxt(XSDFileName); //create an xml schemas parse context
    schema = xmlSchemaParse(ctxt); //parse a schema definition resource and build an internal XML schema
    xmlSchemaFreeParserCtxt(ctxt); //free the resources associated to the schema parser context
    
    doc = xmlReadFile(XMLFileName, NULL, 0); //parse an XML file
    if (doc == NULL)
    {
        fprintf(stderr, "Could not parse %s\n", XMLFileName);
    }
    else
    {
        xmlSchemaValidCtxtPtr ctxt;  //structure xmlSchemaValidCtxt, not public by API
        int ret;
        
        ctxt = xmlSchemaNewValidCtxt(schema); //create an xml schemas validation context 
        ret = xmlSchemaValidateDoc(ctxt, doc); //validate a document tree in memory
        if (ret == 0) //validated
        {
            printf("%s validates\n", XMLFileName);
        }
        else if (ret > 0) //positive error code number
        {
            printf("%s fails to validate\n", XMLFileName);
        }
        else //internal or API error
        {
            printf("%s validation generated an internal error\n", XMLFileName);
        }
        xmlSchemaFreeValidCtxt(ctxt); //free the resources associated to the schema validation context
        xmlFreeDoc(doc);
    }
    // free the resource
    if(schema != NULL)
        xmlSchemaFree(schema); //deallocate a schema structure

    xmlSchemaCleanupTypes(); //cleanup the default xml schemas types library
    xmlCleanupParser(); //cleans memory allocated by the library itself 
    xmlMemoryDump(); //memory dump
    printf("success");
}

int main(int argc, char *argv[]){
    
 
    //READING THE CSV FILE AND STORING DATA IN IT TO THE ARRAY OF STRUCT
    FILE* fp = fopen("records.csv", "r"); //Open the file

    Customer customers[50];//array to structs to store values

    int cusSize = sizeof(customers); //The size of the array

    Customer *binaryData;

    int total=0; //To count the number of structs in the binary file
    int *tp=&total;
    if(strcmp(argv[0], "./myConverter") == 0 && strcmp(argv[1], "records.csv") == 0 && strcmp(argv[2], "records.dat") == 0 && strcmp(argv[3], "1") == 0){
        readFileStoreInArray(fp, customers, cusSize); //Store the file data to the struct array "customers"

        /////////////////////////////////////////////////////////////
        //WRITING THE ARRAY OF STRUCT TO THE BINARY FILE
        FILE *fpb= fopen("records.dat","wb");

        if(writeToBinaryFile(fpb,customers,50))
            printf("Writing data to the binary file is successful.\n");
        else{
            printf("Error writing to the file.\n");
            return 1;
        }

        fclose(fpb);
        
     
    }
    fclose(fp); //close the file

    
    
   // printValues(customers,50); //Print the values of customers array

    //printValues(binaryData,total);


    //////////////////////////////////////////////////////////////
    //CREATING XML FILE
    if(strcmp(argv[0], "./myConverter") == 0 && strcmp(argv[1], "records.dat") == 0 && strcmp(argv[2], "records.xml") == 0 && strcmp(argv[3], "2") == 0){//myConverter records.dat records.xml 2
       
        //////////////////////////////////////////////////////////////
        //READING DATA FROM BINARY FILE AND WRITING TO ARRAY OF STRUCT

        binaryData=readFromBinaryFile("records.dat",tp);

        if(binaryData==NULL){ //If there is a problem occured while reading binary file
            printf("Error reading file!\n");
            return 1;
        }

        printf("Data read successfully from binary file.\n");
        createXML(binaryData,tp);
        printf("XML file has created.");
        
    

    }
    //////////////////////////////////////////////////////////////
    //XML VALIDATION WITH XSD
    if(strcmp(argv[0], "./myConverter") == 0 && strcmp(argv[1], "records.xml") == 0 && strcmp(argv[2], "records.xsd") == 0 && strcmp(argv[3], "3") == 0){//myConverter records.xml recors.xsd 3
      
        xsdValidation();
    }





    return 0;
}
