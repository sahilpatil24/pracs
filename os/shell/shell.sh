#!/bin/bash

echo "Creating the required files"
echo -e "Shreya\nGhoshal\nRakhi\nSawant\n" > file1.txt
echo -e "Atif\nAslam\nfile2\nArijit\nSingh"> file2.txt

echo "creating the combined file"
cat file1.txt file2.txt > combined.txt

echo "sorting the combined.txt"
sort combined.txt

echo "sorting in reverese order"
sort -r combined.txt

echo "remove the contents without deleting"
> file1.txt
> file2.txt
