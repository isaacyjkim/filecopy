# filecopy  
A C program that copies the contents of one file to another using two processes and one pipe. 


## Compilation 
You will need 'gcc' installed. To compile make sure you are in the same directory where filecopy.c is located and run: 

```
gcc filecopy.c -o filecopy
```

Once you run this, it will create an executable called 'filecopy' in your current directory. 

## Running the code 
Once compiled you can run the program using: 
```
./filecopy 'source' 'destination' 
```
- 'source' is the path of the file you want to copy (it will cause an error is it doesn't exist)  
- 'desination' is the path of the file you want to copy into (it will be created if it doesn't exist) 

## Testing Examples

```
./filecopy input.txt output.txt
```

The output for this should be 
```
File sucessfully copied from input.txt to output.txt
```

### Error cases
```
./filecopy input.txt input.txt output.txt
```
Output: 'Only 2 arguments allowed. source - destination' 

```
./filecopy non_existing_file.txt output.txt 
```
Output: 'Error: Unable to open source file 'non_existing_file.txt'.'


