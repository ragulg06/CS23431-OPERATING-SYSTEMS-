echo "Enter the numer of terms"
rean n

a=0
b=0

echo "Fibonacci series:"

for((i=0;i<n;i++))
do 
    echo -n "$a "
    fn = $((a+b))
    a = $b
    b = $fn

done
echo