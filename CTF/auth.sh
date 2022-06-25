# cat ./abc.txt | while read line
# do
#     # echo $line
#     abc = `curl -u admin:admin http://challenge-ef2976bbda71f064.sandbox.ctfhub.com:10800/flag.html`
#     echo abc
# done
abc=`curl -u admin:admin http://challenge-ef2976bbda71f064.sandbox.ctfhub.com:10800/flag.html`
echo $abc