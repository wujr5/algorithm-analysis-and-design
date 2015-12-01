#include<iostream>
#include<cstring>
using namespace std;

struct {
  char name[40];
  int age;
} person, person_copy;

int main() {
	cout << "---- learning cstring ----" << endl;
	
	cout << "copying:" << endl;
	
	cout << "1. memcpy" << endl;
	char myname[] = "Pierre de Fermat";
	/* using memcpy to copy string: */
	memcpy (person.name, myname, strlen(myname)+1);
	person.age = 46;
	/* using memcpy to copy structure: */
	memcpy (&person_copy, &person, sizeof(person));
	
	cout << "2. memmove" << endl;
	char str[] = "memmove can be very useful......";
  	memmove (str+20, str+15, 11);
  	
  	cout << "3. strcpy" << endl;
  	char str1[]="Sample string";
	char str2[40];
	char str3[40];
	strcpy (str2,str1);
	strcpy (str3,"copy successful");

	cout << "4. strncpy" << endl;
	strncpy ( str2, str1, sizeof(str2));
	strncpy ( str3, str2, 5 );
  	str3[5] = '\0';   /* null character manually added */

	cout << endl;
  	cout << "Concatenation:" << endl;
  	
  	cout << "1. strcat" << endl;
  	strcpy (str,"these ");
	strcat (str,"strings ");
	strcat (str,"are ");
	strcat (str,"concatenated.");
	
	cout << "2. strncat" << endl;
	strcpy (str1,"To be ");
	strcpy (str2,"or not to be");
	strncat (str1, str2, 6);
	
	cout << "Comparison:" << endl;
	
	cout << "1. memcmp" << endl;
	char buffer1[] = "DWgaOtP12df0";
	char buffer2[] = "DWGAOTP12DF0";
	int n;
	n=memcmp ( buffer1, buffer2, sizeof(buffer1) );
	if (n>0) printf ("'%s' is greater than '%s'.\n",buffer1,buffer2);
	else if (n<0) printf ("'%s' is less than '%s'.\n",buffer1,buffer2);
	else printf ("'%s' is the same as '%s'.\n",buffer1,buffer2);
	
	cout << "2. strcmp" << end;
	char key[] = "apple";
	char buffer[80];
	do {
	 printf ("Guess my favorite fruit? ");
	 fflush (stdout);
	 scanf ("%79s",buffer);
	} while (strcmp (key,buffer) != 0);
	
	
}
