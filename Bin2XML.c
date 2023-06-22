#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct record
{
    char name[64];    // utf16
    char surname[32]; // utf8
    char gender;
    char email[32];
    char phone_number[16];
    char address[32];
    char level_of_education[8];
    unsigned int income_level; // given little-endian
    unsigned int expenditure;  // given big-endian
    char currency_unit[16];
    char currentMood[32];
    float height;
    unsigned int weight;
};
int read_file(char *fileName, char *createFileName)
{
    int n;
    struct record rd;
    FILE *fptr;
    FILE *fptr2;

    fptr2 = fopen(createFileName, "w+");        // open xml file
    if ((fptr = fopen(fileName, "rb")) == NULL) // open dat file with error control
    {
        printf("Error! opening file");
        // Program exits if the file pointer returns NULL.
        exit(1);
    }

    fprintf(fptr2, "<records>");
    for (n = 1; n < 52; ++n) // read and write to xml
    {

        fread(&rd, sizeof(struct record), 1, fptr);

        if (n > 1)
        {
            fprintf(fptr2, "\n\t<row id = \"\%d\" >\n\t\t<name>%s</name>\n\t\t<surname>%s</surname>\
        \n\t\t<email>%s</email>\n\t\t<phone_number>%s</phone_number>\n\t\t<address>%s</address>\
        \n\t\t<level_of_education>%s</level_of_education>\n\t\t<currency_unit>%s</currency_unit>\
        \n\t\t<currentMood>%s</currentMood>\n\t</row>",
                    n - 1, rd.name, rd.surname, rd.email, rd.phone_number, rd.address, rd.level_of_education, rd.currency_unit, rd.currentMood);
        }
    }
    fprintf(fptr2, "</records>");
    fclose(fptr);
    fclose(fptr2);

    return 0;
}
int main(int argc, char *argv[])
{
    // if the file name to be created and the file name read is missing, an error code will be given
    if (argc > 2)
    {
        if (strcmp(argv[0], "./CHomework") != 0)
        {
            printf("Please enter correctly.\nExample input : ./CHomework records.dat test.xml\n");
        }
        else
        {
            char *fileName = argv[1];
            char *createFileName = argv[2];
            read_file(fileName, createFileName);
        }
    }
    if (argc < 3)
        printf("Please enter correctly.\nExample input : ./CHomework records.dat test.xml\n");
    return 0;
}