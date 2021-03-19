# Count Ascii Characters In Files
Counts ASCII charactes in given .txt file. Uploading it mainly as a buckup. 

Currently there are 2 files: 

•	**basic.cpp** – provides basic ascii symbol count and prints statistics. Does not differentiates between same symbols occurring _n_ times in a row (e.g. “FF F FF” = 5x ‘F’ & 2x ‘ ‘).  

•	**TextStats2.cpp** – provides ascii symbol count, optionally prints statistics & saves to file. Does differentiates between same symbols occurring _n_ times in a row (e.g.   “FF F FF” = 3x ‘F’ & 2x ‘ ‘). Command line arguments are available: 
  TextStats2.exe [p] <file_to_read_from> <file_to_save_output>. 
  **p** stands for 'print' (in reality u can put any string there, as long as there will be argument – I’ll fix it later [maybe]).   
  
  ---


