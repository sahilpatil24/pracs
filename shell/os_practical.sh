echo "creating folder OS Practical"
mkdir OS_Practical
cd OS_Practical

echo "Creating three files:"
touch file1.txt file2.txt file3.txt

echo "copying the file to another backup file"
cp file1.txt file1_backup.txt

echo "moving file2.txt to backup directory"
mkdir backup
mv file2.txt backup

echo "rename file3.txt to updated_fike3.txt"
mv file3.txt updated_fike3.txt

echo "deleting the backup directory"
rm -r backup