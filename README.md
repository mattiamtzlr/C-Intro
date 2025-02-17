# C-Intro
An introduction to the C programming language following [Beej's Guide to C Programming](https://beej.us/guide/bgc/).  

A direct link to the tutorial part of the HTML guide is [here](https://beej.us/guide/bgc/html/split-wide/index.html).  
A direct link to the reference part of the HTML guide is [here](https://beej.us/guide/bgclr/html/split/).

## Usage
To compile and run any of the files in the `src` directory run:
```bash
make run FILE=xx_folder/filename
```
while in the root directory. You don't need to specify the file extension. The compiled binary will be in `out/xx_folder`.  
So for example:
```bash
make run FILE=03_variables_statements/operators
```
to compile and run `./src/03_variables_statements/operators.c`.
