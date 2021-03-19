# Count Ascii Characters In Files
Counts ASCII charactes in given .txt file. Uploading it mainly as a buckup. 

### What it does:
 
Currently there are 2 files: 

•	**basic.cpp** – provides basic ascii symbol count and prints statistics. Does **not** differentiates between same symbols occurring _n_ times in a row (e.g. “FF F FF” = 5x ‘F’ & 2x ‘ ‘).  

•	**TextStats2.cpp** – provides ascii symbol count, optionally prints statistics & saves to file. Does differentiates between same symbols occurring _n_ times in a row (e.g.   “FF F FF” = 3x ‘F’ & 2x ‘ ‘). Command line arguments are available: 

     ./TextStats2.exe [p] <file_to_read_from> <file_to_save_output>
  
  **p** stands for 'print' (in reality u can put any string there, as long as there will be argument – I’ll fix it later [maybe]).   
  
  ---
 
### Example:
  
  ###### Warning! Some symbols like spaces, tabs, new_line etc. are replaced in saved file by thier abbreviations; e.g. space - SP, Tab - TB... In the console output, however, they are not replaced (I might change it later). 
  
  Sample input: 
  
               The quick brown fox jumps over the lazy dog 1234 56789 99 ()[];'<>?!@#$%^&*
   
  
  Sample output: (output scheme as follows: <hex_symbol_code>,<symbol>,<repetitions>:<occurances>) 
               
               0x53,SP,1:12
               0x21,!,1:1
               0x23,#,1:1
               0x24,$,1:1
               0x25,%,1:1
               0x26,&,1:1
               0x27,',1:1
               0x28,(,1:1
               0x29,),1:1
               0x2A,*,1:1
               0x31,1,1:1
               0x32,2,1:1
               0x33,3,1:1
               0x34,4,1:1
               0x35,5,1:1
               0x36,6,1:1
               0x37,7,1:1
               0x38,8,1:1
               0x39,9,2:2
               0x3B,;,1:1
               0x3C,<,1:1
               0x3E,>,1:1
               0x3F,?,1:1
               0x40,@,1:1
               0x54,T,1:1
               0x5B,[,1:1
               0x5D,],1:1
               0x5E,^,1:1
               0x61,a,1:1
               0x62,b,1:1
               0x63,c,1:1
               0x64,d,1:1
               0x65,e,1:3
               0x66,f,1:1
               0x67,g,1:1
               0x68,h,1:2
               0x69,i,1:1
               0x6A,j,1:1
               0x6B,k,1:1
               0x6C,l,1:1
               0x6D,m,1:1
               0x6E,n,1:1
               0x6F,o,1:4
               0x70,p,1:1
               0x71,q,1:1
               0x72,r,1:2
               0x73,s,1:1
               0x74,t,1:1
               0x75,u,1:2
               0x76,v,1:1
               0x77,w,1:1
               0x78,x,1:1
               0x79,y,1:1
               0x7A,z,1:1

Console output with 'p' argument:

          File opened successfully!
          ' ' occured 12 times.
          '!' occured 1 time.
          '#' occured 1 time.
          '$' occured 1 time.
          '%' occured 1 time.
          '&' occured 1 time.
          ''' occured 1 time.
          '(' occured 1 time.
          ')' occured 1 time.
          '*' occured 1 time.
          '1' occured 1 time.
          '2' occured 1 time.
          '3' occured 1 time.
          '4' occured 1 time.
          '5' occured 1 time.
          '6' occured 1 time.
          '7' occured 1 time.
          '8' occured 1 time.
          '9' occured 2 times.
          ';' occured 1 time.
          '<' occured 1 time.
          '>' occured 1 time.
          '?' occured 1 time.
          '@' occured 1 time.
          'T' occured 1 time.
          '[' occured 1 time.
          ']' occured 1 time.
          '^' occured 1 time.
          'a' occured 1 time.
          'b' occured 1 time.
          'c' occured 1 time.
          'd' occured 1 time.
          'e' occured 3 times.
          'f' occured 1 time.
          'g' occured 1 time.
          'h' occured 2 times.
          'i' occured 1 time.
          'j' occured 1 time.
          'k' occured 1 time.
          'l' occured 1 time.
          'm' occured 1 time.
          'n' occured 1 time.
          'o' occured 4 times.
          'p' occured 1 time.
          'q' occured 1 time.
          'r' occured 2 times.
          's' occured 1 time.
          't' occured 1 time.
          'u' occured 2 times.
          'v' occured 1 time.
          'w' occured 1 time.
          'x' occured 1 time.
          'y' occured 1 time.
          'z' occured 1 time.
          Successfully saved to: output.csv!

---


