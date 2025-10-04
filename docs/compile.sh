raco pollen render info.html.pmd
raco pollen reset
cat start.txt > index.html
echo -e '\n' >> index.html
cat info.html >> index.html
echo -e '\n' >> index.html
cat footer.txt >> index.html
raco pollen start