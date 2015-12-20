# cctype

## 1 Character classification functions

### 1.1 isalnum

**Check if character is alphanumeric**

Checks whether c is either a decimal digit or an uppercase or lowercase letter.

### 1.2 isalpha

**Check if character is alphabetic**

Checks whether c is an alphabetic letter.

### 1.3 isblank

**Check if character is blank**

Checks whether c is a blank character.

A blank character is a space character used to separate words within a line of text.

The standard "C" locale considers blank characters the tab character ('\t') and the space character (' ').

### 1.4 iscntrl

**Check if character is a control character**

Checks whether c is a control character.

A control character is a character that does not occupy a printing position on a display (this is the opposite of a printable character, checked with isprint).

For the standard ASCII character set (used by the "C" locale), control characters are those between ASCII codes 0x00 (NUL) and 0x1f (US), plus 0x7f (DEL).

### 1.5 isdigit

**Check if character is decimal digit**

Checks whether c is a decimal digit character.

Decimal digits are any of: 0 1 2 3 4 5 6 7 8 9 

### 1.6 isgraph

**Check if character has graphical representation**

Checks whether c is a character with graphical representation.

The characters with graphical representation are all those characters than can be printed (as determined by isprint) except the space character (' ').

### 1.7 islower

**Check if character is lowercase letter**

Checks whether c is a lowercase letter.

Notice that what is considered a letter may depend on the locale being used; In the default "C" locale, a lowercase letter is any of: a b c d e f g h i j k l m n o p q r s t u v w x y z.

### 1.8 isprint

**Check if character is printable**

Checks whether c is a printable character.

A printable character is a character that occupies a printing position on a display (this is the opposite of a control character, checked with iscntrl).

For the standard ASCII character set (used by the "C" locale), printing characters are all with an ASCII code greater than 0x1f (US), except 0x7f (DEL).

### 1.9 ispunct

**Check if character is a punctuation character**

Checks whether c is a punctuation character.

### 1.10 isspace

**Check if character is a white-space**

Checks whether c is a white-space character.

For the "C" locale, white-space characters are any of:

![image](https://cloud.githubusercontent.com/assets/7693440/11917037/1b00459e-a731-11e5-9eb4-1ead8e55917e.png)

### 1.11 isupper

**Check if character is uppercase letter**

Checks if parameter c is an uppercase alphabetic letter.

Notice that what is considered a letter may depend on the locale being used; In the default "C" locale, an uppercase letter is any of: A B C D E F G H I J K L M N O P Q R S T U V W X Y Z.

### 1.12 isxdigit

**Check if character is hexadecimal digit**

Checks whether c is a hexdecimal digit character.

Hexadecimal digits are any of: 0 1 2 3 4 5 6 7 8 9 a b c d e f A B C D E F 

## 2 Character conversion functions

### 2.1 tolower

**Convert uppercase letter to lowercase**

Converts c to its lowercase equivalent if c is an uppercase letter and has a lowercase equivalent. If no such conversion is possible, the value returned is c unchanged.

Notice that what is considered a letter may depend on the locale being used; In the default "C" locale, an uppercase letter is any of: A B C D E F G H I J K L M N O P Q R S T U V W X Y Z, which translate respectively to: a b c d e f g h i j k l m n o p q r s t u v w x y z.

### 2.2 toupper

**Convert lowercase letter to uppercase**

Converts c to its uppercase equivalent if c is a lowercase letter and has an uppercase equivalent. If no such conversion is possible, the value returned is c unchanged.

Notice that what is considered a letter may depend on the locale being used; In the default "C" locale, a lowercase letter is any of: a b c d e f g h i j k l m n o p q r s t u v w x y z, which translate respectively to: A B C D E F G H I J K L M N O P Q R S T U V W X Y Z.