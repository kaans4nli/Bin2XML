# Bin2XML
# Implementation Details & Requirements
Binary file ('personList.dat') consists of some information about the employees of a company. Each record has the following attributes and their sizes are given below:

![image](https://github.com/kaans4nli/Bin2XML/assets/107371841/977ad386-2051-49aa-8c26-cd7d1381e83f)

For each person that was read from the file, a row number is assigned as the "id" attribute starting from 1 and its value is increased by 1. The element names of "row" in the XML file are found at the beginning of the "personList.dat" file.

The field "surname" read in UTF-8 format whereas the field "name" read in UTF-16 format.

The field "expenditure" read in the Big Endian format whereas the field "income_level" read in the Little Endian format. 

# Usage of Bin2XML 
'Bin2XML < inputfile > < outputfile >'.
  
  The first argument, < inputfile > refers to the source filename to be used for the conversion and the second one, < outputfile >, refers to the target XML filename.
  
  The sample command line usage converting from the binary file to XML as 'Bin2XML personList.dat personList.xml'.
  
The program Create an XSD file that will be used to validate XML file. XSD file include all necessary properties including patterns and restrictions. After the creation of the XML and XSD files, program automatically validate the XML file using the XSD file and return the result of validation by printing "Validation Completed." or "Validation Error."
