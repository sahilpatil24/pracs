echo "Creating 2 employee files:\n"
echo -e "01\nAtif Aslam\n70000\nJunior Manager" > emp1.txt
echo -e "02\nArijit Singh\n92000\nSenior Manager" > emp2.txt

echo "joining two files in the 3rd file"
cat emp1.txt emp2.txt > thirdfile.txt
echo "displaying the concatenated file"
cat thirdfile.txt

echo "counting the contents of the file"
wc -l thirdfile.txt
wc -w thirdfile.txt
wc -c thirdfile.txt
