 *  Executing task: g++ -Wall -Wextra -g3 -I /home/hoangte/Documents/Code/ProJect/LibraryProject/** -finput-charset=UTF-8 -fexec-charset=UTF-8 /home/hoangte/Documents/Code/ProJect/LibraryProject/tests.cpp -o output/tests 

In file included from /home/hoangte/Documents/Code/ProJect/LibraryProject/tests.cpp:1:
/home/hoangte/Documents/Code/ProJect/LibraryProject/InputUtils.h: In function ‘char getch_custom()’:
/home/hoangte/Documents/Code/ProJect/LibraryProject/InputUtils.h:14:32: warning: missing initializer for member ‘termios::c_oflag’ [-Wmissing-field-initializers]
   14 |         struct termios old = {0};
      |                                ^
/home/hoangte/Documents/Code/ProJect/LibraryProject/InputUtils.h:14:32: warning: missing initializer for member ‘termios::c_cflag’ [-Wmissing-field-initializers]
/home/hoangte/Documents/Code/ProJect/LibraryProject/InputUtils.h:14:32: warning: missing initializer for member ‘termios::c_lflag’ [-Wmissing-field-initializers]
/home/hoangte/Documents/Code/ProJect/LibraryProject/InputUtils.h:14:32: warning: missing initializer for member ‘termios::c_line’ [-Wmissing-field-initializers]
/home/hoangte/Documents/Code/ProJect/LibraryProject/InputUtils.h:14:32: warning: missing initializer for member ‘termios::c_cc’ [-Wmissing-field-initializers]
/home/hoangte/Documents/Code/ProJect/LibraryProject/InputUtils.h:14:32: warning: missing initializer for member ‘termios::c_ispeed’ [-Wmissing-field-initializers]
/home/hoangte/Documents/Code/ProJect/LibraryProject/InputUtils.h:14:32: warning: missing initializer for member ‘termios::c_ospeed’ [-Wmissing-field-initializers]
/home/hoangte/Documents/Code/ProJect/LibraryProject/tests.cpp: At global scope:
/home/hoangte/Documents/Code/ProJect/LibraryProject/tests.cpp:15:6: error: redefinition of ‘char getch_custom()’
   15 | char getch_custom() {
      |      ^~~~~~~~~~~~
/home/hoangte/Documents/Code/ProJect/LibraryProject/InputUtils.h:12:10: note: ‘char getch_custom()’ previously defined here
   12 |     char getch_custom() {